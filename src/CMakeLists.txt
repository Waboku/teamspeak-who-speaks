
# TODO: These are taken directly from Atmel, check which are needed
# TODO: Split the flags from the defines
set(CMAKE_C_FLAGS
    "${CMAKE_C_FLAGS} \
    -mthumb \
    -D__SAMD21E17A__ \
    -DDEBUG \
    -DBOARD=USER_BOARD \
    -DARM_MATH_CM0PLUS=true \
    -DUSB_DEVICE_LPM_SUPPORT \
    -DUDD_ENABLE \
    -DSYSTICK_MODE \
    -DADC_CALLBACK_MODE=true \
    -DEVENTS_INTERRUPT_HOOKS_MODE=true \
    -DEXTINT_CALLBACK_MODE=true \
    -DRTC_CALENDAR_ASYNC=true \
    -DUSART_CALLBACK_MODE=true \
    -DTC_ASYNC=true \
    -DWDT_CALLBACK_MODE=true \
    -Og \
    -fdata-sections \
    -ffunction-sections \
    -mlong-calls \
    -mcpu=cortex-m0plus \
    -pipe \
    -fno-strict-aliasing \
    -Wstrict-prototypes \
    -Wmissing-prototypes \
    -Werror-implicit-function-declaration \
    -Wpointer-arith \
    -std=gnu99 \
    -ffunction-sections \
    -fdata-sections \
    -Wchar-subscripts \
    -Wcomment \
    -Wformat=2 \
    -Wimplicit-int \
    -Wmain \
    -Wparentheses \
    -Wsequence-point \
    -Wreturn-type \
    -Wswitch \
    -Wtrigraphs \
    -Wunused \
    -Wuninitialized \
    -Wunknown-pragmas \
    -Wfloat-equal \
    -Wundef \
    -Wshadow \
    -Wbad-function-cast \
    -Wwrite-strings \
    -Wsign-compare \
    -Waggregate-return \
    -Wmissing-declarations \
    -Wformat \
    -Wmissing-format-attribute \
    -Wno-deprecated-declarations\
    -Wpacked \
    -Wredundant-decls \
    -Wnested-externs \
    -Wlong-long \
    -Wunreachable-code \
    -Wcast-align \
    --param max-inline-insns-single=500"
    )
    
include_directories(
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_BINARY_DIR}/include"
    )

# Adds ASF sources to SOURCE_FILES
# Adds ASF headers to ASF_HEADERS
add_subdirectory(ASF) 
include_directories("${ASF_HEADERS}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

add_executable(teamspeak-who-speaks.elf
    "${PROJECT_SOURCE_DIR}/src/main.c"
    "${PROJECT_SOURCE_DIR}/src/stdio_setup.c"
    "${PROJECT_SOURCE_DIR}/src/usb_callback.c"
    "${PROJECT_SOURCE_DIR}/src/linkedlist.c"
    "${SOURCE_FILES}"
    )