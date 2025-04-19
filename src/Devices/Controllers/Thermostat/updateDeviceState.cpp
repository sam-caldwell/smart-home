// Thermostat/updateDeviceState.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Thermostat Http API device class

#include "Devices/Controllers/Thermostat/Thermostat.h"
#include <exception>

bool onOff_toBool(std::string &inp);

ParserResult Thermostat::updateDeviceState(){
    log->info("Thermostat::updateDeviceState() not implemented yet");
    try{
        const std::string json=getRemoteDevice();
        SimpleJsonParser parser(json);

        fanState = onOff_toBool(parser.getString("fan")));
        fanState =

        std::string mode = parser.getString("mode");
        int temp = parser.getInt("temp");



    }catch(...){
        log->error("Thermostat device did not respond properly. Try again later.");
        std::cout << "The device is drunk.  Call again later." << std::endl;
        return ParserResult::error;
    }
    return ParserResult::ok;
}

bool onOff_toBool(std::string &inp){
    const std::string v = to_lower(inp);
    if (v == "on")
      return true;
    else if (v == "off")
      return false;
    else
      throw exception("expected on/off state");
}
