include ExampleDialect.td

def Example_AddOp: Example_Op<"add", [Pure]> {
    let summary: "add two numbers and return a number"
    let description: [{ This operation takes two fp32 numbers as input and returns 
                        a fp32 number as output}]

    let arguments = (ins F32:$input1, F32:$input2)
    let results = (outs F32:$output)

    let assemblyFormat = "$input1 `,` $input2 attr-dict `:` type($output)";
}

def Example_MulOp: Example_Op<"mul", [Pure]> {
    let summary = "Multiple 2 variables"
    let description = "Takes two 32 bit floating point numbers as input and outputs the multiplication of those numbers"

    let arguments = (ins F32:$input1, F32:$input2)
    let results = (outs AnyFloat<[F32, F64]>:$output)

    let assemblyFormat = "$input1 `,` $input2 attr-dict `:` type($output)";
}

def Example_ReluOp: Example_Op<"relu"> {
    let summary = "Performs the relu activation"
    let description = "Takes  variables as input and outputs the max(0, variable)"

    let arguments = (ins F32:$input)
    let results = (outs F32:$output)
}
