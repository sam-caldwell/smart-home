
# Test executable
add_executable(test_program test/main.cpp test/main.cpp)
target_include_directories(test_program PRIVATE ${PROJECT_ROOT}/include)
target_sources(test_program PRIVATE
        src/utils/toLower.cpp
        src/utils/getCurrentTimestamp.cpp
        src/utils/trim.cpp
        src/utils/getExecutableDir.cpp
        src/ParserResult/to_string.cpp
        src/Logger/error.cpp
        src/Logger/destructor.cpp
        src/Logger/constructor.cpp
        src/Logger/info.cpp
        src/Logger/fatal.cpp
)
