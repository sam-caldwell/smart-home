# cmake/PrintHostIP.cmake
# Author: Sam Caldwell
# Description: Generates PrintHostIP

add_custom_target(PrintHostIP ALL
        COMMAND echo "HOST_IP=${HOST_IP}"
        VERBATIM
)
