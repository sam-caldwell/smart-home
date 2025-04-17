// Device.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: This is the base class for all devices

#ifndef DEVICE_H
#define DEVICE_H

#include <Logger/Logger.h>
#include <ParserResult/ParserResult.h>
#include <CommandType/CommandType.h>

class Device {
public:
  Device(Logger *log);
  virtual ParserResult sendCommand(std::vector<std::string> &args);
protected:
  virtual void getHealth();
  virtual void getState();
  Logger *log;
};

// Alias for mapping commands to smart device instances
using DevicePtr = Device*;
using DeviceMap = std::unordered_map<CommandType, DevicePtr>;


#endif //DEVICE_H
