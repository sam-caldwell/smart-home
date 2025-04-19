// Thermostat/setState.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Thermostat Http API device class

#include "Devices/Controllers/Thermostat/Thermostat.h"

#define COMMAND_SET (subCommand == "set")

const std::string to_string(bool fanState);
const std::string to_string(ThermostatMode modeState);

// receive command-line input for processing.
ParserResult Thermostat::sendCommand(std::vector<std::string> &args) {

    log->info("Thermostat::sendCommand start");

    int argc = args.size();

    if ((argc < 2) || (argc > 4)){
        log->error("Thermostat::sendCommand: wrong number of arguments");
        return ParserResult::missingArgument;
    }

    const std::string subCommand = to_lower(args[1]);
    const std::string subject = (argc>=3) ? to_lower(args[2]) : "";
    const std::string strValue = (argc==4) ? to_lower(args[3]) : "";

    if (subCommand == "set"){
        log->info("Thermostat::sendCommand: set");
        if (subject == "temp")
            if (strValue == "")
              return ParserResult::missingArgument;
            else
                setTemp(strValue);
        else if (subject == "fan")
            if (strValue == "")
              return ParserResult::missingArgument;
            else if (strValue == "on")
              fanOn();
            else if (strValue == "off")
              fanOff();
            else return ParserResult::invalidArgument;
        else if (subject == "mode")
            if (strValue == "")
              return ParserResult::missingArgument;
            else if (strValue == "cool")
              cool();
            else if (strValue == "heat")
              heat();
            else
              return ParserResult::invalidArgument;
        else
          return ParserResult::badCommand;
        // Now that internal state is updated, call the API to update the state.
        return updateDeviceState();

    } else if ( subCommand == "get") {
        log->info("Thermostat::sendCommand: get");
        if (argc< 3){
            std::cout << "temp: "+std::to_string(temperature) << "\n"
                      << "fan:  "+ to_string(fanState) << "\n"
                      << "mode: "+ to_string(modeState) << std::endl;
            return ParserResult::ok;
        } else {
            if (subject == "temp"){
              std::cout << "temp: "+std::to_string(temperature) << std::endl;
            }else if (subject == "fan"){
              std::cout << "fan: "+to_string(fanState) << std::endl;
            }else if (subject == "mode"){
              std::cout << "mode: "+to_string(modeState) << std::endl;
            }else{
                return ParserResult::badCommand;
            }
        }
    }
    return ParserResult::error;
}

const std::string to_string(bool fanState) {
    return fanState?"on":"off";
}

const std::string to_string(ThermostatMode modeState) {
    switch(modeState){
        case ThermostatMode::cool:
            return "cool";
        break;
        case ThermostatMode::heat:
            return "heat";
        break;
        default:
            return "unknown";
        break;
    }
}
