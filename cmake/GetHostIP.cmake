# cmake/GetHostIP.cmake
# Author: Sam Caldwell
# Description: Provide cmake function get_host_ip()

function(get_host_ip HOST_IP)
    if(UNIX AND NOT APPLE)
        # Linux: get IP from the first non-loopback interface
        execute_process(
                COMMAND bash -c "hostname -I | awk '{print $1}'"
                OUTPUT_VARIABLE IP_RAW
                OUTPUT_STRIP_TRAILING_WHITESPACE
        )
    elseif(APPLE)
        # macOS: get IP from en0 interface
        execute_process(
                COMMAND ipconfig getifaddr en0
                OUTPUT_VARIABLE IP_RAW
                OUTPUT_STRIP_TRAILING_WHITESPACE
        )
    elseif(WIN32)
        # Windows: use PowerShell to get IPv4 address
        execute_process(
                COMMAND powershell -Command "(Get-NetIPAddress -AddressFamily IPv4 -InterfaceAlias Ethernet* | Where-Object { $_.IPAddress -ne '127.0.0.1' }).IPAddress"
                OUTPUT_VARIABLE IP_RAW
                OUTPUT_STRIP_TRAILING_WHITESPACE
        )
    else()
        message(FATAL_ERROR "Unsupported platform for IP detection.")
    endif()

    if(IP_RAW STREQUAL "")
        message(WARNING "Failed to determine IP address.")
    endif()

    set(${HOST_IP} ${IP_RAW} PARENT_SCOPE)
endfunction()

get_host_ip(HOST_IP)
