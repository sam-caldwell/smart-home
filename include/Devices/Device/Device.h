// Device.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: This is the base class for all devices

#ifndef DEVICE_H
#define DEVICE_H

#include "Logger/Logger.h"
#include "ParserResult/ParserResult.h"
#include "CommandType/CommandType.h"

class Device {
public:

  Device(Logger *log);

  ~Device()=default;

  //process device-specific commands
  virtual ParserResult sendCommand(std::vector<std::string> &args);

protected:

  // check device health
  void getHealth();

  // get the remote device state and update internal state
  virtual const std::string getRemoteState();

  // update the remote device state
  void setState(const std::string &body);

  Logger *log;
};

// Alias for mapping commands to smart device instances
using DevicePtr = Device*;

using DeviceMap = std::unordered_map<CommandType, DevicePtr>;


#endif //DEVICE_H
