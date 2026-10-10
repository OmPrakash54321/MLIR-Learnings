#ifndef MY_DIALECT_PASSES_H
#define MY_DIALECT_PASSES_H

#include <memory>

// Forward declarations to avoid heavy header inclusions
namespace mlir {
class Pass;
} // namespace mlir

namespace my_dialect {

// 1. Declare the pass creation function
std::unique_ptr<mlir::Pass> createConvertMyDialectToArithPass();

// 2. Declare the pass registration function
void registerConvertMyDialectToArithPass();

} // namespace my_dialect

#endif // MY_DIALECT_PASSES_H