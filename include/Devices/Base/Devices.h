// Devices.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: This is the base class for all devices

#ifndef DEVICES_H
#define DEVICES_H

#include "Logger/Logger.h"
#include "ParserResult/ParserResult.h"

class Devices {
public:
  Devices(Logger *log);
  virtual ParserResult sendCommand(std::vector<std::string> &args);
protected:
  virtual void getHealth();
  virtual void getState();
  Logger *log;
};

using DevicePtr = std::unique_ptr<Devices>;

#endif //DEVICES_H
