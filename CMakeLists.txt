cmake_minimum_required(VERSION 3.27)
project(smart-home)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)
set(PROJECT_ROOT ${CMAKE_SOURCE_DIR})

# Custom CMake modules
list(APPEND CMAKE_MODULE_PATH "${PROJECT_ROOT}/cmake")
include(GetHostIP)
include(PrintHostIP)
include(Mockery)
include(ZipSubmission)
include(GenerateFileTree)
include(include_directories)
include(targetMain)
# Disable test project for now
include(targetTest)
include(linkCurl)

# Ensure the file tree is generated before zipping
add_dependencies(zip_submission generate_file_tree)

include(Builder)
