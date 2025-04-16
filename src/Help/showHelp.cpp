// File: showHelp.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: facilitate help by defining a function to print the help screen.

#include "Help/Help.h"

void showHelp(){
    std::cout << "Commands:
"
              << " exit|quit - terminate program
"
              << " help|?    - show this screen
"
              << "
"
              << getSmartRemark() << "
"
              << std::endl;

    // Todo: add more help content here
};
