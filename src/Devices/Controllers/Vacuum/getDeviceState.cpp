// Vacuum/getRemoteState.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Vacuum Http API device class

#include "Devices/Controllers/Vacuum/Vacuum.h"

ParserResult Vacuum::getDeviceState(){
    log->info("Vacuum::getDeviceState()");
    try{
        const std::string json=getRemoteState();
        log->info("state: " + json);

        // SimpleJson parser(json);

        //ToDo: parse json and store state

    }catch(...){
        log->error("Thermostat device did not respond properly. Try again later.");
        std::cout << "Error: Cannot talk to thermostat." << std::endl;
        return ParserResult::error;
    }
    return ParserResult::ok;
}
