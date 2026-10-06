/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Declarations                                                            *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: MyOps.td                                                             *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace my_dialect {

/// Add 2 tensors
/// The my_dialect.add operation takes 2 tensors as input and perfoms addition.
/// Ensures both the shapes and types are the same.
/// 
/// Example:
/// %res = my_dialect.add %in1, %in2: tensor<4x2xf32>
class AddOp;

} // namespace my_dialect
namespace my_dialect {

/// Print the input
/// my_dialect.print will print the the input it gets
/// 
/// Example:
/// my_dialect.print %val: tensor<2x4xf32>
class PrintOp;

} // namespace my_dialect
namespace my_dialect {

/// Perform the Relu / leaky relu activation
/// my_dialect.relu performs the f(x) = x for x >= 0 
///     and f(x) = alpha * x for x < 0
///     
///     Example:
///     %res = my_dialect.relu %input: tensor<4xf32>
class ReluOp;

} // namespace my_dialect
#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES

namespace my_dialect {


//===----------------------------------------------------------------------===//
// ::my_dialect::AddOp declarations
//===----------------------------------------------------------------------===//

namespace detail {

class AddOpGenericAdaptorBase {
public:
  using Properties = ::mlir::EmptyProperties;
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  AddOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("my_dialect.add", odsAttrs.getContext());
  }

  AddOpGenericAdaptorBase(AddOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

};

} // namespace detail
template <typename RangeT>
class AddOpGenericAdaptor : public detail::AddOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::AddOpGenericAdaptorBase;
  static constexpr int odsIndex_lhs = 0;
  static constexpr int odsIndex_rhs = 1;
public:
  AddOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  AddOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::PropertyRef properties, ::mlir::RegionRange regions = {}) : AddOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  AddOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : AddOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  AddOpGenericAdaptor(RangeT values, const AddOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = AddOp, typename = std::enable_if_t<std::is_same_v<LateInst, AddOp>>>
  AddOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getLhs() {
    return (*getODSOperands(0).begin());
  }

  ValueT getRhs() {
    return (*getODSOperands(1).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class AddOpAdaptor : public AddOpGenericAdaptor<::mlir::ValueRange> {
public:
  using AddOpGenericAdaptor::AddOpGenericAdaptor;
  AddOpAdaptor(AddOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class AddOp : public ::mlir::Op<AddOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::TensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<2>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::ConditionallySpeculatable::Trait, ::mlir::OpTrait::AlwaysSpeculatableImplTrait, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::OpTrait::IsCommutative, ::mlir::OpTrait::SameOperandsAndResultType, ::mlir::InferTypeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = AddOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = AddOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static constexpr int odsIndex_lhs = 0;
  static constexpr int odsIndex_rhs = 1;
  static constexpr int odsIndex_result = 0;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("my_dialect.add");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::TensorType> getLhs() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSOperands(0).begin());
  }

  ::mlir::TypedValue<::mlir::TensorType> getRhs() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSOperands(1).begin());
  }

  ::mlir::OpOperand &getLhsMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  ::mlir::OpOperand &getRhsMutable() {
    auto range = getODSOperandIndexAndLength(1);
    return getOperation()->getOpOperand(range.first);
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::TensorType> getResult() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSResults(0).begin());
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void walkInherentAttrs(::mlir::MLIRContext *ctx, Properties &prop, ::llvm::function_ref<void(::llvm::StringRef, ::mlir::Attribute &)> visitor);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value lhs, ::mlir::Value rhs);
  static AddOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Type result, ::mlir::Value lhs, ::mlir::Value rhs);
  static AddOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Type result, ::mlir::Value lhs, ::mlir::Value rhs);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value lhs, ::mlir::Value rhs);
  static AddOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Value lhs, ::mlir::Value rhs);
  static AddOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Value lhs, ::mlir::Value rhs);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value lhs, ::mlir::Value rhs);
  static AddOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::Value lhs, ::mlir::Value rhs);
  static AddOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::Value lhs, ::mlir::Value rhs);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static AddOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static AddOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static AddOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static AddOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  static AddOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  static AddOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  static AddOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  static AddOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  ::mlir::OpFoldResult fold(FoldAdaptor adaptor);
  static ::llvm::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::std::optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::PropertyRef properties, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
public:
};

} // namespace my_dialect
MLIR_DECLARE_EXPLICIT_TYPE_ID(::my_dialect::AddOp)

namespace my_dialect {


//===----------------------------------------------------------------------===//
// ::my_dialect::PrintOp declarations
//===----------------------------------------------------------------------===//

namespace detail {

class PrintOpGenericAdaptorBase {
public:
  using Properties = ::mlir::EmptyProperties;
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  PrintOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("my_dialect.print", odsAttrs.getContext());
  }

  PrintOpGenericAdaptorBase(PrintOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

};

} // namespace detail
template <typename RangeT>
class PrintOpGenericAdaptor : public detail::PrintOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::PrintOpGenericAdaptorBase;
  static constexpr int odsIndex_input = 0;
public:
  PrintOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  PrintOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::PropertyRef properties, ::mlir::RegionRange regions = {}) : PrintOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  PrintOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : PrintOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  PrintOpGenericAdaptor(RangeT values, const PrintOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = PrintOp, typename = std::enable_if_t<std::is_same_v<LateInst, PrintOp>>>
  PrintOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getInput() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class PrintOpAdaptor : public PrintOpGenericAdaptor<::mlir::ValueRange> {
public:
  using PrintOpGenericAdaptor::PrintOpGenericAdaptor;
  PrintOpAdaptor(PrintOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class PrintOp : public ::mlir::Op<PrintOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = PrintOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = PrintOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static constexpr int odsIndex_input = 0;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("my_dialect.print");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::TensorType> getInput() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSOperands(0).begin());
  }

  ::mlir::OpOperand &getInputMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void walkInherentAttrs(::mlir::MLIRContext *ctx, Properties &prop, ::llvm::function_ref<void(::llvm::StringRef, ::mlir::Attribute &)> visitor);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value input);
  static PrintOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Value input);
  static PrintOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Value input);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value input);
  static PrintOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::Value input);
  static PrintOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::Value input);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static PrintOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static PrintOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  static PrintOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  static PrintOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
};

} // namespace my_dialect
MLIR_DECLARE_EXPLICIT_TYPE_ID(::my_dialect::PrintOp)

namespace my_dialect {


//===----------------------------------------------------------------------===//
// ::my_dialect::ReluOp declarations
//===----------------------------------------------------------------------===//

namespace detail {

class ReluOpGenericAdaptorBase {
public:
  struct Properties {
    using alphaTy = ::mlir::FloatAttr;
    alphaTy alpha;

    auto getAlpha() const {
      auto &propStorage = this->alpha;
      return ::llvm::cast<::mlir::FloatAttr>(propStorage);
    }
    void setAlpha(const ::mlir::FloatAttr &propValue) {
      this->alpha = propValue;
    }
    bool operator==(const Properties &rhs) const {
      return 
        rhs.alpha == this->alpha &&
        true;
    }
    bool operator!=(const Properties &rhs) const {
      return !(*this == rhs);
    }
  };
protected:
  ::mlir::DictionaryAttr odsAttrs;
  ::std::optional<::mlir::OperationName> odsOpName;
  Properties properties;
  ::mlir::RegionRange odsRegions;
public:
  ReluOpGenericAdaptorBase(::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : odsAttrs(attrs), properties(properties), odsRegions(regions) {  if (odsAttrs)
      odsOpName.emplace("my_dialect.relu", odsAttrs.getContext());
  }

  ReluOpGenericAdaptorBase(ReluOp op);

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index, unsigned odsOperandsSize) {
    return {index, 1};
  }

  const Properties &getProperties() {
    return properties;
  }

  ::mlir::DictionaryAttr getAttributes() {
    return odsAttrs;
  }

  ::mlir::FloatAttr getAlphaAttr() {
    auto attr = ::llvm::cast<::mlir::FloatAttr>(getProperties().alpha);
    return attr;
  }

  ::llvm::APFloat getAlpha();
};

} // namespace detail
template <typename RangeT>
class ReluOpGenericAdaptor : public detail::ReluOpGenericAdaptorBase {
  using ValueT = ::llvm::detail::ValueOfRange<RangeT>;
  using Base = detail::ReluOpGenericAdaptorBase;
  static constexpr int odsIndex_input = 0;
public:
  ReluOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, const Properties &properties, ::mlir::RegionRange regions = {}) : Base(attrs, properties, regions), odsOperands(values) {}

  ReluOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs, ::mlir::PropertyRef properties, ::mlir::RegionRange regions = {}) : ReluOpGenericAdaptor(values, attrs, (properties ? *properties.as<Properties *>() : Properties{}), regions) {}

  ReluOpGenericAdaptor(RangeT values, ::mlir::DictionaryAttr attrs = nullptr) : ReluOpGenericAdaptor(values, attrs, Properties{}, {}) {}

  ReluOpGenericAdaptor(RangeT values, const ReluOpGenericAdaptorBase &base) : Base(base), odsOperands(values) {}

  template <typename LateInst = ReluOp, typename = std::enable_if_t<std::is_same_v<LateInst, ReluOp>>>
  ReluOpGenericAdaptor(RangeT values, LateInst op) : Base(op), odsOperands(values) {}

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return Base::getODSOperandIndexAndLength(index, odsOperands.size());
  }

  RangeT getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(odsOperands.begin(), valueRange.first),
             std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
  }

  ValueT getInput() {
    return (*getODSOperands(0).begin());
  }

  RangeT getOperands() {
    return odsOperands;
  }

private:
  RangeT odsOperands;
};
class ReluOpAdaptor : public ReluOpGenericAdaptor<::mlir::ValueRange> {
public:
  using ReluOpGenericAdaptor::ReluOpGenericAdaptor;
  ReluOpAdaptor(ReluOp op);

  ::llvm::LogicalResult verify(::mlir::Location loc);
};
class ReluOp : public ::mlir::Op<ReluOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::TensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::BytecodeOpInterface::Trait, ::mlir::ConditionallySpeculatable::Trait, ::mlir::OpTrait::AlwaysSpeculatableImplTrait, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::OpTrait::SameOperandsAndResultShape, ::mlir::OpTrait::SameOperandsAndResultType, ::mlir::InferTypeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ReluOpAdaptor;
  template <typename RangeT>
  using GenericAdaptor = ReluOpGenericAdaptor<RangeT>;
  using FoldAdaptor = GenericAdaptor<::llvm::ArrayRef<::mlir::Attribute>>;
  static constexpr int odsIndex_input = 0;
  static constexpr int odsIndex_result = 0;
  using Properties = FoldAdaptor::Properties;
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("alpha")};
    return ::llvm::ArrayRef(attrNames);
  }

  ::mlir::StringAttr getAlphaAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getAlphaAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("my_dialect.relu");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::operand_range getODSOperands(unsigned index) {
    auto valueRange = getODSOperandIndexAndLength(index);
    return {std::next(getOperation()->operand_begin(), valueRange.first),
             std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::TensorType> getInput() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSOperands(0).begin());
  }

  ::mlir::OpOperand &getInputMutable() {
    auto range = getODSOperandIndexAndLength(0);
    return getOperation()->getOpOperand(range.first);
  }

  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index) {
    return {index, 1};
  }

  ::mlir::Operation::result_range getODSResults(unsigned index) {
    auto valueRange = getODSResultIndexAndLength(index);
    return {std::next(getOperation()->result_begin(), valueRange.first),
             std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
  }

  ::mlir::TypedValue<::mlir::TensorType> getResult() {
    return ::llvm::cast<::mlir::TypedValue<::mlir::TensorType>>(*getODSResults(0).begin());
  }

  static ::llvm::LogicalResult setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::mlir::Attribute getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop);
  static llvm::hash_code computePropertiesHash(const Properties &prop);
  static std::optional<mlir::Attribute> getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name);
  static void setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value);
  static void walkInherentAttrs(::mlir::MLIRContext *ctx, Properties &prop, ::llvm::function_ref<void(::llvm::StringRef, ::mlir::Attribute &)> visitor);
  static ::llvm::LogicalResult verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError);
  static ::llvm::LogicalResult readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state);
  void writeProperties(::mlir::DialectBytecodeWriter &writer);
  ::mlir::FloatAttr getAlphaAttr() {
    return ::llvm::cast<::mlir::FloatAttr>(getProperties().alpha);
  }

  ::llvm::APFloat getAlpha();
  void setAlphaAttr(::mlir::FloatAttr attr) {
    getProperties().alpha = attr;
  }

  void setAlpha(::llvm::APFloat attrValue);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value input, ::mlir::FloatAttr alpha);
  static ReluOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Type result, ::mlir::Value input, ::mlir::FloatAttr alpha);
  static ReluOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Type result, ::mlir::Value input, ::mlir::FloatAttr alpha);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value input, ::mlir::FloatAttr alpha);
  static ReluOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Value input, ::mlir::FloatAttr alpha);
  static ReluOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Value input, ::mlir::FloatAttr alpha);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value input, ::mlir::FloatAttr alpha);
  static ReluOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::Value input, ::mlir::FloatAttr alpha);
  static ReluOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::Value input, ::mlir::FloatAttr alpha);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value input, ::llvm::APFloat alpha);
  static ReluOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Type result, ::mlir::Value input, ::llvm::APFloat alpha);
  static ReluOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Type result, ::mlir::Value input, ::llvm::APFloat alpha);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value input, ::llvm::APFloat alpha);
  static ReluOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Value input, ::llvm::APFloat alpha);
  static ReluOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Value input, ::llvm::APFloat alpha);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value input, ::llvm::APFloat alpha);
  static ReluOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::Value input, ::llvm::APFloat alpha);
  static ReluOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::Value input, ::llvm::APFloat alpha);
  [[deprecated("use the overload taking Properties and discardableAttributes instead")]]
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  [[deprecated("use the overload taking Properties and discardableAttributes instead")]]
  static ReluOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  [[deprecated("use the overload taking Properties and discardableAttributes instead")]]
  static ReluOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  [[deprecated("use the overload taking Properties and discardableAttributes instead")]]
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  [[deprecated("use the overload taking Properties and discardableAttributes instead")]]
  static ReluOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  [[deprecated("use the overload taking Properties and discardableAttributes instead")]]
  static ReluOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  static ReluOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  static ReluOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  static ReluOp create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  static ReluOp create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes = {});
  ::llvm::LogicalResult verifyInvariantsImpl();
  ::llvm::LogicalResult verifyInvariants();
  static ::llvm::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::std::optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::PropertyRef properties, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 1 && "invalid attribute index");
    assert(name.getStringRef() == getOperationName() && "invalid operation name");
    assert(name.isRegistered() && "Operation isn't registered, missing a "
          "dependent dialect loading?");
    return name.getAttributeNames()[index];
  }

  static void buildPropertiesAndDiscardableAttributes(::mlir::OperationState &odsState, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes);
public:
};

} // namespace my_dialect
MLIR_DECLARE_EXPLICIT_TYPE_ID(::my_dialect::ReluOp)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::my_dialect::detail::ReluOpGenericAdaptorBase::Properties)


#endif // GET_OP_CLASSES

