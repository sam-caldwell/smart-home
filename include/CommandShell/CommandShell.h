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

#include "Logger.h"
#include "exit_codes.h"
#include "getCurrentTimestamp.h"
#include "StringUtils.h"
#include "ParserResult.h"
#include "CommandParser.h"
#include "CommandShell.h"
#include "CommandType.h"

class CommandShell {
public:
    // Constructor and Destructor
    CommandShell(Logger *log) : log(log){};
    ~CommandShell(){};

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
