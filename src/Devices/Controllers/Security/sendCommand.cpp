// Security/sendCommand.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Security Http API device class

#include "Devices/Controllers/Security/Security.h"

// receive command-line input for processing.
ParserResult Security::sendCommand(std::vector<std::string> &args) {

    log->info("Security::sendCommand start");

    int argc = args.size();

    if (argc < 2){
        log->error("Security::sendCommand: wrong number of arguments");
        return ParserResult::missingArgument;
    }

    const std::string subCommand = to_lower(args[1]); //set|get

    //Update internal state from the device before we do anything. Bail on error
    if (this->getDeviceState() != ParserResult::ok)
        return ParserResult::ok; //Bail.  We've already said something to the user.  swallow the error

    if (subCommand == "get"){
        std::cout << "armed: " << this->armedState.string() << std::endl;
        return ParserResult::ok;
    } else {
        if (subCommand == "arm")
            armedState.on();
        else if (subCommand == "disarm")
            armedState.off();
        else
          return ParserResult::invalidArgument;
            // Now that internal state is updated, call the API to update the state.
        return updateDeviceState();
    }
    std::cout << "I'm pretty sure that's illegal in this county." << std::endl;
    return ParserResult::badCommand;
}

