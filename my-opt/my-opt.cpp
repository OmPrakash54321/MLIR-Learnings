#include "mlir/IR/DialectRegistry.h" // registry that contains all the dialects
#include "mlir/Tools/mlir-opt/MlirOptMain.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"

#include "MyDialect.h"
#include "MyDialectPasses.h"

int main(int argc, char** argv) {
    // these are not required coz, below in registration of our conversion,
    // the required dialects are already added in the registry
    
    // Flow:
    // Register the custom dialect
    // add the file as module - ensure it is succefully getting loaded to module
    // Load the conversion pass to the pass manager
    // Parse the cli options for what passes to run
    // Ensure if that is succesfull

    /*  
        MlirOptMain - is very powerful, it handles the CLI parsing, loading the test file,
        creating and update the module with the test file
    */

    // Following Not required as the MlirOptMain takes care of it.
    // mlir::registerMLIRContextCLOptions();
    // mlir::registerAndParseCLIOptions();
    // llvm::cl::ParseCommandLineOpticontextons(argc, argv, "Hello compiler\n");

    mlir::DialectRegistry registry;
    registry.insert<mlir::func::FuncDialect>();
    registry.insert<my_dialect::MyDialect>();

    my_dialect::registerConvertMyDialectToArithPass();

    // Use MlirOptMain as the entry point
    return mlir::asMainReturnCode(
        mlir::MlirOptMain(argc, argv, "My Custom Opt tool\n", registry)
    );
}