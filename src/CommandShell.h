// CommandShell.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Provides command-driven interface for smart home control
// Dependencies: CommandParser, DeviceManager
// Changes: Initial version created for smart home automation project

#ifndef COMMANDSHELL_H
#define COMMANDSHELL_H

#include <string>
#include <iostream>
#include <sstream>
#include "Logger.h"
#include "exit_codes.h"
#include "CommandParser.h"

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
