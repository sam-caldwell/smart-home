// CommandParser/constructor.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of the CommandParser logic

#include "CommandParser/CommandParser.h"
#include <stdexcept>

CommandParser::CommandParser(Logger *log) : log(log) {
    const std::string baseUrl = "http://" + getHostIp();
    const std::unordered_map<CommandType, std::string> endpoints = {
        {CommandType::Lights, baseUrl + ":" + getPort("Lights")},
        {CommandType::Security, baseUrl + ":" + getPort("Security")},
        {CommandType::Television, baseUrl + ":" + getPort("Television")},
        {CommandType::Thermostat, baseUrl + ":" + getPort("Thermostat")},
        {CommandType::Vacuum, baseUrl + ":" + getPort("Vacuum")},
    };

    for (const auto &[type, endpoint]: endpoints) {
        if (auto device = DeviceFactory::create(type, log, endpoint)) {
            devices[type] = std::move(device);
        } else {
            throw std::runtime_error("Failed to initialize device for type " + to_string(type));
        }
    }
}
