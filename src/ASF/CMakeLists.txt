
# ASF (Add to PARENT_SCOPE to make them availible in the level above)
set(SOURCE_FILES
    "${SOURCE_FILES}"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/adc/adc_sam_d_r_h/adc.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/adc/adc_sam_d_r_h/adc_callback.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/dma/dma.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/extint/extint_sam_d_r_h/extint.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/rtc/rtc_sam_d_r_h/rtc_calendar.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/rtc/rtc_sam_d_r_h/rtc_calendar_interrupt.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/sercom/sercom.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/tc/tc_sam_d_r_h/tc.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/usb/stack_interface/usb_device_udd.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/usb/stack_interface/usb_dual.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/wdt/wdt.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/wdt/wdt_callback.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/usb/usb_sam_d_r/usb.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/tc/tc_interrupt.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/sercom/usart/usart.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/sercom/usart/usart_interrupt.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/sercom/sercom_interrupt.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/extint/extint_callback.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/events/events_hooks.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/events/events_sam_d_r_h/events.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/common2/services/delay/sam0/systick_counter.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/common/services/sleepmgr/samd/sleepmgr.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/common/services/usb/class/cdc/device/udi_cdc.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/common/services/usb/udc/udc.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/common/services/usb/class/cdc/device/udi_cdc_desc.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/nvm/nvm.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/port/port.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/common2/boards/user_board/init.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/common/utils/interrupt/interrupt_sam_nvic.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/system/clock/clock_samd21_r21_da_ha1/clock.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/system/clock/clock_samd21_r21_da_ha1/gclk.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/system/interrupt/system_interrupt.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/system/pinmux/pinmux.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/system/system.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/utils/cmsis/samd21/source/gcc/startup_samd21.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/utils/cmsis/samd21/source/system_samd21.c"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/utils/syscalls/gcc/syscalls.c"
    PARENT_SCOPE
    )
    
# ASF header files
set(ASF_HEADERS
    "${PROJECT_SOURCE_DIR}/include/ASF"
    "${PROJECT_SOURCE_DIR}/include/ASF/config"
    "${PROJECT_SOURCE_DIR}/src/ASF"
    "${PROJECT_SOURCE_DIR}/src/ASF/common2"
    "${PROJECT_SOURCE_DIR}/src/ASF/common2/boards"
    "${PROJECT_SOURCE_DIR}/src/ASF/common2/boards/user_board"
    "${PROJECT_SOURCE_DIR}/src/ASF/common2/services"
    "${PROJECT_SOURCE_DIR}/src/ASF/common2/services/delay"
    "${PROJECT_SOURCE_DIR}/src/ASF/common2/services/delay/sam0"
    "${PROJECT_SOURCE_DIR}/src/ASF/common"
    "${PROJECT_SOURCE_DIR}/src/ASF/common/boards"
    "${PROJECT_SOURCE_DIR}/src/ASF/common/services"
    "${PROJECT_SOURCE_DIR}/src/ASF/common/services/sleepmgr"
    "${PROJECT_SOURCE_DIR}/src/ASF/common/services/sleepmgr/samd"
    "${PROJECT_SOURCE_DIR}/src/ASF/common/services/usb"
    "${PROJECT_SOURCE_DIR}/src/ASF/common/services/usb/class"
    "${PROJECT_SOURCE_DIR}/src/ASF/common/services/usb/class/cdc"
    "${PROJECT_SOURCE_DIR}/src/ASF/common/services/usb/class/cdc/device"
    "${PROJECT_SOURCE_DIR}/src/ASF/common/services/usb/udc"
    "${PROJECT_SOURCE_DIR}/src/ASF/common/utils"
    "${PROJECT_SOURCE_DIR}/src/ASF/common/utils/interrupt"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/adc"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/adc/adc_sam_d_r_h"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/dma"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/dma/quick_start"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/events"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/events/events_sam_d_r_h"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/extint"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/extint/extint_sam_d_r_h"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/nvm"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/nvm/quick_start_basic"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/port"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/port/quick_start"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/rtc"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/rtc/rtc_sam_d_r_h"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/sercom"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/sercom/usart"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/sercom/usart/quick_start"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/sercom/usart/quick_start_callback"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/sercom/usart/quick_start_dma"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/sercom/usart/quick_start_lin"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/system"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/system/clock"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/system/clock/clock_samd21_r21_da_ha1"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/system/interrupt"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/system/interrupt/system_interrupt_samd21"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/system/pinmux"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/system/pinmux/quick_start"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/system/power"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/system/power/power_sam_d_r_h"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/system/reset"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/system/reset/reset_sam_d_r_h"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/tc"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/tc/tc_sam_d_r_h"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/usb"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/usb/stack_interface"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/usb/usb_sam_d_r"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/wdt"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/wdt/quick_start"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/drivers/wdt/quick_start_callback"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/utils"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/utils/cmsis"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/utils/cmsis/samd21"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/utils/cmsis/samd21/include"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/utils/cmsis/samd21/include/component"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/utils/cmsis/samd21/include/instance"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/utils/cmsis/samd21/include/pio"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/utils/cmsis/samd21/source"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/utils/cmsis/samd21/source/gcc"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/utils/header_files"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/utils/linker_scripts"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/utils/linker_scripts/samd21"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/utils/linker_scripts/samd21/gcc"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/utils/make"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/utils/preprocessor"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/utils/syscalls"
    "${PROJECT_SOURCE_DIR}/src/ASF/sam0/utils/syscalls/gcc"
    "${PROJECT_SOURCE_DIR}/src/ASF/thirdparty"
    "${PROJECT_SOURCE_DIR}/src/ASF/thirdparty/CMSIS"
    "${PROJECT_SOURCE_DIR}/src/ASF/thirdparty/CMSIS/Include"
    "${PROJECT_SOURCE_DIR}/src/ASF/thirdparty/CMSIS/Lib"
    "${PROJECT_SOURCE_DIR}/src/ASF/thirdparty/CMSIS/Lib/GCC"
    PARENT_SCOPE
)