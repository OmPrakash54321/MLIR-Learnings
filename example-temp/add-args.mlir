func.func @add_args(%input1: f32, %input2: f32) -> f32 {
    %sum = arith.addf %input1, %input2: f32
    func.return %sum: f32
}

func.func @add_tensors(%arg0: tensor<4xf32>, %arg1: tensor<4xf32>) -> tensor<4xf32> {
    %res = arith.addf %arg0, %arg1: tensor<4xf32>
    func.return %res: tensor<4xf32>
}