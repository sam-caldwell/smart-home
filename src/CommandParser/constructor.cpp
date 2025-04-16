// CommandParser/constructor.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of the CommandParser logic

#include "CommandParser/CommandParser.h"

CommandParser::CommandParser(Logger* log) : log(log) {
	const std::unordered_map<CommandType, std::string> endpoints = {
    	{CommandType::Thermostat, "http://127.0.0.1:8004"},
    	// {CommandType::Lights, "http://127.0.0.1:8002"},
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

