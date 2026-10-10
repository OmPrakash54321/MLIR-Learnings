#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Dialect/Tensor/IR/Tensor.h"
#include "mlir/Dialect/Vector/IR/VectorOps.h"
#include "mlir/Dialect/MemRef/IR/MemRef.h"

#include "mlir/Conversion/LLVMCommon/TypeConverter.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/TypeUtilities.h"
#include "mlir/Pass/Pass.h"
#include "mlir/Transforms/DialectConversion.h"
#include "mlir/Pass/Pass.h"
#include "mlir/IR/BuiltinOps.h"

#include "MyDialectPasses.h"
#include "MyDialect.h"
#include "MyOps.h"

namespace my_dialect {

// -----------------------------------------------------------------------------
// Pattern 1: AddOp Conversion Pattern
// -----------------------------------------------------------------------------
class ConvertAddOp : public mlir::OpConversionPattern<AddOp> {
public:
  using mlir::OpConversionPattern<AddOp>::OpConversionPattern;

  mlir::LogicalResult
  matchAndRewrite(AddOp op, OpAdaptor adaptor,
                  mlir::ConversionPatternRewriter &rewriter) const override {
    // initially, my written code was a bit different.
    // coz, my reference was torchToArith, there was a similar conversion from torch.add to arith.addf
    // but there it was a scalar value. But in my case, it is a tensor.
    // luckily for me, arith also support tensor - so, no big conversion here.

    // and initially, i first converted the inputs to the output type (Note 'output' not 'target')
    // then passes those target converted & output type converted inputs to the rewriter
    // Here, the output type is directly passed to the rewriter, so i guess the inputs will directly be 
    // converted to the output type
    // mlir::Location loc = op.getLoc(); // -> not required for replaceOpWithNewOp

    mlir::Type outputType =
        this->getTypeConverter()->convertType(op.getResult().getType());

    if (!outputType)
      return rewriter.notifyMatchFailure(op, "type conversion failed");

    // Extract scalar element type to support scalars, vectors, and tensors
    mlir::Type elemType = mlir::getElementTypeOrSelf(outputType);

    if (llvm::isa<mlir::FloatType>(elemType)) {
      rewriter.replaceOpWithNewOp<mlir::arith::AddFOp>(
          op, outputType, adaptor.getLhs(), adaptor.getRhs());
    } else if (llvm::isa<mlir::IntegerType>(elemType)) {
      rewriter.replaceOpWithNewOp<mlir::arith::AddIOp>(
          op, outputType, adaptor.getLhs(), adaptor.getRhs());
    } else {
      return rewriter.notifyMatchFailure(
          op, "unsupported result element type: expected int or float");
    }

    return mlir::success();
  }
};

class ConvertReluOp: public mlir::OpConversionPattern<ReluOp> {
public:
  // Instatantiate the parent constructor
  using mlir::OpConversionPattern<ReluOp>::OpConversionPattern;

  mlir::LogicalResult 
  matchAndRewrite(ReluOp op, OpAdaptor adaptor, mlir::ConversionPatternRewriter &rewriter) const override {
    // create a zero tensor of float or int based on the other input
    // how to create this zero tensor? what do we need?
    // need to get the ranked type of the adaptop input
    // and get the type of the elemnts inside the tensor
    // now construct the denseElementAttr coz that is how we create a tensor in mlir using arith - arith.constant dense<0.0f> : tensor<2.f32>
    // now plug this in the mlir code
    // then convert the my_dialect::relu to arith::maximumf or arith::maximumint

    // get the shape of the tensor
    auto rankedType = mlir::dyn_cast<mlir::RankedTensorType>(adaptor.getInput().getType());
    if (!rankedType) {
      return rewriter.notifyMatchFailure(op, "Expected ranked tensor type");
    }
    // get the type of the elements within that tensor
    mlir::Type elementType = rankedType.getElementType();

    bool isFloat = false;
    // Create a tensor of zero(float/int)
    mlir::DenseElementsAttr zeroAttr;
    if (auto elType = mlir::dyn_cast<mlir::FloatType>(elementType)) {
      zeroAttr = mlir::DenseElementsAttr::get(rankedType, mlir::APFloat(elType.getFloatSemantics(), 0));
      isFloat = true;
    } else if (auto elType = mlir::dyn_cast<mlir::IntegerType>(elementType)) {
      zeroAttr = mlir::DenseElementsAttr::get(rankedType, mlir::APInt(elType.getWidth(), 0, true));
    } else {
      return rewriter.notifyMatchFailure(op, "unsupported operand type");
    }

    // Plug this in the IR
    auto zeroTensor = rewriter.create<mlir::arith::ConstantOp>(op.getLoc(), rankedType, zeroAttr);

    // convert
    if (isFloat) {
        rewriter.replaceOpWithNewOp<mlir::arith::MaximumFOp>(op, zeroTensor, adaptor.getInput());
    } else {
        rewriter.replaceOpWithNewOp<mlir::arith::MaxSIOp>(op, zeroTensor, adaptor.getInput());
    }    

    return mlir::success();
  }
};

class ConvertPrintOp: public mlir::OpConversionPattern<PrintOp> {
public:
  using mlir::OpConversionPattern<PrintOp>::OpConversionPattern;

  mlir::LogicalResult matchAndRewrite(PrintOp op, OpAdaptor adaptor, mlir::ConversionPatternRewriter &rewriter) const override {
    // so, to convert PrintOp which has the tensors as the input
    // convert to vector.print
    // but cant be directly converted as tensor is just a mathematical concept 
    // which does not occupy any physical memory in RAM
    // but ultimately when the print is called by the llvm, the print requires a actual memory to
    // load and print
    // that's why it is required to convert the tensor to memref -> then to vector.print during lowering.

    // so, get the memory Reference type & convert the input tensor to memory reference by bufferization
    // then create an index vector which is required to be passed to vector.print
    // now create the vector type
    // now print the vector

    auto input = adaptor.getInput();
    auto inputRankedType= mlir::dyn_cast<mlir::RankedTensorType>(input.getType());
    if (!inputRankedType) {
      return rewriter.notifyMatchFailure(op, "The type is unsupported or unranked");
    }

    // auto memrefType = mlir::MemRefType::get(inputRankedType.getShape(), inputRankedType.getElementType());
    // auto castOp = rewriter.create<mlir::UnrealizedConversionCastOp>(op.getLoc(), memrefType, input); // loc, target Type, input value
    // mlir::Value memRefVal = castOp.getResult(0);

    auto loc = op.getLoc();
    auto zeroAttr = rewriter.getIndexAttr(0);
    mlir::SmallVector<mlir::Value, 4> indices;
    for (int64_t i = 0; i < inputRankedType.getRank(); ++i) {
        indices.push_back(rewriter.create<mlir::arith::ConstantOp>(loc, rewriter.getIndexType(), zeroAttr));
    }

    auto vectorType = mlir::VectorType::get(inputRankedType.getShape(), inputRankedType.getElementType());
    // std::optional<mlir::Value> paddingOpt = std::nullopt;
    auto zeroPaddingAttr = rewriter.getZeroAttr(inputRankedType.getElementType());
    auto paddingVal = rewriter.create<mlir::arith::ConstantOp>(loc, inputRankedType.getElementType(), zeroPaddingAttr);
    auto vectorLoad = rewriter.create<mlir::vector::TransferReadOp>(op.getLoc(), vectorType, input, indices, paddingVal);

    rewriter.create<mlir::vector::PrintOp>(op.getLoc(), vectorLoad);

    rewriter.eraseOp(op);
    return mlir::success();
  }
};

// -----------------------------------------------------------------------------
// Lowering Pass Class
// -----------------------------------------------------------------------------
class MyDialectToArithLoweringPass : 
    public mlir::PassWrapper<MyDialectToArithLoweringPass, mlir::OperationPass<mlir::ModuleOp>> {
public:
  MLIR_DEFINE_EXPLICIT_INTERNAL_INLINE_TYPE_ID(MyDialectToArithLoweringPass)

  // // Optional: Define the pass argument (for the command line flag) and description
  llvm::StringRef getArgument() const override { return "convert-my-dialect-to-arith"; }
  llvm::StringRef getDescription() const override { return "Lower MyDialect to Arith dialect."; }

  void getDependentDialects(mlir::DialectRegistry &registry) const override {
    registry.insert<mlir::func::FuncDialect>();
    registry.insert<mlir::arith::ArithDialect>();
    registry.insert<mlir::tensor::TensorDialect>();
    registry.insert<mlir::vector::VectorDialect>();
    registry.insert<mlir::memref::MemRefDialect>();
  }

  void runOnOperation() override {
    mlir::ModuleOp module = getOperation();

    mlir::ConversionTarget target(getContext());

    // Mark lower-level dialects as legal target states
    target.addLegalDialect<mlir::arith::ArithDialect,
                          // mlir::tensor::TensorDialect,
                          mlir::vector::VectorDialect,
                          mlir::func::FuncDialect,
                          mlir::memref::MemRefDialect>();

    // Mark custom source dialect as illegal
    target.addIllegalDialect<MyDialect>();

    mlir::TypeConverter typeConverter;
    typeConverter.addConversion([](mlir::Type type) { return type; });

    mlir::RewritePatternSet patterns(&getContext());

    target.addIllegalOp<AddOp, ReluOp, PrintOp>();
    patterns.add<ConvertAddOp, ConvertReluOp, ConvertPrintOp>(typeConverter, &getContext());

    target.addLegalOp<mlir::ModuleOp>(); // need this to be legal coz, the mlir outputs everything in a module

    if (failed(applyFullConversion(module, target,
                                   std::move(patterns)))) {
      return signalPassFailure();
    }
  }
};

// Pass creator function
std::unique_ptr<mlir::Pass> createConvertMyDialectToArithPass() {
  return std::make_unique<MyDialectToArithLoweringPass>();
}

// Registration entry point
void registerConvertMyDialectToArithPass() {
  mlir::PassRegistration<MyDialectToArithLoweringPass>([]() {
    return createConvertMyDialectToArithPass();
  });
}

} // namespace my_dialect