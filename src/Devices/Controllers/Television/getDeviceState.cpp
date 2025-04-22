// Television/getDeviceState.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Television Http API device class

#include "Devices/Controllers/Television/Television.h"

ParserResult Television::getDeviceState(){
    log->info("Television::getDeviceState()");
    try{
        const std::string json=getRemoteState();
        log->info("state: " + json);

        SimpleJson parser(json);

        {
            log->info("parsing power state");
            const std::string raw=parser.getString("power");
            this->powerState.set(raw);
            log->info("powerState: " + raw+ " stored as " + this->powerState.string());
        }

        {
            log->info("parsing channel");
            const std::string raw=parser.getString("channel");
            this->channel(raw);
            log->info("channelState: " + raw+ " stored as " + std::to_string(this->channelState));
        }

        {
            log->info("parsing volume");
            const std::string raw=parser.getString("volume");
            this->volume(raw);
            log->info("volumeState: " + raw+ " stored as " + std::to_string(this->volumeState));
        }

    }catch(...){
        log->error("Television device did not respond properly. Try again later.");
        std::cout << "Error: Cannot talk to Television device." << std::endl;
        return ParserResult::error;
    }
    return ParserResult::ok;
}
