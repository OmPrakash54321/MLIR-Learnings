func.func @mlir_max(%arg0: tensor<2xf32>, %arg1: tensor<2xf32>) -> tensor<2xf32> {
    %maxten = arith.maximumf %arg0, %arg1: tensor<2xf32>
    func.return %maxten: tensor<2xf32>
}