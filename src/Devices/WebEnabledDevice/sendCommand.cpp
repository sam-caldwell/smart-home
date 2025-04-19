
#include "Devices/WebEnabledDevice/WebEnabledDevice.h"

ParserResult Device::sendCommand(std::vector<std::string> &args) {
  log->info("WebEnabledDevice::sendCommand() executed");
  return ParserResult::ok;
}
