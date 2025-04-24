// CommandType.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Enum class for valid smart home CLI command categories
// Changes: Initial version created for smart home automation project

#ifndef COMMAND_TYPE_H
#define COMMAND_TYPE_H

#include <iostream>
#include <map>

enum CommandType {
    Exit,
    Help,
    Thermostat,
    Lights,
    Vacuum,
    Television,
    Security,
    TicTacToe,
    Unknown
};

using Token = std::string;

using CommandMap = std::map<Token, CommandType>;

CommandType identifyCommand(const Token& token);

const std::string to_string(CommandType type);

#endif // COMMAND_TYPE_H
