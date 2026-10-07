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

# look into the child cmake
add_subdirectory(lib)
add_subdirectory(my-opt)