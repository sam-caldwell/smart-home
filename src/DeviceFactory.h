// DeviceFactory.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Factory for constructing smart home device instances by CommandType and endpoint

#ifndef DEVICE_FACTORY_H
#define DEVICE_FACTORY_H

#include "Devices.h"
#include "CommandType.h"

#include "Thermostat.h"
#include "ThermostatPtr.h"

#include <memory>
#include <string>

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
