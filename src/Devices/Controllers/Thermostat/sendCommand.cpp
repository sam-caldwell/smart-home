// Thermostat/setState.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Thermostat Http API device class

#include "Devices/Controllers/Thermostat/Thermostat.h"

// receive command-line input for processing.
ParserResult Thermostat::sendCommand(std::vector<std::string> &args) {
    int argc = args.size();
    // Understand what we are doing set|get and update internal state
    if (argc < 2)
        return ParserResult::missingArgument;

    if (args[1] == "set"){
        if (argc< 3)
            return ParserResult::missingArgument;
        if (args[2] == "temp"){
            if (argc < 4) return ParserResult::missingArgument;
            setTemp(args[3]);
        }
        if (args[2] == "fan"){
            if (argc < 4) return ParserResult::missingArgument;
            else if (args[3] == "on") fanOn();
            else if (args[3] == "off") fanOff();
            else return ParserResult::invalidArgument;
        }
        if (args[2] == "mode") {
            if (argc < 4) return ParserResult::missingArgument;
            else if (args[3] == "cool") cool();
            else if (args[3] == "heat") heat();
            else return ParserResult::invalidArgument;
        }
        // Now that internal state is updated, call the API to update the state.
        return updateDeviceState();
    }
    // we want to get the current device state
    if ( args[1] == "get"){
        return getDeviceState();
    }
    return ParserResult::error;
}
