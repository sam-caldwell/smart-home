# cmake/GenerateFileTree.cmake
# Author: Sam Caldwell
# Description: Generates a normalized file structure tree for documentation
# Changes: Initial version created for smart home automation project

add_custom_target(generate_file_tree
        COMMENT "Generating docs/file_structure.txt from project tree..."
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/docs
        COMMAND bash -c "tree --gitignore ${CMAKE_SOURCE_DIR} | sed 's/\\xC2\\xA0/ /g' > ${CMAKE_SOURCE_DIR}/docs/file_structure.md"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        VERBATIM
)
