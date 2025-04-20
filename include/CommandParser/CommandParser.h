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

#include "Logger/Logger.h"
#include "utils/StringUtils.h"
#include "utils/getHostIp.h"
#include "utils/getPort.h"
#include <Help/Help.h>
#include "CommandType/CommandType.h"
#include "ParserResult/ParserResult.h"
#include "Devices/Controllers/Thermostat/Thermostat.h"
#include "Devices/Device/Device.h"
#include "Devices/WebEnabledDevice/WebEnabledDevice.h"
#include "Devices/Factory/DeviceFactory.h"


using TokenList = std::vector<std::string>;

class CommandParser {
public:
    explicit CommandParser(Logger *log);

    ~CommandParser();

    ParserResult parse(const std::string &input);

    using CommandArgs = std::vector<std::string>;

private:
    Logger *log;

    // convert string into space-delimited tokens
    TokenList tokenize(const std::string &input);

    // safely invoke device controller
    ParserResult invoke_device(DeviceMap devices, CommandType cmd, CommandArgs &args);

    // Map CommandType to device instance
    DeviceMap devices;
};

#endif // COMMAND_PARSER_H
