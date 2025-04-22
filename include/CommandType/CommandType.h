// CommandType.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Enum class for valid smart home CLI command categories

#ifndef COMMAND_TYPE_H
#define COMMAND_TYPE_H

#include <iostream>
#include <map>
#include "utils/Token.h"

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

using CommandMap = std::map<Token, CommandType>;

CommandType identifyCommand(const Token& token);

const std::string to_string(CommandType type);


#endif // COMMAND_TYPE_H
