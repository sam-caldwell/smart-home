
#include "Devices/Device/Device.h"

ParserResult Device::sendCommand(Tokens &args) {
  log->info("Device::sendCommand() executed");
  return ParserResult::ok;
}
