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

    if (subCommand == "get"){

        //Update internal state from the device before we do anything.
        getDeviceState();
        std::cout << "armed: " << this->armedState.string() << std::endl;

    }else if (subCommand == "set"){
        if (argc < 3){
            log->error("Security::sendCommand: wrong number of arguments for a 'security set' command");
            return ParserResult::missingArgument;
        }
        const std::string subject = (argc>=3) ? to_lower(args[2]) : "";
        if (subject == "arm")
          armedState.on();
        else if (subject == "disarm")
          armedState.off();
        else
          return ParserResult::invalidArgument;
        // Now that internal state is updated, call the API to update the state.
        return updateDeviceState();
    }else{
      std::cout << "That makes no sense...try again." << std::endl;
      return ParserResult::badCommand;
    }
    std::cout << "I'm pretty sure that's illegal in this county." << std::endl;
    return ParserResult::badCommand;
}

