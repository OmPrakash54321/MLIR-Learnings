/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Definitions                                                             *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: MyOps.td                                                             *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_OP_LIST
#undef GET_OP_LIST

::my_dialect::AddOp,
::my_dialect::PrintOp,
::my_dialect::ReluOp
#endif // GET_OP_LIST

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// Local Utility Method Definitions
//===----------------------------------------------------------------------===//


static ::llvm::LogicalResult __mlir_ods_local_type_constraint_MyOps1(
    ::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind,
    unsigned valueIndex) {
  if (!(((::llvm::isa<::mlir::TensorType>(type))) && ([](::mlir::Type elementType) { return !((::llvm::isa<::mlir::TokenType>(elementType))); }(::llvm::cast<::mlir::ShapedType>(type).getElementType())))) {
    return op->emitOpError(valueKind) << " #" << valueIndex
        << " must be tensor of any non-token type values, but got " << type;
  }
  return ::mlir::success();
}

static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_MyOps1(
    ::mlir::Attribute attr, ::llvm::StringRef attrName, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  if (attr && !(((::llvm::isa<::mlir::FloatAttr>(attr))) && ((::llvm::cast<::mlir::FloatAttr>(attr).getType().isF32()))))
    return emitError() << "attribute '" << attrName
        << "' failed to satisfy constraint: 32-bit float attribute";
  return ::mlir::success();
}
static ::llvm::LogicalResult __mlir_ods_local_attr_constraint_MyOps1(
    ::mlir::Operation *op, ::mlir::Attribute attr, ::llvm::StringRef attrName) {
  return __mlir_ods_local_attr_constraint_MyOps1(attr, attrName, [op]() {
    return op->emitOpError();
  });
}
namespace my_dialect {


//===----------------------------------------------------------------------===//
// ::my_dialect::AddOp definitions
//===----------------------------------------------------------------------===//

namespace detail {

AddOpGenericAdaptorBase::AddOpGenericAdaptorBase(AddOp op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), properties(op.getProperties()), odsRegions(op->getRegions()) {}


} // namespace detail
AddOpAdaptor::AddOpAdaptor(AddOp op) : AddOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult AddOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

::llvm::LogicalResult AddOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }
      return ::mlir::success();
}

::mlir::Attribute AddOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code AddOp::computePropertiesHash(const Properties &prop) {
  using llvm::hash_value;
  return llvm::hash_combine();
}

std::optional<mlir::Attribute> AddOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
  return std::nullopt;
}

void AddOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
}

void AddOp::walkInherentAttrs(::mlir::MLIRContext *ctx, Properties &prop, ::llvm::function_ref<void(::llvm::StringRef, ::mlir::Attribute &)> visitor) {
}

::llvm::LogicalResult AddOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
    return ::mlir::success();
}

void AddOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value lhs, ::mlir::Value rhs) {
  odsState.addOperands(lhs);
  odsState.addOperands(rhs);
  odsState.addTypes(result);
}

AddOp AddOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Type result, ::mlir::Value lhs, ::mlir::Value rhs) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(result)>(result), std::forward<decltype(lhs)>(lhs), std::forward<decltype(rhs)>(rhs));
  auto __res__ = builder.create(__state__);
  assert((::llvm::isa<AddOp>(__res__)) && "builder didn't return the right type");
  return ::llvm::cast<AddOp>(__res__);
}

AddOp AddOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Type result, ::mlir::Value lhs, ::mlir::Value rhs) {
  return create(builder, builder.getLoc(), std::forward<decltype(result)>(result), std::forward<decltype(lhs)>(lhs), std::forward<decltype(rhs)>(rhs));
}

void AddOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value lhs, ::mlir::Value rhs) {
  odsState.addOperands(lhs);
  odsState.addOperands(rhs);

        ::llvm::SmallVector<::mlir::Type, 2> inferredReturnTypes;
        if (::mlir::succeeded(AddOp::inferReturnTypes(odsBuilder.getContext(),
                      odsState.location, odsState.operands,
                      odsState.attributes.getDictionary(odsState.getContext()),
                      odsState.getRawProperties(),
                      odsState.regions, inferredReturnTypes)))
          odsState.addTypes(inferredReturnTypes);
        else
          ::mlir::detail::reportFatalInferReturnTypesError(odsState);
        
}

AddOp AddOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Value lhs, ::mlir::Value rhs) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(lhs)>(lhs), std::forward<decltype(rhs)>(rhs));
  auto __res__ = builder.create(__state__);
  assert((::llvm::isa<AddOp>(__res__)) && "builder didn't return the right type");
  return ::llvm::cast<AddOp>(__res__);
}

AddOp AddOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Value lhs, ::mlir::Value rhs) {
  return create(builder, builder.getLoc(), std::forward<decltype(lhs)>(lhs), std::forward<decltype(rhs)>(rhs));
}

void AddOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value lhs, ::mlir::Value rhs) {
  odsState.addOperands(lhs);
  odsState.addOperands(rhs);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

AddOp AddOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::Value lhs, ::mlir::Value rhs) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(lhs)>(lhs), std::forward<decltype(rhs)>(rhs));
  auto __res__ = builder.create(__state__);
  assert((::llvm::isa<AddOp>(__res__)) && "builder didn't return the right type");
  return ::llvm::cast<AddOp>(__res__);
}

AddOp AddOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::Value lhs, ::mlir::Value rhs) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(lhs)>(lhs), std::forward<decltype(rhs)>(rhs));
}

void AddOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 2u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

AddOp AddOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(attributes)>(attributes));
  auto __res__ = builder.create(__state__);
  assert((::llvm::isa<AddOp>(__res__)) && "builder didn't return the right type");
  return ::llvm::cast<AddOp>(__res__);
}

AddOp AddOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(attributes)>(attributes));
}

void AddOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 2u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);

  ::llvm::SmallVector<::mlir::Type, 2> inferredReturnTypes;
  if (::mlir::succeeded(AddOp::inferReturnTypes(odsBuilder.getContext(),
          odsState.location, operands,
          odsState.attributes.getDictionary(odsState.getContext()),
          odsState.getRawProperties(),
          odsState.regions, inferredReturnTypes))) {
    assert(inferredReturnTypes.size() == 1u && "mismatched number of return types");
    odsState.addTypes(inferredReturnTypes);
  } else {
    ::llvm::report_fatal_error("Failed to infer result type(s).");
  }
}

AddOp AddOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(operands)>(operands), std::forward<decltype(attributes)>(attributes));
  auto __res__ = builder.create(__state__);
  assert((::llvm::isa<AddOp>(__res__)) && "builder didn't return the right type");
  return ::llvm::cast<AddOp>(__res__);
}

AddOp AddOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  return create(builder, builder.getLoc(), std::forward<decltype(operands)>(operands), std::forward<decltype(attributes)>(attributes));
}

void AddOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  assert(operands.size() == 2u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.useProperties(const_cast<Properties&>(properties));
  odsState.addAttributes(discardableAttributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

AddOp AddOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(properties)>(properties), std::forward<decltype(discardableAttributes)>(discardableAttributes));
  auto __res__ = builder.create(__state__);
  assert((::llvm::isa<AddOp>(__res__)) && "builder didn't return the right type");
  return ::llvm::cast<AddOp>(__res__);
}

AddOp AddOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(properties)>(properties), std::forward<decltype(discardableAttributes)>(discardableAttributes));
}

void AddOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  assert(operands.size() == 2u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.useProperties(const_cast<Properties&>(properties));
  odsState.addAttributes(discardableAttributes);

  ::llvm::SmallVector<::mlir::Type, 2> inferredReturnTypes;
  if (::mlir::succeeded(AddOp::inferReturnTypes(odsBuilder.getContext(),
          odsState.location, operands,
          odsState.attributes.getDictionary(odsState.getContext()),
          odsState.getRawProperties(),
          odsState.regions, inferredReturnTypes))) {
    assert(inferredReturnTypes.size() == 1u && "mismatched number of return types");
    odsState.addTypes(inferredReturnTypes);
  } else {
    ::llvm::report_fatal_error("Failed to infer result type(s).");
  }
}

AddOp AddOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(operands)>(operands), std::forward<decltype(properties)>(properties), std::forward<decltype(discardableAttributes)>(discardableAttributes));
  auto __res__ = builder.create(__state__);
  assert((::llvm::isa<AddOp>(__res__)) && "builder didn't return the right type");
  return ::llvm::cast<AddOp>(__res__);
}

AddOp AddOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  return create(builder, builder.getLoc(), std::forward<decltype(operands)>(operands), std::forward<decltype(properties)>(properties), std::forward<decltype(discardableAttributes)>(discardableAttributes));
}

::llvm::LogicalResult AddOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MyOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
    auto valueGroup1 = getODSOperands(1);

    for (auto v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MyOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MyOps1(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult AddOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::llvm::LogicalResult AddOp::inferReturnTypes(::mlir::MLIRContext *context, ::std::optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::PropertyRef properties, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes) {
  inferredReturnTypes.resize(1);
  ::mlir::Builder odsBuilder(context);
  if (operands.size() <= 0)
    return ::mlir::failure();
  ::mlir::Type odsInferredType0 = operands[0].getType();
  inferredReturnTypes[0] = odsInferredType0;
  return ::mlir::success();
}

::mlir::ParseResult AddOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::UnresolvedOperand lhsRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> lhsOperands(&lhsRawOperand, 1);  ::llvm::SMLoc lhsOperandsLoc;
  (void)lhsOperandsLoc;
  ::mlir::OpAsmParser::UnresolvedOperand rhsRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> rhsOperands(&rhsRawOperand, 1);  ::llvm::SMLoc rhsOperandsLoc;
  (void)rhsOperandsLoc;
  ::mlir::Type resultRawType{};
  ::llvm::ArrayRef<::mlir::Type> resultTypes(&resultRawType, 1);

  lhsOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(lhsRawOperand))
    return ::mlir::failure();
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
    if (failed(verifyInherentAttrs(result.name, result.attributes, [&]() {
        return parser.emitError(loc) << "'" << result.name.getStringRef() << "' op ";
      })))
      return ::mlir::failure();
  }
  if (parser.parseComma())
    return ::mlir::failure();

  rhsOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(rhsRawOperand))
    return ::mlir::failure();
  if (parser.parseColon())
    return ::mlir::failure();

  {
    ::mlir::TensorType type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    resultRawType = type;
  }
  result.addTypes(resultTypes);
  // coverity[ARRAY_VS_SINGLETON]
  if (parser.resolveOperands(lhsOperands, resultTypes[0], lhsOperandsLoc, result.operands))
    return ::mlir::failure();
  // coverity[ARRAY_VS_SINGLETON]
  if (parser.resolveOperands(rhsOperands, resultTypes[0], rhsOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void AddOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << ' ';
  _odsPrinter << getLhs();
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  ::mlir::NamedAttrList _odsAttrs((*this)->getRawDictionaryAttrs());
  (*this)->getName().walkInherentAttrs(*this, [&](::llvm::StringRef name, ::mlir::Attribute &attr) {
    _odsAttrs.append(name, attr);
  });
  _odsPrinter.printOptionalAttrDict(_odsAttrs.getDictionary((*this)->getContext()).getValue(), elidedAttrs);
  _odsPrinter << ",";
  _odsPrinter << ' ';
  _odsPrinter << getRhs();
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  {
    auto type = getResult().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::TensorType>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
}

void AddOp::getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects) {
}


} // namespace my_dialect
MLIR_DEFINE_EXPLICIT_TYPE_ID(::my_dialect::AddOp)

namespace my_dialect {


//===----------------------------------------------------------------------===//
// ::my_dialect::PrintOp definitions
//===----------------------------------------------------------------------===//

namespace detail {

PrintOpGenericAdaptorBase::PrintOpGenericAdaptorBase(PrintOp op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), properties(op.getProperties()), odsRegions(op->getRegions()) {}


} // namespace detail
PrintOpAdaptor::PrintOpAdaptor(PrintOp op) : PrintOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult PrintOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

::llvm::LogicalResult PrintOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }
      return ::mlir::success();
}

::mlir::Attribute PrintOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code PrintOp::computePropertiesHash(const Properties &prop) {
  using llvm::hash_value;
  return llvm::hash_combine();
}

std::optional<mlir::Attribute> PrintOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
  return std::nullopt;
}

void PrintOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
}

void PrintOp::walkInherentAttrs(::mlir::MLIRContext *ctx, Properties &prop, ::llvm::function_ref<void(::llvm::StringRef, ::mlir::Attribute &)> visitor) {
}

::llvm::LogicalResult PrintOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
    return ::mlir::success();
}

void PrintOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value input) {
  odsState.addOperands(input);
}

PrintOp PrintOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Value input) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(input)>(input));
  auto __res__ = builder.create(__state__);
  assert((::llvm::isa<PrintOp>(__res__)) && "builder didn't return the right type");
  return ::llvm::cast<PrintOp>(__res__);
}

PrintOp PrintOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Value input) {
  return create(builder, builder.getLoc(), std::forward<decltype(input)>(input));
}

void PrintOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value input) {
  odsState.addOperands(input);
  assert(resultTypes.size() == 0u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

PrintOp PrintOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::Value input) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(input)>(input));
  auto __res__ = builder.create(__state__);
  assert((::llvm::isa<PrintOp>(__res__)) && "builder didn't return the right type");
  return ::llvm::cast<PrintOp>(__res__);
}

PrintOp PrintOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::Value input) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(input)>(input));
}

void PrintOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

PrintOp PrintOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(attributes)>(attributes));
  auto __res__ = builder.create(__state__);
  assert((::llvm::isa<PrintOp>(__res__)) && "builder didn't return the right type");
  return ::llvm::cast<PrintOp>(__res__);
}

PrintOp PrintOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(attributes)>(attributes));
}

void PrintOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.useProperties(const_cast<Properties&>(properties));
  odsState.addAttributes(discardableAttributes);
  assert(resultTypes.size() == 0u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

PrintOp PrintOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(properties)>(properties), std::forward<decltype(discardableAttributes)>(discardableAttributes));
  auto __res__ = builder.create(__state__);
  assert((::llvm::isa<PrintOp>(__res__)) && "builder didn't return the right type");
  return ::llvm::cast<PrintOp>(__res__);
}

PrintOp PrintOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(properties)>(properties), std::forward<decltype(discardableAttributes)>(discardableAttributes));
}

::llvm::LogicalResult PrintOp::verifyInvariantsImpl() {
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MyOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult PrintOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::mlir::ParseResult PrintOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::UnresolvedOperand inputRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> inputOperands(&inputRawOperand, 1);  ::llvm::SMLoc inputOperandsLoc;
  (void)inputOperandsLoc;
  ::mlir::Type inputRawType{};
  ::llvm::ArrayRef<::mlir::Type> inputTypes(&inputRawType, 1);

  inputOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(inputRawOperand))
    return ::mlir::failure();
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
    if (failed(verifyInherentAttrs(result.name, result.attributes, [&]() {
        return parser.emitError(loc) << "'" << result.name.getStringRef() << "' op ";
      })))
      return ::mlir::failure();
  }
  if (parser.parseColon())
    return ::mlir::failure();

  {
    ::mlir::TensorType type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    inputRawType = type;
  }
  // coverity[ARRAY_VS_SINGLETON]
  if (parser.resolveOperands(inputOperands, inputTypes, inputOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void PrintOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << ' ';
  _odsPrinter << getInput();
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  ::mlir::NamedAttrList _odsAttrs((*this)->getRawDictionaryAttrs());
  (*this)->getName().walkInherentAttrs(*this, [&](::llvm::StringRef name, ::mlir::Attribute &attr) {
    _odsAttrs.append(name, attr);
  });
  _odsPrinter.printOptionalAttrDict(_odsAttrs.getDictionary((*this)->getContext()).getValue(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  {
    auto type = getInput().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::TensorType>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
}


} // namespace my_dialect
MLIR_DEFINE_EXPLICIT_TYPE_ID(::my_dialect::PrintOp)

namespace my_dialect {


//===----------------------------------------------------------------------===//
// ::my_dialect::ReluOp definitions
//===----------------------------------------------------------------------===//

namespace detail {

ReluOpGenericAdaptorBase::ReluOpGenericAdaptorBase(ReluOp op) : odsAttrs(op->getRawDictionaryAttrs()), odsOpName(op->getName()), properties(op.getProperties()), odsRegions(op->getRegions()) {}

::llvm::APFloat ReluOpGenericAdaptorBase::getAlpha() {
  auto attr = getAlphaAttr();
  return attr.getValue();
}


} // namespace detail
ReluOpAdaptor::ReluOpAdaptor(ReluOp op) : ReluOpGenericAdaptor(op->getOperands(), op) {}

::llvm::LogicalResult ReluOpAdaptor::verify(::mlir::Location loc) {
  auto tblgen_alpha = getProperties().alpha; (void)tblgen_alpha;
  if (!tblgen_alpha) return emitError(loc, "'my_dialect.relu' op requires attribute 'alpha'");

  if (tblgen_alpha && !(((::llvm::isa<::mlir::FloatAttr>(tblgen_alpha))) && ((::llvm::cast<::mlir::FloatAttr>(tblgen_alpha).getType().isF32()))))
    return emitError(loc, "'my_dialect.relu' op attribute 'alpha' failed to satisfy constraint: 32-bit float attribute");
  return ::mlir::success();
}

::llvm::LogicalResult ReluOp::setPropertiesFromAttr(Properties &prop, ::mlir::Attribute attr, ::llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
  ::mlir::DictionaryAttr dict = ::llvm::dyn_cast<::mlir::DictionaryAttr>(attr);
  if (!dict) {
    emitError() << "expected DictionaryAttr to set properties";
    return ::mlir::failure();
  }

  {
    auto &propStorage = prop.alpha;
       auto attr = dict.get("alpha");
    if (attr) {
      auto convertedAttr = ::llvm::dyn_cast<std::remove_reference_t<decltype(propStorage)>>(attr);
      if (convertedAttr) {
        propStorage = convertedAttr;
      } else {
        emitError() << "Invalid attribute `alpha` in property conversion: " << attr;
        return ::mlir::failure();
      }
    }
  }
  return ::mlir::success();
}

::mlir::Attribute ReluOp::getPropertiesAsAttr(::mlir::MLIRContext *ctx, const Properties &prop) {
    ::mlir::SmallVector<::mlir::NamedAttribute> attrs;
    ::mlir::Builder odsBuilder{ctx};

    {
      const auto &propStorage = prop.alpha;
      if (propStorage)
        attrs.push_back(odsBuilder.getNamedAttr("alpha",
                                       propStorage));
    }

  if (!attrs.empty())
    return odsBuilder.getDictionaryAttr(attrs);
  return {};
}

llvm::hash_code ReluOp::computePropertiesHash(const Properties &prop) {
  using llvm::hash_value;
  return llvm::hash_combine(
    llvm::hash_value(prop.alpha.getAsOpaquePointer()));
}

std::optional<mlir::Attribute> ReluOp::getInherentAttr(::mlir::MLIRContext *ctx, const Properties &prop, llvm::StringRef name) {
    if (name == "alpha")
      return prop.alpha;
  return std::nullopt;
}

void ReluOp::setInherentAttr(Properties &prop, llvm::StringRef name, mlir::Attribute value) {
    if (name == "alpha") {
       prop.alpha = ::llvm::dyn_cast_or_null<std::remove_reference_t<decltype(prop.alpha)>>(value);
       return;
    }
}

void ReluOp::walkInherentAttrs(::mlir::MLIRContext *ctx, Properties &prop, ::llvm::function_ref<void(::llvm::StringRef, ::mlir::Attribute &)> visitor) {
    if (prop.alpha) {
      ::mlir::Attribute value = prop.alpha;
      ::mlir::Attribute originalValue = value;
      visitor("alpha", value);
      if (value != originalValue)
        setInherentAttr(prop, "alpha", value);
    }
}

::llvm::LogicalResult ReluOp::verifyInherentAttrs(::mlir::OperationName opName, ::mlir::NamedAttrList &attrs, llvm::function_ref<::mlir::InFlightDiagnostic()> emitError) {
    {
      ::mlir::Attribute attr = attrs.get(getAlphaAttrName(opName));
      if (attr && ::mlir::failed(__mlir_ods_local_attr_constraint_MyOps1(attr, "alpha", emitError)))
        return ::mlir::failure();
    }
    return ::mlir::success();
}

::llvm::LogicalResult ReluOp::readProperties(::mlir::DialectBytecodeReader &reader, ::mlir::OperationState &state) {
  auto &prop = state.getOrAddProperties<Properties>(); (void)prop;
  if (::mlir::failed(reader.readAttribute(prop.alpha)))
    return ::mlir::failure();
  return ::mlir::success();
}

void ReluOp::writeProperties(::mlir::DialectBytecodeWriter &writer) {
  auto &prop = getProperties(); (void)prop;
  writer.writeAttribute(prop.alpha);
}

::llvm::APFloat ReluOp::getAlpha() {
  auto attr = getAlphaAttr();
  return attr.getValue();
}

void ReluOp::setAlpha(::llvm::APFloat attrValue) {
  getProperties().alpha = ::mlir::Builder((*this)->getContext()).getFloatAttr(::mlir::Builder((*this)->getContext()).getF32Type(), attrValue);
}

void ReluOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value input, ::mlir::FloatAttr alpha) {
  odsState.addOperands(input);
  odsState.getOrAddProperties<Properties>().alpha = alpha;
  odsState.addTypes(result);
}

ReluOp ReluOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Type result, ::mlir::Value input, ::mlir::FloatAttr alpha) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(result)>(result), std::forward<decltype(input)>(input), std::forward<decltype(alpha)>(alpha));
  auto __res__ = builder.create(__state__);
  assert((::llvm::isa<ReluOp>(__res__)) && "builder didn't return the right type");
  return ::llvm::cast<ReluOp>(__res__);
}

ReluOp ReluOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Type result, ::mlir::Value input, ::mlir::FloatAttr alpha) {
  return create(builder, builder.getLoc(), std::forward<decltype(result)>(result), std::forward<decltype(input)>(input), std::forward<decltype(alpha)>(alpha));
}

void ReluOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value input, ::mlir::FloatAttr alpha) {
  odsState.addOperands(input);
  odsState.getOrAddProperties<Properties>().alpha = alpha;

        ::llvm::SmallVector<::mlir::Type, 2> inferredReturnTypes;
        if (::mlir::succeeded(ReluOp::inferReturnTypes(odsBuilder.getContext(),
                      odsState.location, odsState.operands,
                      odsState.attributes.getDictionary(odsState.getContext()),
                      odsState.getRawProperties(),
                      odsState.regions, inferredReturnTypes)))
          odsState.addTypes(inferredReturnTypes);
        else
          ::mlir::detail::reportFatalInferReturnTypesError(odsState);
        
}

ReluOp ReluOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Value input, ::mlir::FloatAttr alpha) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(input)>(input), std::forward<decltype(alpha)>(alpha));
  auto __res__ = builder.create(__state__);
  assert((::llvm::isa<ReluOp>(__res__)) && "builder didn't return the right type");
  return ::llvm::cast<ReluOp>(__res__);
}

ReluOp ReluOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Value input, ::mlir::FloatAttr alpha) {
  return create(builder, builder.getLoc(), std::forward<decltype(input)>(input), std::forward<decltype(alpha)>(alpha));
}

void ReluOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value input, ::mlir::FloatAttr alpha) {
  odsState.addOperands(input);
  odsState.getOrAddProperties<Properties>().alpha = alpha;
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

ReluOp ReluOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::Value input, ::mlir::FloatAttr alpha) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(input)>(input), std::forward<decltype(alpha)>(alpha));
  auto __res__ = builder.create(__state__);
  assert((::llvm::isa<ReluOp>(__res__)) && "builder didn't return the right type");
  return ::llvm::cast<ReluOp>(__res__);
}

ReluOp ReluOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::Value input, ::mlir::FloatAttr alpha) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(input)>(input), std::forward<decltype(alpha)>(alpha));
}

void ReluOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value input, ::llvm::APFloat alpha) {
  odsState.addOperands(input);
  odsState.getOrAddProperties<Properties>().alpha = odsBuilder.getFloatAttr(odsBuilder.getF32Type(), alpha);
  odsState.addTypes(result);
}

ReluOp ReluOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Type result, ::mlir::Value input, ::llvm::APFloat alpha) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(result)>(result), std::forward<decltype(input)>(input), std::forward<decltype(alpha)>(alpha));
  auto __res__ = builder.create(__state__);
  assert((::llvm::isa<ReluOp>(__res__)) && "builder didn't return the right type");
  return ::llvm::cast<ReluOp>(__res__);
}

ReluOp ReluOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Type result, ::mlir::Value input, ::llvm::APFloat alpha) {
  return create(builder, builder.getLoc(), std::forward<decltype(result)>(result), std::forward<decltype(input)>(input), std::forward<decltype(alpha)>(alpha));
}

void ReluOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value input, ::llvm::APFloat alpha) {
  odsState.addOperands(input);
  odsState.getOrAddProperties<Properties>().alpha = odsBuilder.getFloatAttr(odsBuilder.getF32Type(), alpha);

        ::llvm::SmallVector<::mlir::Type, 2> inferredReturnTypes;
        if (::mlir::succeeded(ReluOp::inferReturnTypes(odsBuilder.getContext(),
                      odsState.location, odsState.operands,
                      odsState.attributes.getDictionary(odsState.getContext()),
                      odsState.getRawProperties(),
                      odsState.regions, inferredReturnTypes)))
          odsState.addTypes(inferredReturnTypes);
        else
          ::mlir::detail::reportFatalInferReturnTypesError(odsState);
        
}

ReluOp ReluOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::Value input, ::llvm::APFloat alpha) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(input)>(input), std::forward<decltype(alpha)>(alpha));
  auto __res__ = builder.create(__state__);
  assert((::llvm::isa<ReluOp>(__res__)) && "builder didn't return the right type");
  return ::llvm::cast<ReluOp>(__res__);
}

ReluOp ReluOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::Value input, ::llvm::APFloat alpha) {
  return create(builder, builder.getLoc(), std::forward<decltype(input)>(input), std::forward<decltype(alpha)>(alpha));
}

void ReluOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value input, ::llvm::APFloat alpha) {
  odsState.addOperands(input);
  odsState.getOrAddProperties<Properties>().alpha = odsBuilder.getFloatAttr(odsBuilder.getF32Type(), alpha);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

ReluOp ReluOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::Value input, ::llvm::APFloat alpha) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(input)>(input), std::forward<decltype(alpha)>(alpha));
  auto __res__ = builder.create(__state__);
  assert((::llvm::isa<ReluOp>(__res__)) && "builder didn't return the right type");
  return ::llvm::cast<ReluOp>(__res__);
}

ReluOp ReluOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::Value input, ::llvm::APFloat alpha) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(input)>(input), std::forward<decltype(alpha)>(alpha));
}

void ReluOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  buildPropertiesAndDiscardableAttributes(odsState, attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

ReluOp ReluOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(attributes)>(attributes));
  auto __res__ = builder.create(__state__);
  assert((::llvm::isa<ReluOp>(__res__)) && "builder didn't return the right type");
  return ::llvm::cast<ReluOp>(__res__);
}

ReluOp ReluOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(attributes)>(attributes));
}

void ReluOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  buildPropertiesAndDiscardableAttributes(odsState, attributes);

  ::llvm::SmallVector<::mlir::Type, 2> inferredReturnTypes;
  if (::mlir::succeeded(ReluOp::inferReturnTypes(odsBuilder.getContext(),
          odsState.location, operands,
          odsState.attributes.getDictionary(odsState.getContext()),
          odsState.getRawProperties(),
          odsState.regions, inferredReturnTypes))) {
    assert(inferredReturnTypes.size() == 1u && "mismatched number of return types");
    odsState.addTypes(inferredReturnTypes);
  } else {
    ::llvm::report_fatal_error("Failed to infer result type(s).");
  }
}

ReluOp ReluOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(operands)>(operands), std::forward<decltype(attributes)>(attributes));
  auto __res__ = builder.create(__state__);
  assert((::llvm::isa<ReluOp>(__res__)) && "builder didn't return the right type");
  return ::llvm::cast<ReluOp>(__res__);
}

ReluOp ReluOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  return create(builder, builder.getLoc(), std::forward<decltype(operands)>(operands), std::forward<decltype(attributes)>(attributes));
}

void ReluOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.useProperties(const_cast<Properties&>(properties));
  odsState.addAttributes(discardableAttributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

ReluOp ReluOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(properties)>(properties), std::forward<decltype(discardableAttributes)>(discardableAttributes));
  auto __res__ = builder.create(__state__);
  assert((::llvm::isa<ReluOp>(__res__)) && "builder didn't return the right type");
  return ::llvm::cast<ReluOp>(__res__);
}

ReluOp ReluOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  return create(builder, builder.getLoc(), std::forward<decltype(resultTypes)>(resultTypes), std::forward<decltype(operands)>(operands), std::forward<decltype(properties)>(properties), std::forward<decltype(discardableAttributes)>(discardableAttributes));
}

void ReluOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.useProperties(const_cast<Properties&>(properties));
  odsState.addAttributes(discardableAttributes);

  ::llvm::SmallVector<::mlir::Type, 2> inferredReturnTypes;
  if (::mlir::succeeded(ReluOp::inferReturnTypes(odsBuilder.getContext(),
          odsState.location, operands,
          odsState.attributes.getDictionary(odsState.getContext()),
          odsState.getRawProperties(),
          odsState.regions, inferredReturnTypes))) {
    assert(inferredReturnTypes.size() == 1u && "mismatched number of return types");
    odsState.addTypes(inferredReturnTypes);
  } else {
    ::llvm::report_fatal_error("Failed to infer result type(s).");
  }
}

ReluOp ReluOp::create(::mlir::OpBuilder &builder, ::mlir::Location location, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  ::mlir::OperationState __state__(location, getOperationName());
  build(builder, __state__, std::forward<decltype(operands)>(operands), std::forward<decltype(properties)>(properties), std::forward<decltype(discardableAttributes)>(discardableAttributes));
  auto __res__ = builder.create(__state__);
  assert((::llvm::isa<ReluOp>(__res__)) && "builder didn't return the right type");
  return ::llvm::cast<ReluOp>(__res__);
}

ReluOp ReluOp::create(::mlir::ImplicitLocOpBuilder &builder, ::mlir::ValueRange operands, const Properties &properties, ::llvm::ArrayRef<::mlir::NamedAttribute> discardableAttributes) {
  return create(builder, builder.getLoc(), std::forward<decltype(operands)>(operands), std::forward<decltype(properties)>(properties), std::forward<decltype(discardableAttributes)>(discardableAttributes));
}

::llvm::LogicalResult ReluOp::verifyInvariantsImpl() {
  auto tblgen_alpha = getProperties().alpha; (void)tblgen_alpha;
  if (!tblgen_alpha) return emitOpError("requires attribute 'alpha'");

  if (::mlir::failed(__mlir_ods_local_attr_constraint_MyOps1(*this, tblgen_alpha, "alpha")))
    return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MyOps1(*this, v.getType(), "operand", index++)))
        return ::mlir::failure();
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);

    for (auto v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_MyOps1(*this, v.getType(), "result", index++)))
        return ::mlir::failure();
    }
  }
  return ::mlir::success();
}

::llvm::LogicalResult ReluOp::verifyInvariants() {
  return verifyInvariantsImpl();
}

::llvm::LogicalResult ReluOp::inferReturnTypes(::mlir::MLIRContext *context, ::std::optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::PropertyRef properties, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes) {
  inferredReturnTypes.resize(1);
  ::mlir::Builder odsBuilder(context);
  if (operands.size() <= 0)
    return ::mlir::failure();
  ::mlir::Type odsInferredType0 = operands[0].getType();
  inferredReturnTypes[0] = odsInferredType0;
  return ::mlir::success();
}

::mlir::ParseResult ReluOp::parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result) {
  ::mlir::OpAsmParser::UnresolvedOperand inputRawOperand{};
  ::llvm::ArrayRef<::mlir::OpAsmParser::UnresolvedOperand> inputOperands(&inputRawOperand, 1);  ::llvm::SMLoc inputOperandsLoc;
  (void)inputOperandsLoc;
  ::mlir::Type resultRawType{};
  ::llvm::ArrayRef<::mlir::Type> resultTypes(&resultRawType, 1);

  inputOperandsLoc = parser.getCurrentLocation();
  if (parser.parseOperand(inputRawOperand))
    return ::mlir::failure();
  {
    auto loc = parser.getCurrentLocation();(void)loc;
    if (parser.parseOptionalAttrDict(result.attributes))
      return ::mlir::failure();
    if (failed(verifyInherentAttrs(result.name, result.attributes, [&]() {
        return parser.emitError(loc) << "'" << result.name.getStringRef() << "' op ";
      })))
      return ::mlir::failure();
  }
  if (parser.parseColon())
    return ::mlir::failure();

  {
    ::mlir::TensorType type;
    if (parser.parseCustomTypeWithFallback(type))
      return ::mlir::failure();
    resultRawType = type;
  }
  result.addTypes(resultTypes);
  // coverity[ARRAY_VS_SINGLETON]
  if (parser.resolveOperands(inputOperands, resultTypes[0], inputOperandsLoc, result.operands))
    return ::mlir::failure();
  return ::mlir::success();
}

void ReluOp::print(::mlir::OpAsmPrinter &_odsPrinter) {
  _odsPrinter << ' ';
  _odsPrinter << getInput();
  ::llvm::SmallVector<::llvm::StringRef, 2> elidedAttrs;
  ::mlir::NamedAttrList _odsAttrs((*this)->getRawDictionaryAttrs());
  (*this)->getName().walkInherentAttrs(*this, [&](::llvm::StringRef name, ::mlir::Attribute &attr) {
    _odsAttrs.append(name, attr);
  });
  _odsPrinter.printOptionalAttrDict(_odsAttrs.getDictionary((*this)->getContext()).getValue(), elidedAttrs);
  _odsPrinter << ' ' << ":";
  _odsPrinter << ' ';
  {
    auto type = getResult().getType();
    if (auto validType = ::llvm::dyn_cast<::mlir::TensorType>(type))
      _odsPrinter.printStrippedAttrOrType(validType);
   else
     _odsPrinter << type;
  }
}

void ReluOp::getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects) {
}

void ReluOp::buildPropertiesAndDiscardableAttributes(::mlir::OperationState &odsState, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  Properties &properties = odsState.getOrAddProperties<Properties>();
  populateDefaultProperties(odsState.name, properties);
  ::llvm::SmallVector<::mlir::NamedAttribute> inherentAttributes;
  for (const ::mlir::NamedAttribute &attr : attributes) {
    ::llvm::StringRef name = attr.getName().getValue();
    if (name == "alpha")
      inherentAttributes.push_back(attr);
    else
      odsState.addAttribute(attr.getName(), attr.getValue());
  }
  if (inherentAttributes.empty())
    return;
  if (::mlir::failed(setPropertiesFromAttr(
          properties,
          ::mlir::DictionaryAttr::get(odsState.getContext(), inherentAttributes),
          [&]() { return ::mlir::emitError(odsState.location); })))
    ::llvm::report_fatal_error("Property conversion failed.");
}


} // namespace my_dialect
MLIR_DEFINE_EXPLICIT_TYPE_ID(::my_dialect::ReluOp)
MLIR_DEFINE_EXPLICIT_TYPE_ID(::my_dialect::detail::ReluOpGenericAdaptorBase::Properties)


#endif // GET_OP_CLASSES

