// Lights/sendCommand.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Lights Http API device class

#include "Devices/Controllers/Lights/Lights.h"

// receive command-line input for processing.
ParserResult Lights::sendCommand(std::vector<std::string> &args) {
    log->info("Lights::sendCommand start");

    int argc = args.size();
    const std::string subCommand = to_lower(args[1]); //set|get

    //Update internal state from the device before we do anything. Bail on error
    if (this->getDeviceState() != ParserResult::ok)
        return ParserResult::ok; //Bail.  We've already said something to the user.  swallow the error

    if (subCommand == "get") {
        for (const auto &[name, state] : *lights) {
            std::cout << name << " : " << state.string() << std::endl;
        }
        return ParserResult::ok;
    } else if (subCommand == "set") {
        if (argc == 3) {
            const std::string name = to_lower(args[2]);
            const std::string value = to_lower(args[3]);
            if (!exists(name)) {
                return ParserResult::invalidArgument;
            }
            if (value == "on")
                lights->at(value).on();
            else if (value == "off")
                lights->at(value).off();
            else
                return ParserResult::invalidArgument;
        } else {
            return ParserResult::invalidArgument;
        }
        return updateDeviceState();
    }
    std::cout << "I'm pretty sure that's illegal in this county." << std::endl;
    return ParserResult::badCommand;
}
