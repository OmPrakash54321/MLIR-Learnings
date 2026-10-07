cmake_minimum_required(VERSION 3.20)
project(my-opt-project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# threw linking error. so had to add this line which forces no run time type information
add_compile_options(-fno-rtti)

# Place all compiled binaries into build/bin/
# needed coz, when the build happens, a folder named my-opt/ gets created automatically to mirror the dir structure
# using the following line, create a build/bin/ and move the exec inside it
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# MLIR / LLVM include directories
find_package(MLIR REQUIRED CONFIG)
message(STATUS "Using MLIRConfig.cmake from: ${MLIR_DIR}")

# include the LLVM / MLIR cmake helpers, flags, settings
list(APPEND CMAKE_MODULE_PATH "${MLIR_CMAKE_DIR}")
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(TableGen)
include(AddLLVM)
include(AddMLIR)
include(HandleLLVMOptions)

include_directories(${LLVM_INCLUDE_DIRS} ${MLIR_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)

# Points to the root file that includes the dialect.td file
set(LLVM_TARGET_DEFINITIONS ${CMAKE_CURRENT_SOURCE_DIR}/include/MyOps.td)

# Generate the .inc files inside build/include/
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/include)
mlir_tablegen(include/MyDialect.h.inc -gen-dialect-decls)
mlir_tablegen(include/MyDialect.cpp.inc -gen-dialect-defs)
mlir_tablegen(include/MyOps.h.inc -gen-op-decls)
mlir_tablegen(include/MyOps.cpp.inc -gen-op-defs)
# Create a target named 'MyDialectIncGen' that forces TableGen to execute
add_public_tablegen_target(MyDialectIncGen)


# look into the child cmake
add_subdirectory(lib)
add_subdirectory(my-opt)