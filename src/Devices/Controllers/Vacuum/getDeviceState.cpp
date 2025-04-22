// Vacuum/getRemoteState.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Vacuum Http API device class

#include "Devices/Controllers/Vacuum/Vacuum.h"

ParserResult Vacuum::getDeviceState(){
    log->info("Vacuum::getDeviceState()");
    try{
        const std::string json=getRemoteState();
        log->info("state: " + json);

        SimpleJson parser(json);

        {
            log->info("parsing run state");
            const std::string raw=parser.getString("active");
            this->runState.set(raw);
            log->info("runState: " + raw+ " stored as " + this->runState.string());
        }


    }catch(...){
        log->error("Vacuum device did not respond properly. Try again later.");
        std::cout << "Error: Cannot talk to Vacuum." << std::endl;
        return ParserResult::error;
    }
    return ParserResult::ok;
}
