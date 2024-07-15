//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "fusion_fuel_cycleTestApp.h"
#include "fusion_fuel_cycleApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
fusion_fuel_cycleTestApp::validParams()
{
  InputParameters params = fusion_fuel_cycleApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

fusion_fuel_cycleTestApp::fusion_fuel_cycleTestApp(InputParameters parameters) : MooseApp(parameters)
{
  fusion_fuel_cycleTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

fusion_fuel_cycleTestApp::~fusion_fuel_cycleTestApp() {}

void
fusion_fuel_cycleTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  fusion_fuel_cycleApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"fusion_fuel_cycleTestApp"});
    Registry::registerActionsTo(af, {"fusion_fuel_cycleTestApp"});
  }
}

void
fusion_fuel_cycleTestApp::registerApps()
{
  registerApp(fusion_fuel_cycleApp);
  registerApp(fusion_fuel_cycleTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
fusion_fuel_cycleTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  fusion_fuel_cycleTestApp::registerAll(f, af, s);
}
extern "C" void
fusion_fuel_cycleTestApp__registerApps()
{
  fusion_fuel_cycleTestApp::registerApps();
}
