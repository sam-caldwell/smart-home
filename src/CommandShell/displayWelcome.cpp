/**
* @file CommandShell/displayWelcome.cpp
 * @author Sam Caldwell
 * @brief Display the commandshell banner
 * @version 1.0 - Initial stub created for testing integration.
 */

#include "CommandShell/CommandShell.h"

void CommandShell::displayWelcome() const {
    std::cout << "========================================
";
    std::cout << "     Smart Home Automation CLI Shell
";
    std::cout << "         Type 'exit' to quit
";
    std::cout << "========================================
";
}
