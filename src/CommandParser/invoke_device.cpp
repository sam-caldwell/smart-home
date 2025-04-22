// CommandParser/invoke_device.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Parses CLI input strings into actionable command tokens
// Dependencies: <string>, <vector>, <unordered_map>, Logger

#include "utils/Tokens.h"
#include "CommandParser/CommandParser.h"

ParserResult CommandParser::invoke_device(DeviceMap devices, CommandType command, Tokens &args) {
    if (devices.contains(command)) {
        return devices.at(command)->sendCommand(args);
    } else {
        throw std::runtime_error("device controller (" + to_string(command) + ") not found");
    }

    return ParserResult::badCommand;
}
