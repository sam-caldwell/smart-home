// CommandParser.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Parses CLI input strings into actionable command tokens
// Dependencies: <string>, <vector>, <unordered_map>, Logger
// Changes: Initial version created for smart home automation project

#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <string>
#include <queue>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <new>
#include <exception>
#include <memory>
#include "utils/Tokens.h"
#include "Logger/Logger.h"
#include "utils/StringUtils.h"
#include "utils/getHostIp.h"
#include "utils/getPort.h"
#include "utils/Tokens.h"
#include "utils/RawCommandLine.h"
#include <Help/Help.h>
#include "CommandType/CommandType.h"
#include "ParserResult/ParserResult.h"
#include "Devices/Controllers/Thermostat/Thermostat.h"
#include "Devices/Device/Device.h"
#include "Devices/WebEnabledDevice/WebEnabledDevice.h"
#include "Devices/Factory/DeviceFactory.h"


class CommandParser {
public:
    explicit CommandParser(Logger *log);

    ~CommandParser();

    ParserResult parse(const RawCommandLine &input);

private:
    // convert string into space-delimited tokens
    Tokens tokenize(const RawCommandLine &input);

    // safely invoke device controller
    ParserResult invoke_device(DeviceMap devices, CommandType cmd, Tokens &args);

    // Map CommandType to device instance
    DeviceMap devices;

    Logger *log;
};

#endif // COMMAND_PARSER_H
