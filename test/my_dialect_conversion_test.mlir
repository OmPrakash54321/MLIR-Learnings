func.func @add_tensors(%arg0: tensor<4xf32>, %arg1: tensor<4xf32>) -> tensor<4xf32> {
    %res = my_dialect.add %arg0, %arg1: tensor<4xf32>
    func.return %res: tensor<4xf32>
}

func.func @relu_tensors_f(%arg0: tensor<4xf32>) -> tensor<4xf32> {
    %res = my_dialect.relu %arg0: tensor<4xf32>
    func.return %res: tensor<4xf32>
}

func.func @relu_tensors_i(%arg0: tensor<4xi32>) -> tensor<4xi32> {
    %res = my_dialect.relu %arg0: tensor<4xi32>
    func.return %res: tensor<4xi32>
}