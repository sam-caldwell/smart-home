// Vacuum/sendCommand.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Vacuum Http API device class

#include "Devices/Controllers/Vacuum/Vacuum.h"

// receive command-line input for processing.
ParserResult Vacuum::sendCommand(std::vector<std::string> &args) {

    log->info("Lights::sendCommand start");

    int argc = args.size();

    const std::string subCommand = to_lower(args[1]); //set|get

    //Update internal state from the device before we do anything. Bail on error
    if (this->getDeviceState() != ParserResult::ok)
        return ParserResult::ok; //Bail.  We've already said something to the user.  swallow the error

    if (argc <2) {
        log->error("Television::sendCommand: wrong number of arguments");
        return ParserResult::missingArgument;
    }
    if (subCommand == "get"){
        std::cout << "running: " << runState.string() << std::endl;
        return ParserResult::ok;
    } else if (subCommand == "on") {
        runState.on();
        return updateDeviceState();
    }else if (subCommand == "off") {
        runState.off();
        return updateDeviceState();
    }else{
        std::cout << "unknown command: " << subCommand << std::endl;
        return ParserResult::missingArgument;
    }
    std::cout << "I don't know what you want to do. I'm pretty sure that's illegal in this county." << std::endl;
    return ParserResult::badCommand;
}

