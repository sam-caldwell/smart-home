// ThermostatMode.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Define the two modes of a thermostat (heat|cool)
// Changes: Initial version created for smart home automation project

#ifndef THERMOSTAT_MODE_H
#define THERMOSTAT_MODE_H
#include <stdexcept>
#include "utils/StringUtils.h"

enum ThermostatMode {
  cool,
  heat,
};

ThermostatMode to_thermostat_mode(const std::string& inp);

const std::string to_string(ThermostatMode modeState);

#endif //THERMOSTAT_MODE_H
