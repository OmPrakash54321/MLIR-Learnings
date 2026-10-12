#include "mlir/Pass/Pass.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
#include "mlir/IR/PatternMatch.h"
#include "mlir/IR/Value.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"

#include "MyDialect.h"
#include "MyOps.h"
#include "MyDialectPasses.h"

namespace my_dialect {

class FusedAddRelu: public mlir::OpRewritePattern<my_dialect::ReluOp> {
using mlir::OpRewritePattern<my_dialect::ReluOp>::OpRewritePattern;

public:

mlir::LogicalResult matchAndRewrite(my_dialect::ReluOp reluOp, mlir::PatternRewriter &rewriter) const override {
    // check if the input to relu comes from add op
    // if true, convert this relu to fused add_relu

    // but one thing to note is that there is an addOp
    // but should it be rmoved - depends on whether there are othr nodes tha use the outptu of add
    // so, it has to be handled based on that
    // but the funtion mlir::applyPatternsAndFoldGreedily takes care of this folding
    // it implicitly checks this and removes add if it isn't used by other nodes

    auto reluValue = reluOp.getInput();
    auto addOp = reluValue.getDefiningOp<my_dialect::AddOp>();

    if (!addOp) return mlir::failure();

    rewriter.replaceOpWithNewOp<my_dialect::AddReluOp>(reluOp, reluValue.getType(), addOp.getLhs(), addOp.getRhs());

    if (addOp.use_empty()) {
        rewriter.eraseOp(addOp);
    }
    return mlir::success();
}
}; // FusedAddRelu

class MyDialectTransformationPass: public mlir::PassWrapper<MyDialectTransformationPass, mlir::OperationPass<mlir::func::FuncOp>> {
public:
MLIR_DEFINE_EXPLICIT_INTERNAL_INLINE_TYPE_ID(MyDialectTransformationPass)

llvm::StringRef getArgument() const override { return "fuse-add-relu"; }
llvm::StringRef getDescription() const override { return "Transformation pass in my_dialect"; }

void runOnOperation() override {
    mlir::func::FuncOp func = getOperation();

    mlir::RewritePatternSet patterns(&getContext());
    patterns.add<my_dialect::FusedAddRelu>(&getContext());

    if (mlir::failed(mlir::applyPatternsGreedily(func, std::move(patterns)))) {
        return signalPassFailure();
    }
} // runOnOperation

};
    
// Pass creator function
std::unique_ptr<mlir::Pass> createTransformationPass() {
  return std::make_unique<MyDialectTransformationPass>();
}

// Registration entry point
void registerTransformationPass() {
  mlir::PassRegistration<MyDialectTransformationPass>([]() {
    return createTransformationPass();
  });
}
} // my_dialect namespace