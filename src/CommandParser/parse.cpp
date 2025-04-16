// CommandParser/parse.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of the CommandParser logic

#include "CommandParser.h"

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
