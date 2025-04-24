// fanOff.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Turn off the fan
#include "Devices/Controllers/Thermostat/Thermostat.h"

void Thermostat::fanOff(){
  log->info("fanOff (was "+fanState.string() +")");
  fanState.off();
  log->info("fanState (is "+fanState.string() + ")");
}
