// Thermostat/setTemp.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Thermostat Http API device class

#include "Devices/Controllers/Thermostat/Thermostat.h"
#include <stdexcept>

void Thermostat::setTemp(std::string &tempStr){
  log->info("setting temperature to " + tempStr);
  try {
    int t = std::stoi(tempStr);
    if (t < 0 || t > 100) {
      log->error("Temperature out of range: " + tempStr);
      return;
    }
    temperature = static_cast<unsigned short>(t);
    log->info("Thermostat setTemp: " + std::to_string(temperature));
  } catch (const std::exception& e) {
    log->error("Invalid temperature value: " + tempStr + " (" + e.what() + ")");
  }
}
