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
  [reaction]
    type = ADReaction
    variable = u
    rate = 1
  []
[]

[Materials]
  [k]
    type = KMaterial
  []
[]

[BCs]
  [neumann]
    type = ADNeumannBC
    boundary = "top right bottom left"
    variable = u
  []
[]

[Executioner]
  type = Steady
[]
