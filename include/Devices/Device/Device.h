// Device.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: This is the base class for all devices

#ifndef DEVICE_H
#define DEVICE_H

#include "utils/Tokens.h"
#include "Logger/Logger.h"
#include "ParserResult/ParserResult.h"
#include "CommandType/CommandType.h"

class Device {
public:
    Device(Logger *log);

    virtual ~Device() = default;

    //process device-specific commands
    virtual ParserResult sendCommand(Tokens &args);

protected:
    // check device health
    virtual void getHealth();
    // get the remote device state and update internal state
    virtual const std::string getRemoteState();
    // set the remote device state
    virtual const bool setRemoteState(const std::string &body);

    Logger *log;
};

// Alias for mapping commands to smart device instances
using DevicePtr = Device *;

using DeviceMap = std::unordered_map<CommandType, DevicePtr>;


#endif //DEVICE_H
