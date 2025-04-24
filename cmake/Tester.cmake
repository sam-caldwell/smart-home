# cmake/Tester.cmake
# Author: Sam Caldwell
# Description: cbuild tests and run tests

add_custom_target(build_tests
        COMMAND ${CMAKE_COMMAND} --build . --target test_program
        VERBATIM
)

add_custom_target(run_test
        COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test_program
        VERBATIM
)
