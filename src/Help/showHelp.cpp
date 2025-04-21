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
              << " light <name> <on|off>           - turn on/off a specific light\n"
              << " light get                       - show current light state\n"
              << " security <arm|disarm>           - arm or disarm security\n"
              << " security get                    - show current security state\n"
              << " vacuum schedule <time>          - schedule a time for vacuum to run\n"
              << " vacuum cancel                   - cancel a current vacuum run\n"
              << " television <on|off>             - turn on/off the television\n"
              << " television set channel <int>    - set the television channel\n"
              << " television set volume <int>     - set the television volume\n"
              << "\n"
              << getSmartRemark() << "\n"
              << std::endl;

    // Todo: add more help content here
};
