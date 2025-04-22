// Thermostat/sendCommand.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Thermostat Http API device class

#include "Devices/Controllers/Thermostat/Thermostat.h"

// receive command-line input for processing.
ParserResult Thermostat::sendCommand(Tokens &tokens) {
    log->info("Thermostat::sendCommand start");

    //Update internal state from the device before we do anything. Bail on error
    if (this->getDeviceState() == ParserResult::error)
        return ParserResult::ok;

    if (const std::string subCommand = tokens.pop(); subCommand == "set") {
        log->info("Thermostat::sendCommand: set");

        if (tokens.empty())
            return ParserResult::missingArgument;
        const std::string subject = tokens.pop();

        if (tokens.empty())
            return ParserResult::missingArgument;
        const std::string strValue = tokens.pop();

        if (subject == "temp")
            setTemp(strValue);
        else if (subject == "fan")
            if (strValue == "on")
                fanOn();
            else if (strValue == "off")
                fanOff();
            else return ParserResult::invalidArgument;
        else if (subject == "mode")
            if (strValue == "cool")
                cool();
            else if (strValue == "heat")
                heat();
            else {
                std::cout << "I'm not sure what you're trying to do. But we don't do that around here."
                        << std::endl;
                return ParserResult::badCommand;
            }
        else {
            std::cout << "You're not doing it right!" << std::endl;
            return ParserResult::badCommand;
        }
        // Now that internal state is updated, call the API to update the state.
        return updateDeviceState();
    } else if (subCommand == "get") {
        log->info("Thermostat::sendCommand: get");
        std::cout << "temp: " + std::to_string(temperature) << "\n"
                << "fan:  " + fanState.string() << "\n"
                << "mode: " + to_string(modeState) << std::endl;
        return ParserResult::ok;
    }
    std::cout << "I'm pretty sure that's illegal in this county." << std::endl;
    return ParserResult::badCommand;
}
