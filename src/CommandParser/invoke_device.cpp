// CommandParser/invoke_device.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Parses CLI input strings into actionable command tokens
// Dependencies: <string>, <vector>, <unordered_map>, Logger

#include "CommandParser/CommandParser.h"

ParserResult CommandParser::invoke_device(DeviceMap devices, CommandType cmd, Tokens &args) {
    if (devices.count(cmd)) {
        return devices.at(cmd)->sendCommand(args);
    } else {
        throw std::runtime_error("device controller (" + to_string(cmd) + ") not found");
    }

    return ParserResult::badCommand;
}
