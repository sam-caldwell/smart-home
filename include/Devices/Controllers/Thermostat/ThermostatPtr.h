// ThermostatPtr.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Define the two modes of a thermostat (heat|cool)

#pragma once
#include <memory>

class Thermostat;  // Forward declaration (global namespace)

using ThermostatPtr = std::unique_ptr<Thermostat>;
