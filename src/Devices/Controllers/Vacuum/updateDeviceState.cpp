// Vacuum/updateDeviceState.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Security Http API device class

#include "Devices/Controllers/Vacuum/Vacuum.h"
#include <stdexcept>

ParserResult Vacuum::updateDeviceState(){
    SimpleJson json;
    json.set("active",runState.string());
    const std::string jsonString = json.stringify();
    log->info("sending update: "+jsonString);
    if (setRemoteState(jsonString))
        std::cout << "remote device updated" << std::endl;
    else
        std::cout << "we should add retry logic at least" << std::endl;

    return ParserResult::ok;
}
