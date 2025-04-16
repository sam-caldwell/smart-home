// identifyCommand.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Enum class for valid smart home CLI command categories

#include "CommandType.h"

CommandType identifyCommand(const std::string& cmd) {
    static std::unordered_map<std::string, CommandType> commandMap {
                {"exit", CommandType::Exit},
                {"quit", CommandType::Exit},
                {"?", CommandType::Help},
                {"help", CommandType::Help},
                {"thermostat", CommandType::Thermostat},
                {"lights",     CommandType::Lights},
                {"vacuum",     CommandType::Vacuum},
                {"television", CommandType::Television},
                {"security",   CommandType::Security}
    };

    auto it = commandMap.find(cmd);
    return (it != commandMap.end())
               ? it->second
               : CommandType::Unknown;
}
