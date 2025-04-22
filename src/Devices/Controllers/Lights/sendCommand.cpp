// Lights/sendCommand.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Lights Http API device class

#include "Devices/Controllers/Lights/Lights.h"

// receive command-line input for processing.
ParserResult Lights::sendCommand(Tokens &tokens) {
    log->info("Lights::sendCommand start");

    //Update internal state from the device before we do anything. Bail on error
    if (this->getDeviceState() != ParserResult::ok)
        return ParserResult::ok; //Bail.  We've already said something to the user.  swallow the error

    if (const std::string subCommand = tokens.pop(); subCommand == "get") {
        //iterate over the state map and print the current state to stdout
        for (const auto &[name, state]: *lights) {
            std::cout << name << " : " << state.string() << std::endl;
        }
    } else {
        if (tokens.empty())
            return ParserResult::invalidArgument; // we expected a setting

        if (const std::string lightName = subCommand; exists(subCommand)) {
            const std::string setting = tokens.pop();
            if (setting == "on")
                lights->at(lightName).on();
            else if (setting == "off")
                lights->at(lightName).off();
            else {
                log->error("invalid light setting: '" + lightName + "'");
                std::cout << "lights can only be turned 'on' or 'off': " << lightName << std::endl;
                return ParserResult::badCommand;
            }
            log->info("light " + lightName + ": " + setting);
            updateDeviceState();
        } else {
            log->error("light not found: " + lightName);
            std::cout << "light not found: " << lightName << std::endl;
            return ParserResult::badCommand;
        }
    }
    return ParserResult::ok;
}
