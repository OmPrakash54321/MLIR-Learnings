add_executable(my-opt my-opt.cpp)

target_link_libraries(my-opt PRIVATE
    MyDialectDefs      # <--- Links custom dialect's compiled logic
    MLIRFuncDialect    # <--- Fixes the FuncDialect undefined references
    MLIRIR             # Core MLIR structural definitions
    MLIROptLib         # Binary execution driver engine for MlirOptMain
    MLIRSupport        # Lower-level diagnostic routines
)