// CommandParser/parse.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of the CommandParser logic

#include "utils/Tokens.h"
#include "CommandParser/CommandParser.h"

// Parse command-line inputs and execute the result
ParserResult CommandParser::parse(const std::string &inputRaw) {
    //strip the commandline string and make it case insensitive
    std::string input = to_lower(trim(inputRaw));

    // bail if empty
    if (input.empty()) return ParserResult::emptyCommand;

    // tokenize and bail if empty tokens (unusual)
    Tokens tokens = tokenize(input);
    if (tokens.empty())
        return ParserResult::emptyCommand; // no work to be performed here...

    // get the first token.  This is our command
    switch (const CommandType command = identifyCommand(tokens.pop())) {

        case CommandType::Lights: //fall through
        case CommandType::Security: //fall through
        case CommandType::Television: //fall through
        case CommandType::Thermostat: //fall through
        // ToDo: add more devices here
        case CommandType::Vacuum:
            return invoke_device(devices, command, tokens);

        case CommandType::Exit:
            return ParserResult::exitCommand;

        case CommandType::Help:
            showHelp();
            log->info("Help requested.");
            return ParserResult::ok;

        case CommandType::TicTacToe:
            std::cout << "Wouldn't you prefer a nice game of chess?" << std::endl;
            log->info("TicTacToe requested.");
            return ParserResult::ok;

        case CommandType::Unknown:
            log->error("Unknown command: " + command);
            return ParserResult::badCommand;
        default:
            log->error("Bad or unrecognized command: " + command);
            return ParserResult::badCommand;
    }
    //ToDo: add more parser logic.
}
