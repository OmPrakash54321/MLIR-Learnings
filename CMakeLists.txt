cmake_minimum_required(VERSION 3.20)
project(my-opt-project)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# threw linking error. so had to add this line which forces no run time type information
add_compile_options(-fno-rtti)

################ MLIR / LLVM directories ############################
# Find your LLVM/MLIR installation or build directory
find_package(MLIR REQUIRED CONFIG)
message(STATUS "Using MLIRConfig.cmake from: ${MLIR_DIR}")
include_directories(${LLVM_INCLUDE_DIRS} ${MLIR_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})
link_directories(${LLVM_BUILD_LIBRARY_DIR})

message(STATUS "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
message(STATUS "LLVM INCLUDE LIBS: ${LLVM_INCLUDE_DIRS}")
message(STATUS "MLIR INCLUDE LIBS: ${MLIR_INCLUDE_DIRS}")
message(STATUS "LLVM_LIBRARY_DIRS: ${LLVM_LIBRARY_DIRS}")

################# Create exectutable ################################
add_executable(my-opt my-opt.cpp)

#################### Custom dialect files ##########################
add_library(MyDialectDefs
    MyDialect.cpp
    MyOps.cpp
)
target_include_directories(MyDialectDefs PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(MyDialectDefs PRIVATE MLIRIR MLIRSupport)

##########################link the runtime against #########################
# Link the essential MLIR libraries required for a custom opt tool
target_link_libraries(my-opt PRIVATE
    MyDialectDefs      # <--- Links your custom dialect's compiled logic
    MLIRFuncDialect    # <--- Fixes the FuncDialect undefined references
    MLIRIR             # Core MLIR structural definitions
    MLIROptLib         # Binary execution driver engine for MlirOptMain
    MLIRSupport        # Lower-level diagnostic routines
)