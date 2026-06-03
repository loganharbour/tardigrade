[Mesh/gmg]
  type = GeneratedMeshGenerator
  dim = 2
  nx = 10
  ny = 10
[]

[Variables/u]
[]

[Kernels]
  [diffusion]
    type = ADMatDiffusion
    variable = u
    diffusivity = 1
  []
[]

[Executioner]
  type = Steady
[]
