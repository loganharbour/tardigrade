#include "TardigradeApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
TardigradeApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

TardigradeApp::TardigradeApp(const InputParameters & parameters) : MooseApp(parameters)
{
  TardigradeApp::registerAll(_factory, _action_factory, _syntax);
}

TardigradeApp::~TardigradeApp() {}

void
TardigradeApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<TardigradeApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"TardigradeApp"});
  Registry::registerActionsTo(af, {"TardigradeApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
TardigradeApp::registerApps()
{
  registerApp(TardigradeApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
TardigradeApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  TardigradeApp::registerAll(f, af, s);
}
extern "C" void
TardigradeApp__registerApps()
{
  TardigradeApp::registerApps();
}
