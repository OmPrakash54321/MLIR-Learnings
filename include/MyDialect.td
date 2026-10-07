include "mlir/IR/OpBase.td"

// -------------- My dialect declaration ----------------------

def My_Dialect: Dialect {
    let name = "my_dialect";
    let summary = "Includes example ops";
    let description = "Includes ops to add, mul, sub tensors";

    let cppNamespace = "::my_dialect";
}