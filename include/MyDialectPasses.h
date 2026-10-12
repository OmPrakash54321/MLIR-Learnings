#ifndef MY_DIALECT_PASSES_H
#define MY_DIALECT_PASSES_H

#include <memory>

// Forward declarations to avoid heavy header inclusions
namespace mlir {
class Pass;
} // namespace mlir

namespace my_dialect {

// conversion pass
std::unique_ptr<mlir::Pass> createConvertMyDialectToArithPass();
void registerConvertMyDialectToArithPass();

// transformatio (fusion) pass
std::unique_ptr<mlir::Pass> createTransformationPass();
void registerTransformationPass();

} // namespace my_dialect

#endif // MY_DIALECT_PASSES_H