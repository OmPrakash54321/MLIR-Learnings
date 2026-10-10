func.func @print_tensor(%input0: tensor<4xf32>) -> ()  {
    my_dialect.print %input0: tensor<4xf32>
    return
}

func.func @all_ops_test(%input0: tensor<2x4xf32>, %input1: tensor<2x4xf32>) -> tensor<2x4xf32> {
    %sum = my_dialect.add %input0, %input1: tensor<2x4xf32>
    %act = my_dialect.relu %sum alpha 0.1 : tensor<2x4xf32>
    my_dialect.print %act: tensor<2x4xf32>

    func.return %act: tensor<2x4xf32>
}