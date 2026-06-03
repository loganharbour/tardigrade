//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "TardigradeTestApp.h"
#include "TardigradeApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
TardigradeTestApp::validParams()
{
  InputParameters params = TardigradeApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

TardigradeTestApp::TardigradeTestApp(const InputParameters & parameters) : MooseApp(parameters)
{
  TardigradeTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

TardigradeTestApp::~TardigradeTestApp() {}

void
TardigradeTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  TardigradeApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"TardigradeTestApp"});
    Registry::registerActionsTo(af, {"TardigradeTestApp"});
  }
}

void
TardigradeTestApp::registerApps()
{
  registerApp(TardigradeApp);
  registerApp(TardigradeTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
TardigradeTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  TardigradeTestApp::registerAll(f, af, s);
}
extern "C" void
TardigradeTestApp__registerApps()
{
  TardigradeTestApp::registerApps();
}
