/**
 * @file CommandShell/Run.cpp
 * @author Sam Caldwell
 * @brief CommandShell class for smart home automation.
 * @details Provides a command-driven interface. In this version, only the shell loop is implemented.
 * @dependencies Requires Logger, CommandParser, DeviceManager.
 * @version 1.0 - Initial stub created for testing integration.
 */

#include "CommandShell/CommandShell.h"

int CommandShell::Run() {
    //Fancy Prompt...
    // ToDo: we could even steal from my old ANSI colors library if we wanted to...and have time...
    // See https://github.com/sam-caldwell/monorepo/tree/main/cpp/common/AnsiColors
    //
    const std::string prompt = getCurrentTimestamp() + ">";

    // CommandParser doesn't need to be part of the class instance.
    // We only use it here.  KISS!
    CommandParser parser(log);

    // Display the welcome banner
    displayWelcome();

    while (true) {
        constexpr char space = ' ';
        // display the prompt
        std::cout << "\n" << space << prompt << space;

        // get the command line input
        std::string input;
        std::getline(std::cin, input);
        log->info("command (raw): '" + input + "'");

        // Parse the command-line and execute it, collect a result
        ParserResult result = parser.parse(input);
        log->info("Parsed command '" + input + "' result: '" + to_string(result) + "'");

        // evaluate the result...keep running or terminate?
        switch (result) {
            case ParserResult::exitCommand:
                return success; //Terminate
                break;

            case ParserResult::ok:
                break;

            case ParserResult::badCommand:
            case ParserResult::invalidArgument:
            case ParserResult::missingArgument:
                log->error("Missing argument.");
                std::cout << "Use ? or help for usage." << std::endl;
                break; //keep going

            case ParserResult::emptyCommand:
                log->error("No input provided.");
                break;

            default:
                // catch all because this should not happen...
                log->error("Unknown parser outcome (programmatic error)");
                return runtime_error;
                break;
        }
    }
    return 0;
}
