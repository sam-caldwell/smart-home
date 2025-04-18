// CommandParser/destructor.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: clean up device pointers and other things allocated

#include "CommandParser/CommandParser.h"

CommandParser::~CommandParser() {

    //Delete all devices in DeviceMap
    for (auto& [cmd, device] : devices) {
        delete device;
        device = nullptr;
    }
    devices.clear();
}
