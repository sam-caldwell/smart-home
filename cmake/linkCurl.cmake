
if(APPLE)

    target_link_libraries(smart_home_exec PRIVATE "-lcurl")

else()

    find_package(CURL REQUIRED)
    target_link_libraries(smart_home_exec PRIVATE CURL::libcurl)

endif()

