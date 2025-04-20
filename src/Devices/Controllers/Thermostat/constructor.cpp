// Thermostat/constructor.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Thermostat Http API device class

#include "Devices/Controllers/Thermostat/Thermostat.h"

Thermostat::Thermostat(Logger *log, const std::string &connstr)
    : WebEnabledDevice(log, connstr),
      temperature(72),
      modeState(ThermostatMode::cool) {
    log->info("Thermostat is registered (" + connstr + ")");
    getDeviceState();
};
