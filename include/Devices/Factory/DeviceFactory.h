// DeviceFactory.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Factory for constructing smart home device instances by CommandType and endpoint
// Changes: Initial version created for smart home automation project

#ifndef DEVICE_FACTORY_H
#define DEVICE_FACTORY_H

#include <memory>
#include <string>
#include "Devices/Device/Device.h"
#include "CommandType/CommandType.h"

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
