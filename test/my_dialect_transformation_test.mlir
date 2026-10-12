func.func @test_fusion(%input0: tensor<2xf32>, %input1: tensor<2xf32>) -> tensor<2xf32> {
    %add = my_dialect.add %input0, %input1: tensor<2xf32>
    %relu = my_dialect.relu %add: tensor<2xf32>
    return %relu: tensor<2xf32>
}