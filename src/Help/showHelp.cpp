// File: showHelp.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: facilitate help by defining a function to print the help screen.

#include "Help/Help.h"

void showHelp(){
    std::cout << "Commands:\n"
              << " exit|quit                       - terminate program\n"
              << " help|?                          - show this screen\n"
              << " thermostat set fan <on|off>     - turn on/off fan\n"
              << " thermostat set mode <heat|cool> - set mode\n"
              << " thermostat set temp <number>    - set temperature\n"
              << " thermostat get                  - get current thermostat state\n"
              << "\n"
              << getSmartRemark() << "\n"
              << std::endl;

    // Todo: add more help content here
};
