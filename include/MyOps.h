#pragma once

#include "mlir/IR/OpDefinition.h"
#include "mlir/Interfaces/SideEffectInterfaces.h" 
#include "mlir/Interfaces/InferTypeOpInterface.h"
#include "mlir/Bytecode/BytecodeOpInterface.h"

#define GET_OP_CLASSES
#include "MyOps.h.inc"