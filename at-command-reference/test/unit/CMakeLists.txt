include_directories("${PROJECT_SOURCE_DIR}/cmocka/include")

set(UNIT_TESTS
    test_linkedlist
    test_at
    test_ts3_serverquery
    )

# Add the sources for the test, this is not done in the foreach loop because of
# dependencies. This would lead to a lot of exceptions.
add_executable(test_linkedlist 
    "${PROJECT_SOURCE_DIR}/src/linkedlist.c" 
    linkedlist/test_linkedlist.c
    )

add_executable(test_at
    "${PROJECT_SOURCE_DIR}/src/at.c"
    at/test_at.c
    )

add_executable(test_ts3_serverquery
    "${PROJECT_SOURCE_DIR}/src/ts3_serverquery.c"
    "${PROJECT_SOURCE_DIR}/src/linkedlist.c" 
    ts3-serverquery/test_ts3_serverquery.c
    )

# Find cmocka TODO: Build cmake using ExternalProject
find_library(CMOCKA_LIBRARY
    NAMES libcmocka cmocka
    HINTS "${PROJECT_SOURCE_DIR}/cmocka/build/src/"
    )

# Add the test to cmake
# Add a custom command for executing the tests when building (depending on the option)
foreach(_UNIT_TEST ${UNIT_TESTS})
    target_link_libraries("${_UNIT_TEST}" ${CMOCKA_LIBRARY})

    add_test(NAME "${_UNIT_TEST}" COMMAND "${_UNIT_TEST}")

    if (${RUN_TESTS_DURING_BUILD})
        add_custom_command(TARGET "${_UNIT_TEST}" POST_BUILD COMMAND ${_UNIT_TEST})
    endif (${RUN_TESTS_DURING_BUILD})
endforeach()

