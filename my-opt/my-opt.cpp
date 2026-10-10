#include "mlir/IR/DialectRegistry.h" // registry that contains all the dialects
#include "mlir/Tools/mlir-opt/MlirOptMain.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Dialect/Arith/IR/Arith.h"

// #include "mlir/InitAllDialects.h"

#include "MyDialect.h"
#include "MyDialectPasses.h"

int main(int argc, char** argv) {
    mlir::DialectRegistry registry;

    registry.insert<mlir::func::FuncDialect>();
    registry.insert<mlir::arith::ArithDialect>();
    registry.insert<my_dialect::MyDialect>();

    my_dialect::registerConvertMyDialectToArithPass();

    // Use MlirOptMain as the entry point
    return mlir::asMainReturnCode(
        mlir::MlirOptMain(argc, argv, "My Custom Opt tool\n", registry)
    );
}