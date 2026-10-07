#include "MyDialect.h"
#include "MyOps.h"

#define GET_OP_CLASSES
#include "MyOps.cpp.inc"

namespace my_dialect {

mlir::OpFoldResult AddOp::fold(FoldAdaptor adaptor) {
    // Return a null OpFoldResult to indicate that constant folding was NOT performed
    return nullptr;
}

} // namespace my_dialect