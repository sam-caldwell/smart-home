// CommandType.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Enum class for valid smart home CLI command categories

#ifndef COMMAND_TYPE_H
#define COMMAND_TYPE_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

enum CommandType {
    Exit,
    Help,
    Thermostat,
    Lights,
    Vacuum,
    Television,
    Security,
    Unknown
};

CommandType identifyCommand(const std::string& cmd);

#endif // COMMAND_TYPE_H
