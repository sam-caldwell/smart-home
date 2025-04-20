// Thermostat/updateDeviceState.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Thermostat Http API device class

#include "Devices/Controllers/Thermostat/Thermostat.h"
#include <stdexcept>

ParserResult Thermostat::updateDeviceState(){
    log->info("Thermostat::updateDeviceState() not implemented yet");
    //
    // ToDo: craft the json string with the update
    //       send the state to the server.
    //
    return ParserResult::ok;
}
