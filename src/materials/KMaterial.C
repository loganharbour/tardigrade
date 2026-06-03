#include "KMaterial.h"

registerMooseObject("TardigradeApp", KMaterial);

InputParameters
KMaterial::validParams()
{
  InputParameters params = Material::validParams();
  params.addParam<MaterialName>("k_name", "k", "The name of material property for k");
  params.addRequiredCoupledVar("variable", "The name of the variable whose gradient is in the denom");
  return params;
}

KMaterial::KMaterial(const InputParameters & parameters)
  : Material(parameters), _k(declareADProperty<Real>("k_name"))
{
}

void
KMaterial::computeQpProperties()
{
    _k[_qp] = 0;
}
