/**
* @file CommandType/to_string.cpp
 * @author Sam Caldwell
 * @brief Enum class for valid smart home CLI command categories
 * @version 1.0 - Initial stub created for testing integration.
 */
#include "CommandType/CommandType.h"

const std::string to_string(const CommandType type) {
    switch (type) {
        case CommandType::Exit:
            return "exit";
        case CommandType::Help:
            return "help";
        case CommandType::Thermostat:
            return "thermostat";
        case CommandType::Lights:
            return "lights";
        case CommandType::Vacuum:
            return "vacuum";
        case CommandType::TicTacToe:
            return "tic-tac-toe";
        case CommandType::Security:
            return "security";
        default:
            return "unknown command";
    }
}
