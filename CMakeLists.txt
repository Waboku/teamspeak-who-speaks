cmake_minimum_required(VERSION 3.6)

project(teamspeak-who-speaks)

# The default C Flags
set(CMAKE_C_FLAGS 
    "${CMAKE_C_FLAGS} \
    -Wall"
    )
    
# Compile the source
add_subdirectory(src) 

# Configure header file
configure_file(
    "${PROJECT_SOURCE_DIR}/include/config.h.in"
    "${PROJECT_BINARY_DIR}/include/config.h"
    )
