cmake_minimum_required(VERSION 3.27)
project(smart-home)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)
set(PROJECT_ROOT ${CMAKE_SOURCE_DIR})

option(FF_TEST_ENABLE "Enable test targets" OFF)


# Custom CMake modules
list(APPEND CMAKE_MODULE_PATH "${PROJECT_ROOT}/cmake")
include(GetHostIP)
include(PrintHostIP)
include(Mockery)
include(ZipSubmission)
include(GenerateFileTree)
include(include_directories)
include(targetMain)
if(${FF_TEST_ENABLE})
    message(STATUS "tests ON")
    include(targetTest)
    include(Tester)
else()
    message(STATUS "tests OFF")
endif()
include(linkCurl)

# Ensure the file tree is generated before zipping
add_dependencies(zip_submission generate_file_tree)

include(Builder)
