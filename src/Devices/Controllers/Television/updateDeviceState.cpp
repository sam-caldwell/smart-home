// Television/updateDeviceState.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Security Http API device class

#include "Devices/Controllers/Television/Television.h"
#include <stdexcept>

ParserResult Television::updateDeviceState(){
    SimpleJson json;
    // we have an internal state (map) representing the current state.
    const std::string jsonString = json.stringify();
    log->info("sending update: "+jsonString);
    if (setRemoteState(jsonString))
        std::cout << "remote device updated" << std::endl;
    else
        std::cout << "we should add retry logic at least" << std::endl;
    return ParserResult::ok;
}
