// Security/updateDeviceState.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Security Http API device class

#include "Devices/Controllers/Security/Security.h"
#include <stdexcept>

ParserResult Security::updateDeviceState(){
    SimpleJson json;
    json.set("armed",armedState.string());
    if (setRemoteState(json.stringify()))
        std::cout << "remote armedState updated" << std::endl;
    else
        std::cout << "we should add retry logic at least" << std::endl;
    return ParserResult::ok;
}
