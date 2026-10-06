include "mlir/IR/OpBase.td"
include "mlir/Interfaces/SideEffectInterfaces.td" 
include "mlir/Interfaces/InferTypeOpInterface.td" 
include "MyDialect.td"

// what ops can i create?
// add
// mul
// relu
// print

def AddOp: Op<My_Dialect, "add", [
    Pure,
    Commutative, 
    SameOperandsAndResultType,
]> {
    let summary = "Add 2 tensors";
    let description = [{
        The my_dialect.add operation takes 2 tensors as input and perfoms addition.
        Ensures both the shapes and types are the same.
    
        Example:
        %res = my_dialect.add %in1, %in2: tensor<4x2xf32>
    }];

    let arguments = (ins AnyTensor:$lhs, AnyTensor:$rhs);
    let results = (outs AnyTensor:$result);

    let assemblyFormat = "$lhs attr-dict `,` $rhs `:` type($result)";
    let hasFolder = 1; 
}

def ReluOp: Op<My_Dialect, "relu", [
    Pure,
    SameOperandsAndResultShape, 
    SameOperandsAndResultType
]> {
    let summary = "Perform the Relu / leaky relu activation";
    let description = [{my_dialect.relu performs the f(x) = x for x >= 0 
    and f(x) = alpha * x for x < 0
    
    Example:
    %res = my_dialect.relu %input: tensor<4xf32>
    }];

    let arguments = (ins 
    AnyTensor:$input,
    F32Attr:$alpha
    );
    let results = (outs AnyTensor:$result);

    let assemblyFormat = "$input attr-dict `:` type($result)";
}

def PrintOp: Op<My_Dialect, "print", []> {
    let summary = "Print the input";
    let description = [{
        my_dialect.print will print the the input it gets

        Example:
        my_dialect.print %val: tensor<2x4xf32>
    }];

    let arguments = (ins AnyTensor:$input);

    let assemblyFormat = "$input attr-dict `:` type($input)";
}

