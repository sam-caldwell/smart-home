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
        for (const auto &[name, state]: *lights) {
            std::cout << name << " : " << state.string() << std::endl;
        }
    } else {
        if (argc < 3)
            return ParserResult::invalidArgument;

        const std::string name = to_lower(args[1]);
        if (exists(name)) {
            log->info("light found: " + name);
        } else {
            log->error("light not found: " + name);
            std::cout << "light not found: " << name << std::endl;
            return ParserResult::badCommand;
        }

        const std::string value = to_lower(args[2]);
        if (value == "on")
            lights->at(name).on();
        else if (value == "off")
            lights->at(name).off();
        else {
            log->error("invalid light setting: '" + name + "'");
            std::cout << "lights can only be turned 'on' or 'off': " << name << std::endl;
            return ParserResult::badCommand;
        }
        log->info("light " + name + ": "+value);
        updateDeviceState();
    }
    return ParserResult::ok;
}
