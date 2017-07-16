cmake_minimum_required(VERSION 3.2)
project(teamspeak-who-speaks-unit)

include(ExternalProject)
enable_testing()

get_filename_component(ROOT_PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR} DIRECTORY)

option(UNIT_TESTING_MEM "Test memory management (malloc, free etc)" ON)
option(RUN_TESTS_DURING_BUILD "Run the tests wile building them" ON)

# Configure header file
configure_file(
    "${ROOT_PROJECT_SOURCE_DIR}/include/config.h.in"
    "${PROJECT_BINARY_DIR}/include/config.h"
    )

configure_file(
    "${ROOT_PROJECT_SOURCE_DIR}/include/config_unit.h.in"
    "${PROJECT_BINARY_DIR}/include/config_unit.h"
    )

externalproject_add(
    project_cmocka
    PREFIX "${PROJECT_SOURCE_DIR}/cmocka"
    INSTALL_COMMAND ""
    GIT_REPOSITORY "git://git.cryptomilk.org/projects/cmocka.git"
)

ExternalProject_Get_Property(project_cmocka source_dir)
ExternalProject_Get_Property(project_cmocka binary_dir)

include_directories("${ROOT_PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_BINARY_DIR}/include")
include_directories("${source_dir}/include")

link_directories("${binary_dir}/src")
set(CMOCKA_LIBRARY cmocka)

# Add the unit tests
set(UNIT_TESTS
    test_linkedlist
    )

# Add the sources for the test, this is not done in the foreach loop because of
# dependencies. This would lead to a lot of exceptions.
add_executable(test_linkedlist
    "${ROOT_PROJECT_SOURCE_DIR}/src/linkedlist.c"
    unit/linkedlist/test_linkedlist.c
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
