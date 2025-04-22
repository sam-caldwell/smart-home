// Vacuum/sendCommand.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Vacuum Http API device class

#include "Devices/Controllers/Vacuum/Vacuum.h"

// receive command-line input for processing.
ParserResult Vacuum::sendCommand(Tokens &tokens) {
    log->info("Lights::sendCommand start");

    //Update internal state from the device before we do anything. Bail on error
    if (this->getDeviceState() != ParserResult::ok)
        return ParserResult::ok; //Bail.  We've already said something to the user.  swallow the error

    if (const std::string subCommand = tokens.pop(); subCommand == "get") {
        std::cout << "running: " << runState.string() << std::endl;
        return ParserResult::ok;
    } else if (subCommand == "on") {
        runState.on();
    } else if (subCommand == "off") {
        runState.off();
    } else {
        std::cout << "unknown command: " << subCommand << std::endl;
        return ParserResult::missingArgument;
    }
    return updateDeviceState();
}
