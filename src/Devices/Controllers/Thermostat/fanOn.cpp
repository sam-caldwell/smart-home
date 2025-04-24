// fanOn.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Turn on the fan
#include "Devices/Controllers/Thermostat/Thermostat.h"

void Thermostat::fanOn(){
  log->info("fanOn (was "+fanState.string() +")");
  fanState.on();
  log->info("fanState (is "+fanState.string() + ")");
}
