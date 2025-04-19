
#include "Devices/Device/Device.h"

ParserResult Device::sendCommand(std::vector<std::string> &args) {
  log->info("Device::sendCommand() executed");
  return ParserResult::ok;
}
