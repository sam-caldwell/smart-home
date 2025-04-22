/**
 * @file CommandType/identifyCommand.cpp
 * @author Sam Caldwell
 * @brief Enum class for valid smart home CLI command categories
 * @version 1.0 - Initial stub created for testing integration.
 */

#include "CommandType/CommandType.h"

// Lookup a command in our table and return the CommandType token
CommandType identifyCommand(Token &token) {
    constexpr CommandMap commandMap {
                {"exit", CommandType::Exit},
                {"quit", CommandType::Exit},
                {"?", CommandType::Help},
                {"help", CommandType::Help},
                {"thermostat", CommandType::Thermostat},
                {"lights",     CommandType::Lights},
                {"vacuum",     CommandType::Vacuum},
                {"television", CommandType::Television},
                {"security",   CommandType::Security},
                {"tic-tac-toe", CommandType::TicTacToe},
    };

    auto it = commandMap.find(token);
    return (it != commandMap.end())
               ? it->second
               : CommandType::Unknown;
}
