#include "fusion_fuel_cycleApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
fusion_fuel_cycleApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

fusion_fuel_cycleApp::fusion_fuel_cycleApp(InputParameters parameters) : MooseApp(parameters)
{
  fusion_fuel_cycleApp::registerAll(_factory, _action_factory, _syntax);
}

fusion_fuel_cycleApp::~fusion_fuel_cycleApp() {}

void
fusion_fuel_cycleApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<fusion_fuel_cycleApp>(f, af, s);
  Registry::registerObjectsTo(f, {"fusion_fuel_cycleApp"});
  Registry::registerActionsTo(af, {"fusion_fuel_cycleApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
fusion_fuel_cycleApp::registerApps()
{
  registerApp(fusion_fuel_cycleApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
fusion_fuel_cycleApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  fusion_fuel_cycleApp::registerAll(f, af, s);
}
extern "C" void
fusion_fuel_cycleApp__registerApps()
{
  fusion_fuel_cycleApp::registerApps();
}
