// CommandParser.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Parses CLI input strings into actionable command tokens
// Dependencies: <string>, <vector>, <unordered_map>, Logger

#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <new>
#include <exception>
#include <memory>

#include <Logger/Logger.h>
#include <utils/StringUtils.h>

#include <Help/Help.h>
#include <CommandParser/tokenize.h>
#include <CommandType/CommandType.h>
#include <ParserResult/ParserResult.h>
#include <Devices/Controllers/Thermostat/ThermostatPtr.h>
#include <Devices/Controllers/Thermostat/Thermostat.h>
#include <Devices/Devices/Devices.h>
#include <Devices/DeviceMap/DeviceMap.h>
#include <Devices/WebEnabledDevices/WebEnabledDevices.h>
#include <Devices/Factory/DeviceFactory.h>

class CommandParser {
public:
    explicit CommandParser(Logger* log);
    ~CommandParser() = default;
    ParserResult parse(const std::string& input);

private:
    Logger* log;

    // Map CommandType to device instance
    DeviceMap devices;
};

using CommandArgs = std::vector<std::string>;

// safely invoke device controller
ParserResult invoke_device(DeviceMap devices, CommandType cmd, CommandArgs &args);

#endif // COMMAND_PARSER_H

