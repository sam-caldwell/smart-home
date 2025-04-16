// CommandParser.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of the CommandParser logic

#include "CommandParser.h"
#include "ThermostatPtr.h"
#include "Thermostat.h"
#include "DeviceFactory.h"

CommandParser::CommandParser(Logger* log) : log(log) {
	std::unordered_map<CommandType, std::string> endpoints = {
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

// Convert our input string to space-delimited tokens.
static std::vector<std::string> tokenize(const std::string& input) {
    std::vector<std::string> tokens;
    std::istringstream stream(input);
    std::string token;
    while (stream >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

// safely invoke the device controller
ParserResult invoke_device(
    DeviceMap *devices,
    CommandType cmd,
    std::vector<std::string> &args){

    if (devices->count(cmd)) {
        return devices->at(cmd)->sendCommand(args);
    } else {
        throw std::runtime_error("device controller not found");
    }
    return ParserResult::badCommand;
}

// Parse command-line inputs and execute the result
ParserResult CommandParser::parse(const std::string& inputRaw) {
    //strip the commandline string and make it case insensitive
    std::string input = toLower(trim(inputRaw));

    // bail if empty
    if (input.empty()) return ParserResult::emptyCommand;

    // tokenize and bail if empty tokens (unusual)
    std::vector<std::string> tokens = tokenize(input);
    if (tokens.empty())
        return ParserResult::emptyCommand;

    // identify the tokens
    CommandType type = identifyCommand(tokens[0]);
    switch(type) {
    case CommandType::Exit:
		return ParserResult::exitCommand;

    case CommandType::Thermostat:
      log->info("Thermostat");
      return invoke_device(devices, type, tokens);

    case CommandType::Lights:
      //ToDo: execute Lights
      log->info("Thermostat");
      return ParserResult::ok;

    case CommandType::Vacuum:
      //ToDo: execute Vacuum
      log->info("Thermostat");
      return ParserResult::ok;

    case CommandType::Television:
      //ToDo: execute Television
      log->info("Thermostat");
      return ParserResult::ok;

    case CommandType::Security:
      //ToDo: execute Security
      log->info("Thermostat");
      return ParserResult::ok;

    case CommandType::Help:
    	showHelp();
    	log->info("Help requested.");
        return ParserResult::ok;

    case CommandType::Unknown:
    	//fall through
    default:
        log->error("Unknown command: " + tokens[0]);
        return ParserResult::badCommand;
	}
    //ToDo: add more parser logic.

}
