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

add_executable(build/program src/main.cpp)

