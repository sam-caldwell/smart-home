// Thermostat/sendCommand.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Thermostat Http API device class

#include "Devices/Controllers/Thermostat/Thermostat.h"

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
            else {
              std::cout << "I'm not sure what you're trying to do. But we don't do that around here."
                        << std::endl;
              return ParserResult::badCommand;
            }
        else{
          std::cout << "You're not doing it right!" << std::endl;
          return ParserResult::badCommand;
        }
        // Now that internal state is updated, call the API to update the state.
        return updateDeviceState();

    } else if ( subCommand == "get") {
        //Update internal state from the device before we do anything.
        getDeviceState();

        log->info("Thermostat::sendCommand: get");
        if (argc< 3){
            std::cout << "temp: "+std::to_string(temperature) << "\n"
                      << "fan:  "+ fanState.string() << "\n"
                      << "mode: "+ to_string(modeState) << std::endl;
            return ParserResult::ok;
        } else {
            if (subject == "temp"){
              std::cout << "temp: "+std::to_string(temperature) << std::endl;
            }else if (subject == "fan"){
              std::cout << "fan: "+fanState.string() << std::endl;
            }else if (subject == "mode"){
              std::cout << "mode: "+to_string(modeState) << std::endl;
            }else{
                std::cout << "That's illegal in this county."
                          << std::endl;
                return ParserResult::badCommand;
            }
            return ParserResult::ok;
        }
    }
    std::cout << "I'm pretty sure that's illegal in this county." << std::endl;
    return ParserResult::badCommand;
}

