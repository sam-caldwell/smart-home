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

        {
            const std::string rawFan=parser.getString("fan");
            this->fanState.set(rawFan);
            log->info("fanState: " + rawFan+ " stored as " + this->fanState.string());
        }
        {
            const std::string rawMode = parser.getString("mode");
           this->modeState = to_thermostat_mode(rawMode);
            log->info("modeState: " + rawMode + " stored as " + to_string(this->modeState));
        }
        {
            const std::string rawTemp=parser.getString("temp");
            this->temperature = parser.getInt("temp");
            log->info("temp " + rawTemp + " stored as " + std::to_string(this->temperature));
        }

    }catch(...){
        log->error("Thermostat device did not respond properly. Try again later.");
        std::cout << "Error: Cannot talk to device." << std::endl;
        return ParserResult::error;
    }
    return ParserResult::ok;
}
