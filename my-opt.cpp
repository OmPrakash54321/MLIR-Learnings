#include "mlir/IR/DialectRegistry.h" // registry that contains all the dialects
#include "mlir/Tools/mlir-opt/MlirOptMain.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "MyDialect.h"


int main(int argc, char** argv) {
    mlir::DialectRegistry registry;

    registry.insert<mlir::func::FuncDialect>();

    registry.insert<my_dialect::MyDialect>();

    // Use MlirOptMain as the entry point
    return mlir::asMainReturnCode(
        mlir::MlirOptMain(argc, argv, "My Dialect Optimizer\n", registry)
    );
}