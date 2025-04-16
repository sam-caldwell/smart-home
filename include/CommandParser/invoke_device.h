// CommandParser/invoke_device.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Parses CLI input strings into actionable command tokens
// Dependencies: <string>, <vector>, <unordered_map>, Logger

#ifndef INVOKE_DEVICE_H
#define INVOKE_DEVICE_H

#include "CommandParser.h"

ParserResult invoke_device(
    DeviceMap *devices,
    CommandType cmd,
    std::vector<std::string> &args);

#endif //INVOKE_DEVICE_H
