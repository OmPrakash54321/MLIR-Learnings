/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|* From: MyDialect.td                                                         *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace my_dialect {

/// Includes example ops
/// Includes ops to add, mul, sub tensors
class MyDialect : public ::mlir::Dialect {
  explicit MyDialect(::mlir::MLIRContext *context);

  void initialize();
  friend class ::mlir::MLIRContext;
public:
  ~MyDialect() override;
  static constexpr ::llvm::StringLiteral getDialectNamespace() {
    return ::llvm::StringLiteral("my_dialect");
  }
};

} // namespace my_dialect
MLIR_DECLARE_EXPLICIT_TYPE_ID(::my_dialect::MyDialect)
