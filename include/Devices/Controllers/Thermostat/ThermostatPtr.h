#ifndef THERMOSTAT_PTR_H
#define THERMOSTAT_PTR_H

#include <memory>

class Thermostat;  // Forward declare — no full class needed for unique_ptr

using ThermostatPtr = std::unique_ptr<Thermostat>;

#endif // THERMOSTAT_PTR_H
