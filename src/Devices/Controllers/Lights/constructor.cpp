// Lights/constructor.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Lights Http API device class

#include "Devices/Controllers/Lights/Lights.h"

Lights::Lights(Logger *log, const std::string &connstr): WebEnabledDevice(log, connstr), lights(new LightMap) {
    log->info("Lights system is registered (" + connstr + ")");
    getDeviceState();
};
