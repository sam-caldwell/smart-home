// Television/sendCommand.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Television Http API device class

#include "Devices/Controllers/Television/Television.h"

// receive command-line input for processing.
ParserResult Television::sendCommand(Tokens &args) {
    log->info("Lights::sendCommand start");

    int argc = args.size();

    //Update internal state from the device before we do anything. Bail on error
    if (this->getDeviceState() != ParserResult::ok)
        return ParserResult::ok; //Bail.  We've already said something to the user.  swallow the error

    if (argc < 2) {
        log->error("Television::sendCommand: wrong number of arguments");
        return ParserResult::missingArgument;
    }

    //Update internal state from the device before we do anything. Bail on error
    if (this->getDeviceState() == ParserResult::error)
        return ParserResult::ok;

    const std::string subCommand = to_lower(args[1]);

    if (subCommand == "get") {
        std::cout << "power: " << powerState.string() << "\n"
                << "volume: " << std::to_string(volumeState) << "\n"
                << "channel: " << std::to_string(channelState) << "\n"
                << std::endl;
        return ParserResult::ok;
    }
    if (subCommand == "on") {
        powerState.on();
        return updateDeviceState();
    }
    if (subCommand == "off") {
        powerState.off();
        return updateDeviceState();
    }
    if (subCommand == "set") {
        if (argc < 4) {
            log->error("Television::sendCommand: wrong number of arguments");
            return ParserResult::missingArgument;
        }
        const std::string subject = to_lower(args[2]);
        if (subject == "volume") {
            if (argc == 4)
                volume(args[3]);
        } else if (subject == "channel") {
            if (argc == 4)
                channel(args[3]);
        } else {
            log->error("Television::sendCommand: invalid subcommand");
            return ParserResult::badCommand;
        }
        //ToDo: look up the light by name in the map.  If it is in the map, set the value accordingly (on|off)
        //      if the light name is not in the map, return an error state.
        // Now that internal state is updated, call the API to update the state.
        return updateDeviceState();
    }
    std::cout << "I'm pretty sure that's illegal in this county." << std::endl;
    return ParserResult::badCommand;
}
