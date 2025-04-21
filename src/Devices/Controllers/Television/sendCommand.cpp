// Television/sendCommand.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Television Http API device class

#include "Devices/Controllers/Television/Television.h"

// receive command-line input for processing.
ParserResult Television::sendCommand(std::vector<std::string> &args) {

    log->info("Lights::sendCommand start");

    int argc = args.size();
    const std::string subCommand = to_lower(args[1]); //set|get

    //Update internal state from the device before we do anything. Bail on error
    if (this->getDeviceState() != ParserResult::ok)
        return ParserResult::ok; //Bail.  We've already said something to the user.  swallow the error

    if (subCommand == "get"){
        //ToDo: iterate over the map and display all lights and their state
        return ParserResult::ok;
    } else if (subCommand == "set"){
        //ToDo: look up the light by name in the map.  If it is in the map, set the value accordingly (on|off)
        //      if the light name is not in the map, return an error state.
        // Now that internal state is updated, call the API to update the state.
        return updateDeviceState();
    }
    std::cout << "I'm pretty sure that's illegal in this county." << std::endl;
    return ParserResult::badCommand;
}

