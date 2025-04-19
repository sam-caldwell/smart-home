// Thermostat/getRemoteState.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Thermostat Http API device class

#include "Devices/Controllers/Thermostat/Thermostat.h"

ParserResult Thermostat::getDeviceState(){
    log->info("Thermostat::getDeviceState()");
    const std::string rawState = WebEnabledDevice::getRemoteState();
    log->info("state: " + rawState);
    return ParserResult::ok;
}
