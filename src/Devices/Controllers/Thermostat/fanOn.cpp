
#include "Devices/Controllers/Thermostat/Thermostat.h"

void Thermostat::fanOn(){
  log->info("fanOn");
  fanState.on();
}
