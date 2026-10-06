#ifndef EXAMPLE_DIALECT_H
#define EXAMPLE_DIALECT_H

include "mlir/IR/OpBase.td"

def Example_Dialect: Dialect {
    let name: "example";
    let summary: "This is just an example dialect I'm creating for experimenting and learning";
    let description: "This example dialect will have operations like Add, Mul and Relu";

    let cppNamespace: "::example";
    let useDefaultAttributePrinterParser = 1;
    let useDefaultTypePrinterParser = 1;

}

class Example_Op<string nemonic, list<Trait> traits = []>: Op<Example_Dialect, nemonic, traits>

#endif