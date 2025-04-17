// CommandShell.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Provides command-driven interface for smart home control
// Dependencies: CommandParser, DeviceManager
// Changes: Initial version created for smart home automation project

#ifndef COMMANDSHELL_H
#define COMMANDSHELL_H

#include <algorithm>
#include <cctype>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>

#include <Logger/Logger.h>
#include <constants/exit_codes.h>
#include <utils/getCurrentTimestamp.h>
#include <utils/StringUtils.h>
#include <ParserResult/ParserResult.h>

#include <CommandParser/CommandParser.h>
#include <CommandType/CommandType.h>

class CommandShell {
public:
    // Constructor and Destructor
    CommandShell(Logger *log);
    ~CommandShell();

    /**
     * @brief Runs the interactive command-line shell
     * @return 0 if successful, non-zero if an error occurs
     */
    int Run();

private:
    Logger *log;
    //DeviceManager deviceManager;
    //CommandParser commandParser;

    /**
     * @brief Displays the welcome banner
     */
    void displayWelcome() const;
};

#endif // COMMANDSHELL_H
