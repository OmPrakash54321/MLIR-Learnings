#include "MyDialect.h"
#include "MyOps.h"

#include "MyDialect.cpp.inc"

namespace my_dialect {

void MyDialect::initialize() {
    addOperations<
#define GET_OP_LIST
#include "MyOps.cpp.inc"
      >();
}

}