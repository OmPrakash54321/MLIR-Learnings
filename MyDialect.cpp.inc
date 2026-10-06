/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: MyDialect.td                                                         *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

MLIR_DEFINE_EXPLICIT_TYPE_ID(::my_dialect::MyDialect)
namespace my_dialect {


MyDialect::MyDialect(::mlir::MLIRContext *context)
    : ::mlir::Dialect(getDialectNamespace(), context, ::mlir::TypeID::get<MyDialect>())
    
     {
  
  initialize();
}

MyDialect::~MyDialect() = default;


} // namespace my_dialect
