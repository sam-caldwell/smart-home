# cmake/ZipSubmission.cmake
# Author: Sam Caldwell
# Description: Adds a target to zip the full project directory for submission.

add_custom_target(zip_submission
        COMMENT "Zipping the entire project directory into submission.zip..."
        COMMAND ${CMAKE_COMMAND} -E echo "Creating submission.zip from ${CMAKE_SOURCE_DIR}"
        COMMAND ${CMAKE_COMMAND} -E remove -f ${CMAKE_SOURCE_DIR}/build/submission.zip
        COMMAND zip -r build/submission.zip . -x "*/build/*" -x "*.DS_Store"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        VERBATIM
)
