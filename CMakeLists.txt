cmake_minimum_required(VERSION 3.27)
project(smart-home)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

set(PROJECT_ROOT ${CMAKE_SOURCE_DIR})

# Custom CMake modules
list(APPEND CMAKE_MODULE_PATH "${PROJECT_ROOT}/cmake")
include(Mockery)
include(ZipSubmission)
include(GenerateFileTree)

# Include headers
include_directories(${PROJECT_ROOT}/include)

# Main executable
add_executable(smart_home_exec src/main.cpp)
target_include_directories(smart_home_exec PRIVATE ${PROJECT_ROOT}/include)

# Test executable
add_executable(test_program test/main.cpp)
target_include_directories(test_program PRIVATE ${PROJECT_ROOT}/include)

# Ensure the file tree is generated before zipping
add_dependencies(zip_submission generate_file_tree)

# Custom build + test target
add_custom_target(build_and_test
        COMMAND echo "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}"
        COMMAND ${CMAKE_COMMAND} --build . --target smart_home_exec
        COMMAND ${CMAKE_COMMAND} --build . --target mockery
        COMMAND ${CMAKE_COMMAND} --build . --target test_program
        COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test_program
        COMMENT "Building app, launching mockery, then running tests..."
        VERBATIM
)
