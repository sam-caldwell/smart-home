// Thermostat/updateDeviceState.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Thermostat Http API device class

#include "Devices/Controllers/Thermostat/Thermostat.h"
#include <stdexcept>

ParserResult Thermostat::updateDeviceState(){
    SimpleJson json;
    json.set("temp",temperature);
    json.set("fan", fanState.string());
    json.set("mode", to_string(modeState));
    if (setRemoteState(json.stringify()))
        std::cout << "remote state updated" << std::endl;
    else
        std::cout << "we should add retry logic at least" << std::endl;
    return ParserResult::ok;
}
