// Thermostat/getRemoteState.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Thermostat Http API device class

#include "Devices/Controllers/Thermostat/Thermostat.h"

ParserResult Thermostat::getDeviceState(){
    log->info("Thermostat::getDeviceState()");
    try{
        const std::string json=getRemoteState();
        log->info("state: " + json);

        SimpleJson parser(json);

        fanState.set(parser.getString("fan"));
        modeState = to_thermostat_mode(parser.getString("mode"));
        int temp = parser.getInt("temp");

    }catch(...){
        log->error("Thermostat device did not respond properly. Try again later.");
        std::cout << "The device is drunk.  Call again later." << std::endl;
        return ParserResult::error;
    }
    return ParserResult::ok;
}
