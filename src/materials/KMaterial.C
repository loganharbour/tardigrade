#include "KMaterial.h"

registerMooseObject("TardigradeApp", KMaterial);

InputParameters
KMaterial::validParams()
{
  InputParameters params = Material::validParams();
  return params;
}

KMaterial::KMaterial(const InputParameters & parameters)
  : Material(parameters)
{
}

void
KMaterial::computeQpProperties()
{
}
