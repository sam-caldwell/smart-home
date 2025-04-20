// CommandParser/constructor.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of the CommandParser logic

#include "CommandParser/CommandParser.h"

CommandParser::CommandParser(Logger* log) : log(log) {

    const std::string baseUrl = "http://"+getHostIp();
    const std::unordered_map<CommandType, std::string> endpoints = {
        // {CommandType::Lights, baseUrl+getPort("Lights")},
        // {CommandType::Security, baseUrl+getPort("Security")},
        // {CommandType::Television, baseUrl+getPort("Television")},
        {CommandType::Thermostat, baseUrl+getPort("Thermostat")},
        // {CommandType::Vacuum, baseUrl+getPort("Vacuum")},
    };

    for (const auto& [type, endpoint] : endpoints) {
        auto device = DeviceFactory::create(type, log, endpoint);
        if (device) {
            devices[type] = std::move(device);
        } else {
            log->error("Failed to initialize device for type " + std::to_string(static_cast<int>(type)));
        }
    }
}

