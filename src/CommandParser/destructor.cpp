// CommandParser/destructor.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: clean up device pointers and other things allocated

CommandParser::~CommandParser() {
    for (auto& [cmd, device] : deviceMap) {
        delete device;
        device = nullptr;
    }
    deviceMap.clear();
}
