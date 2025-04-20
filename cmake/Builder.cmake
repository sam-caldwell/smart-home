
# Custom build + test target
add_custom_target(build
    COMMAND echo "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}"
    COMMAND ${CMAKE_COMMAND} --build . --target smart_home_exec
    COMMENT "Building app"
    VERBATIM
)
