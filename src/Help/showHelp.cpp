// File: showHelp.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: facilitate help by defining a function to print the help screen.

#include "Help/Help.h"

void showHelp(){
    std::cout << "Commands:\n"
              << " exit|quit                       - terminate program\n"
              << " help|?                          - show this screen\n"
              << " lights <name> <on|off>          - turn on/off a specific light\n"
              << " lights get                      - show current light state\n"
              << " television <on|off>             - turn on/off the television\n"
              << " television set channel <int>    - set the television channel\n"
              << " television set volume <int>     - set the television volume\n"
              << " thermostat set fan <on|off>     - turn on/off fan\n"
              << " thermostat set mode <heat|cool> - set mode\n"
              << " thermostat set temp <number>    - set temperature\n"
              << " thermostat get                  - get current thermostat state\n"
              << " security get                    - show current security state\n"
              << " security <arm|disarm>           - arm or disarm security\n"
              << " vacuum get                      - get vacuum state\n"
              << " vacuum on                       - start vacuum run\n"
              << " vacuum of                       - stop vacuum run\n"
              << "\n"
              << getSmartRemark() << "\n"
              << std::endl;
};
