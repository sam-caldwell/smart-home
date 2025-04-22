// Television/sendCommand.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Television Http API device class

#include "Devices/Controllers/Television/Television.h"

// receive command-line input for processing.
ParserResult Television::sendCommand(Tokens &tokens) {
    log->info("Television::sendCommand start");

    //Update internal state from the device before we do anything. Bail on error
    if (this->getDeviceState() != ParserResult::ok)
        return ParserResult::ok; //Bail.  We've already said something to the user.  swallow the error

    if (const std::string subCommand = tokens.pop(); subCommand == "get") {
        std::cout << "power: " << powerState.string() << "\n"
                << "volume: " << std::to_string(volumeState) << "\n"
                << "channel: " << std::to_string(channelState) << "\n"
                << std::endl;
        return ParserResult::ok;
    } else if (subCommand == "on") {
        powerState.on();
        return updateDeviceState();
    } else if (subCommand == "off") {
        powerState.off();
        return updateDeviceState();
    } else if (subCommand == "set") {
        if (tokens.empty()){
            return ParserResult::missingArgument;
        }
        const std::string setting = tokens.pop();
        if (tokens.empty()){
            return ParserResult::missingArgument;
        }
        const std::string value = tokens.pop();
        if (setting == "volume") {
            volume(value);
        } else if (setting == "channel") {
            channel(value);
        }else {
            log->error("Television::sendCommand: invalid setting (use volume|channel)");
            return ParserResult::badCommand;
        }
        return updateDeviceState();
    }else {
        std::cout << "I'm pretty sure that's illegal in this county." << std::endl;
        return ParserResult::badCommand;
    }
}
