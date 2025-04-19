// Thermostat/setState.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Thermostat Http API device class

#include "Devices/Controllers/Thermostat/Thermostat.h"


const std::string to_string(bool fanState);
const std::string to_string(ThermostatMode modeState);

// receive command-line input for processing.
ParserResult Thermostat::sendCommand(std::vector<std::string> &args) {

    log->info("Thermostat::sendCommand start");

    int argc = args.size();

    // Understand what we are doing set|get and update internal state
    if (argc < 2){
        log->error("Thermostat::sendCommand: wrong number of arguments");
        return ParserResult::missingArgument;
    }

    if (args[1] == "set"){
        log->info("Thermostat::sendCommand: set");
        if (argc< 3){
            log->error("Thermostat::sendCommand: wrong number of arguments");
            return ParserResult::missingArgument;
        }
        if (args[2] == "temp"){
            if (argc < 4) {
              log->error("Thermostat::sendCommand: wrong number of arguments");
              return ParserResult::missingArgument;
            }
            log->info("Thermostat::sendCommand: temperature");
            setTemp(args[3]);

        } else if (args[2] == "fan"){
            if (argc < 4) return ParserResult::missingArgument;
            else if (args[3] == "on") fanOn();
            else if (args[3] == "off") fanOff();
            else return ParserResult::invalidArgument;

        } else if (args[2] == "mode") {
            if (argc < 4) return ParserResult::missingArgument;
            else if (args[3] == "cool") cool();
            else if (args[3] == "heat") heat();
            else return ParserResult::invalidArgument;

        } else {
          log->error("Thermostat::sendCommand: unknown command");
          return ParserResult::badCommand;
        }
        // Now that internal state is updated, call the API to update the state.
        return updateDeviceState();

    } else if ( args[1] == "get"){
        log->info("Thermostat::sendCommand: get");
        if (argc< 3){
            std::cout << "temp: "+std::to_string(temperature) << "\n"
                      << "fan:  "+ to_string(fanState) << "\n"
                      << "mode: "+ to_string(modeState) << "\n";
            return ParserResult::ok;
        }else{
            if (args[2] == "temp"){

            }else if (args[2] == "fan"){

            }else if (args[2] == "mode"){

            }else{
                log->error("Thermostat::sendCommand: unknown command");
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
