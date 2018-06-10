include_directories("${MyProject_SOURCE_DIR}/include")

# Don't compile the main project if memory testing is enabled
# This is because malloc, free etc are overwritten by those of cmocka
# This is done to check for memory leaks and invallid free calls
if (NOT UNIT_TESTING_MEM)
    add_executable(TS-Status 
        main.c
        socket_at.c
        at.c
        )
endif (NOT UNIT_TESTING_MEM)
