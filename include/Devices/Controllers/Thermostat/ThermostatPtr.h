// ThermostatPtr.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Define the two modes of a thermostat (heat|cool)

#ifndef THERMOSTAT_PTR_H
#define THERMOSTAT_PTR_H

#include <memory>

#ifndef THERMOSTAT_H
class Thermostat;  // Forward declare — no full class needed for unique_ptr
#endif

using ThermostatPtr = std::unique_ptr<Thermostat>;

#endif // THERMOSTAT_PTR_H
