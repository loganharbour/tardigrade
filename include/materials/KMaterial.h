#pragma once

#include "Material.h"

class KMaterial : public Material
{
public:
  static InputParameters validParams();

  KMaterial(const InputParameters & parameters);

protected:
  virtual void computeQpProperties();
};
