cmake_minimum_required (VERSION 3.6)
set(CMAKE_VERBOSE_MAKEFILE OFF)

project (Research)
include(CMakeForceCompiler)
set (CMAKE_SYSTEM_NAME Generic)
set (CMAKE_CROSSCOMPILING 1)
enable_language (ASM)
set (CMAKE_ASM_COMPILER /path/to/your/gnu-mcu-eclipse/arm-none-eabi-gcc/7.3.1-1.1-20180724-0637/bin/arm-none-eabi-gcc)
CMAKE_FORCE_C_COMPILER (/path/to/your/gnu-mcu-eclipse/arm-none-eabi-gcc/7.3.1-1.1-20180724-0637/bin/arm-none-eabi-gcc GNU)
CMAKE_FORCE_CXX_COMPILER (/path/to/your/gnu-mcu-eclipse/arm-none-eabi-gcc/7.3.1-1.1-20180724-0637/bin/arm-none-eabi-g++ GNU)

# Define repository directory structure
set (ST_LIB_DIR "${CMAKE_SOURCE_DIR}/STM32Cube_FW_F4_V1.21.0")

# Identify include for project, CMSIS, and STM drivers
include_directories (
    ${ST_LIB_DIR}/Drivers/STM32F4xx_HAL_Driver/Inc
    ${CMAKE_SOURCE_DIR}/inc
    ${ST_LIB_DIR}/Drivers/BSP/STM32F4-Discovery/
    ${ST_LIB_DIR}/Drivers/CMSIS/Include
    ${ST_LIB_DIR}/Drivers/CMSIS/Device/ST/STM32F4xx/Include

)

# Identify linker directories
link_directories(
    ${ST_LIB_DIR}/Drivers/CMSIS/Lib/GCC
)

# ========================================================================
set (STARTUP
    ${CMAKE_SOURCE_DIR}/startup_stm32f407xx.s
)

set (STM_SRC
    ${ST_LIB_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
    ${ST_LIB_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
    ${ST_LIB_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
    ${ST_LIB_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
    ${ST_LIB_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c
    ${ST_LIB_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
    ${ST_LIB_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
    ${ST_LIB_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc.c
    ${ST_LIB_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc_ex.c
    ${ST_LIB_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
    ${ST_LIB_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c
    ${ST_LIB_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c
    ${ST_LIB_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c
    ${ST_LIB_DIR}/Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.c
)

add_library(STM ${STM_SRC})

# add shortcut
set (APP_SRC
    ${CMAKE_SOURCE_DIR}/src/blink.cc
)

set (CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -c")

# set printing console
set(GCC_LINK_FLAGS "-u _printf_float -nostartfiles -Xlinker --gc-sections -L${CMAKE_SOURCE_DIR}/ldscripts --specs=nano.specs --specs=nosys.specs")

set (LINKER_SCRIPT
    ${CMAKE_SOURCE_DIR}/linker/STM32F407VGTx_FLASH.ld)
# ========================================================================
set (CM_SYSTEM_DEFINE
    "-DSTM32F407xx -DARM_MATH_CM4"
)

set (CMAKE_C_FLAGS
    "${CMAKE_C_FLAGS} \
    -mcpu=cortex-m4 -mthumb \
    -mfloat-abi=hard -mfpu=fpv4-sp-d16 \
    -ffunction-sections \
    -fdata-sections \
    -fno-builtin \
    ${CM_SYSTEM_DEFINE}"
)

set (CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} \
    -mcpu=cortex-m4 -mthumb \
    -mfloat-abi=hard -mfpu=fpv4-sp-d16 \
    -ffunction-sections \
    -fdata-sections \
    -fno-builtin \
    -Wall \
    -W \
    -std=c++11 \
    ${CM_SYSTEM_DEFINE}"
)

set (DBG_MORE_FLAGS "-g -Og -DBUILD_SEMIHOSTING_ENABLE")
set (TEST_MORE_FLAGS "-g -Og -DBUILD_SEMIHOSTING_ENABLE")
set (RLS_MORE_FLAGS "-fno-exceptions -O3")

set (DBG_LINK "-T ${LINKER_SCRIPT} --specs=nano.specs --specs=rdimon.specs -u _scanf_float -u _printf_float  -Wl,--no-wchar-size-warning -lc -lrdimon -Wl,-gc-sections")

add_executable (${PROJECT_NAME} ${STARTUP} ${APP_SRC} ${STM_SRC})

set_target_properties(
  ${PROJECT_NAME} PROPERTIES
  COMPILE_FLAGS ${DBG_MORE_FLAGS}
  LINK_FLAGS ${DBG_LINK}
)
