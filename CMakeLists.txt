cmake_minimum_required(VERSION 3.6)

project(teamspeak-who-speaks)

# The default C Flags
set(CMAKE_C_FLAGS 
"${CMAKE_C_FLAGS} \
-Wall"
)
    
# Set the additional Debug C Flags
set(CMAKE_C_FLAGS_DEBUG
"-Og \
-g \
${CMAKE_C_FLAGS_DEBUG} \
${CMAKE_C_FLAGS}"
)

# Set the additional Release C Flags
set(CMAKE_C_FLAGS_RELEASE
"-O3 \
${CMAKE_C_FLAGS_RELEASE} \
${CMAKE_C_FLAGS}"
)
    
# Inform the user of the Build type
if (CMAKE_BUILD_TYPE MATCHES Debug)
    message("Debug build")
elseif (CMAKE_BUILD_TYPE MATCHES Release)
    message("Release build")
elseif (NOT CMAKE_BUILD_TYPE)
    message("Default build")
else ()
    message(SEND_ERROR "Unknown build")
endif ()
    
# Compile the source
add_subdirectory(src) 

# Configure header file
configure_file(
    "${PROJECT_SOURCE_DIR}/include/config.h.in"
    "${PROJECT_BINARY_DIR}/include/config.h"
    )
