
# Test executable
add_executable(test_program test/main.cpp ${SOURCE_FILES})
target_include_directories(test_program PRIVATE ${PROJECT_ROOT}/include)
