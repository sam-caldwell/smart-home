// Security/updateDeviceState.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Security Http API device class

#include "Devices/Controllers/Security/Security.h"
#include <stdexcept>

ParserResult Security::updateDeviceState(){
    SimpleJson json;
    json.set("armed",armedState.string());
    json.set("sensitivity",2); //placeholder
    const std::string jsonString = json.stringify();
    log->info("sending update: "+jsonString);
    if (setRemoteState(jsonString))
        std::cout << "remote device updated ("+armedState.string()+")" << std::endl;
    else
        std::cout << "we should add retry logic at least" << std::endl;
    return ParserResult::ok;
}
