// Security/getDeviceState.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Security Http API device class

#include "Devices/Controllers/Security/Security.h"

ParserResult Security::getDeviceState(){
    log->info("Security::getDeviceState()");
    try{
        const std::string json=getRemoteState();
        log->info("state: " + json);

        SimpleJson parser(json);

        {
            log->info("parsing fan state");
            const std::string raw=parser.getString("armed");
            this->armedState.set(raw);
            log->info("armedState: " + raw+ " stored as " + this->armedState.string());
        }

    }catch(...){
        log->error("Security device did not respond properly. Try again later.");
        std::cout << "Error: Cannot talk to Security device." << std::endl;
        return ParserResult::error;
    }
    return ParserResult::ok;
}
