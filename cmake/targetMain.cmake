
# Main executable
add_executable(smart_home_exec src/main.cpp)
target_include_directories(smart_home_exec PRIVATE ${PROJECT_ROOT}/include)
target_sources(smart_home_exec PRIVATE
        src/utils/to_lower.cpp
        src/utils/getCurrentTimestamp.cpp
        src/utils/trim.cpp
        src/utils/getExecutableDir.cpp
        src/ParserResult/to_string.cpp
        src/Logger/error.cpp
        src/Logger/destructor.cpp
        src/Logger/constructor.cpp
        src/Logger/info.cpp
        src/Logger/fatal.cpp
        src/HttpClient/destructor.cpp
        src/HttpClient/constructor.cpp
        src/HttpClient/post.cpp
        src/HttpClient/get.cpp
        src/Devices/Device/GetState.cpp
        src/Devices/Device/sendCommand.cpp
        src/Devices/Device/constructor.cpp
        src/Devices/Device/setState.cpp
        src/Devices/Device/GetHealth.cpp
        src/Devices/WebEnabledDevice/getState.cpp
        src/Devices/WebEnabledDevice/destructor.cpp
        src/Devices/WebEnabledDevice/constructor.cpp
        src/Devices/WebEnabledDevice/setState.cpp
        src/Devices/WebEnabledDevice/getHealth.cpp
        src/Devices/Controllers/Thermostat/setTemp.cpp
        src/Devices/Controllers/Thermostat/getDeviceState.cpp
        src/Devices/Controllers/Thermostat/heat.cpp
        src/Devices/Controllers/Thermostat/sendCommand.cpp
        src/Devices/Controllers/Thermostat/constructor.cpp
        src/Devices/Controllers/Thermostat/getTemp.cpp
        src/Devices/Controllers/Thermostat/fanOn.cpp
        src/Devices/Controllers/Thermostat/cool.cpp
        src/Devices/Controllers/Thermostat/fanOff.cpp
        src/Devices/Controllers/Thermostat/updateDeviceState.cpp
        src/Devices/Factory/create.cpp
        src/CommandShell/destructor.cpp
        src/CommandShell/Run.cpp
        src/CommandShell/displayWelcome.cpp
        src/CommandShell/constructor.cpp
        src/CommandParser/invoke_device.cpp
        src/CommandParser/parse.cpp
        src/CommandParser/tokenize.cpp
        src/CommandParser/destructor.cpp
        src/CommandParser/constructor.cpp
        src/CommandType/identifyCommand.cpp
        src/Help/showHelp.cpp
        src/Help/getSmartRemark.cpp
)
