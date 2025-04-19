// Thermostat/getTemp.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Thermostat Http API device class

#include "Devices/Controllers/Thermostat/Thermostat.h"

unsigned short Thermostat::getTemp() const {
    log->info("thermostat: temp = " + std::to_string(temperature));
    return temperature;
}
