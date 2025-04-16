// DeviceFactory.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Factory for constructing smart home device instances by CommandType and endpoint

#ifndef DEVICE_FACTORY_H
#define DEVICE_FACTORY_H

#include <memory>
#include <string>
#include "Devices/Devices/Devices.h"
#include "CommandType/CommandType.h"
#include "Devices/Controllers/Thermostat/Thermostat.h"
#include "Devices/Controllers/Thermostat/ThermostatPtr.h"

class DeviceFactory {
public:
    /**
     * @brief Factory method to create a smart device
     * @param type CommandType enum (Thermostat, Lights, etc.)
     * @param log Pointer to logger
     * @param endpoint HTTP endpoint for the device
     * @return DevicePtr (smart pointer to device)
     */
    static DevicePtr create(CommandType type, Logger* log, const std::string& endpoint);
};

#endif // DEVICE_FACTORY_H
