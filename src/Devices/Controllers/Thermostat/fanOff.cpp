
#include "Devices/Controllers/Thermostat/Thermostat.h"

void Thermostat::fanOff(){
  log->info("fanOff (was "+fanState.string() +")");
  fanState.off();
  log->info("fanState (is "+fanState.string() + ")");
}
