// Thermostat/heat.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Thermostat Http API device class

#include <Devices/Controllers/Thermostat/Thermostat.h>

void Thermostat::heat(){
    modeState=ThermostatMode::heat;
}
