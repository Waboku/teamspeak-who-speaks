cmake_minimum_required(VERSION 3.0)
project(TS-Status)

option(UNIT_TESTING "Build test code" ON)
option(UNIT_TESTING_MEM "Test memory management (malloc, free etc)" OFF)
option(RUN_TESTS_DURING_BUILD "Run the tests wile building them" OFF)
option(AT_SOCKET "Use AT command based sockets" ON)

set(TS_SERVERQUERY_PW "default_pass" CACHE STRING "TeamSpeak ServerQuery password")

# Set the default C Flags
set(CMAKE_C_FLAGS
    "${CMAKE_C_FLAGS}           \
    -Wall                       \
    -Wpointer-arith"  
    )

# Set the aditional debug C Flags
set(CMAKE_C_FLAGS_DEBUG
    "${CMAKE_C_FLAGS_DEBUG}     \
    ${CMAKE_C_FLAGS}"
    )

# Set the aditional release C Flags
set(CMAKE_C_FLAGS_DEBUG
    "${CMAKE_C_FLAGS_RELEASE}     \
    ${CMAKE_C_FLAGS}"
    )

# Set the compiler flags for normal and debug mode
if (CMAKE_BUILD_TYPE MATCHES Debug)
    message("Debug build")
elseif (CMAKE_BUILD_TYPE MATCHES Release)
    message("Release build")
elseif (NOT CMAKE_BUILD_TYPE)
    message("Default build")
else ()
    message(SEND_ERROR "Unknown build")
endif ()

include_directories(
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_BINARY_DIR}/include"
    )

# Compile the source
add_subdirectory(src) 

if (UNIT_TESTING)
    enable_testing()
    add_subdirectory(test/unit)
endif(UNIT_TESTING)

# Configure header file
configure_file(
    "${PROJECT_SOURCE_DIR}/include/config.h.in"
    "${PROJECT_BINARY_DIR}/include/config.h"
    )
