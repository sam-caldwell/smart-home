cmake_minimum_required(VERSION 3.27)
project(smart_home)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

set(PROJECT_ROOT ${CMAKE_SOURCE_DIR})

# Include custom CMake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(Mockery)
include(ZipSubmission)
include(GenerateFileTree)

# this ensures we generate a file tree before we zip the submission
add_dependencies(zip_submission generate_file_tree)

# project program
add_executable(smart-home src/main.cpp)

# test program
add_executable(test_program test/main.cpp)

# Simplify the build-test cycle.  Build first, run mockery then tests.
add_custom_target(build_and_test
        COMMAND ${CMAKE_COMMAND} --build . --target smart_home
        COMMAND ${CMAKE_COMMAND} --build . --target mockery
        COMMENT "Building app, launching mockery, then running tests..."
        VERBATIM
)