// File: showHelp.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: facilitate help by defining a function to print the help screen.

#include "Help.h"

void showHelp(){
    std::cout << "Commands:\n"
              << " exit|quit - terminate program\n"
              << " help|?    - show this screen\n"
              << "\n"
              << getSmartRemark() << "\n"
              << std::endl;

    // Todo: add more help content here
};
