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
    diffusivity = k_name
  []
  [reaction]
    type = ADReaction
    variable = u
    rate = 1
  []
[]

[Materials]
  [k]
    type = KMaterial
    variable = u
    k_name = k
  []
[]

[BCs]
  [neumann]
    type = ADNeumannBC
    boundary = "top right bottom left"
    variable = u
    value = 0.2
  []
[]

[Executioner]
  type = Steady
[]

[Outputs]
  exodus = true
[]
