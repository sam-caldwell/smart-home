
#include "Devices/Controllers/Thermostat/Thermostat.h"

void Thermostat::fanOff(){
  log->info("fanOff");
  fanState.off();
}
