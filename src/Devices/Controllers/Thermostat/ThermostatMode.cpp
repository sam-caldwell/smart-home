// ThermostatMode.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>

#include "Devices/Controllers/Thermostat/ThermostatMode.h"

ThermostatMode to_thermostat_mode(const std::string& inp) {
    std::string val = to_lower(trim(inp));

    if (val == "cool")
        return ThermostatMode::cool;
    else if (val == "heat")
        return ThermostatMode::heat;
    else
        throw std::invalid_argument("Invalid thermostat mode. Expected 'cool' or 'heat'.");
}

const std::string to_string(ThermostatMode modeState) {
    switch(modeState){
        case ThermostatMode::cool:
            return "cool";
        break;
        case ThermostatMode::heat:
            return "heat";
        break;
        default:
            return "unknown";
        break;
    }
}
