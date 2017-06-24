# CMAKE toolchain for the samd21e17a ARM microcontroller

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR samd21)

SET(LINKER_SCRIPT "${PROJECT_SOURCE_DIR}/src/linker_scripts/samd21e17a_flash.ld")

set(CMAKE_C_COMPILER   "arm-none-eabi-gcc")
set(CMAKE_CXX_COMPILER "arm-none-eabi-g++")
set(CMAKE_AR           "arm-none-eabi-ar")
set(CMAKE_LINKER       "arm-none-eabi-ld")
set(CMAKE_NM           "arm-none-eabi-nm")
set(CMAKE_OBJDUMP      "arm-none-eabi-objdump")
set(CMAKE_STRIP        "arm-none-eabi-strip")
set(CMAKE_RANLIB       "arm-none-eabi-ranlib")

SET(CMAKE_EXE_LINKER_FLAGS "-specs=nosys.specs -Wl,--gc-sections -T ${LINKER_SCRIPT}")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
