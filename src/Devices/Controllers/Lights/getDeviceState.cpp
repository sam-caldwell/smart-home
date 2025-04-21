// Lights/getDeviceState.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Lights Http API device class

#include "Devices/Controllers/Lights/Lights.h"

ParserResult Lights::getDeviceState(){
    log->info("Lights::getDeviceState()");
    try{
        const std::string json=getRemoteState();
        log->info("state: " + json);

        SimpleJson parser(json);

        {
            log->info("parsing armed state (there's a spook joke in here somewhere)");
            //ToDo: parse and store state
        }

    }catch(...){
        log->error("Security device did not respond properly. Try again later.");
        std::cout << "Error: Cannot talk to Security device." << std::endl;
        return ParserResult::error;
    }
    return ParserResult::ok;
}
