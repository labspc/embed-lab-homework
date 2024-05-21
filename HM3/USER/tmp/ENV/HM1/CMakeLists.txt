# CMSIS Build CMakeLists generated on 2024-05-13T01:00:31

cmake_minimum_required(VERSION 3.22)

# Target options

set(TARGET ENV)
set(CPU Cortex-M3)
set(PRJ_DIR "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/USER")
set(OUT_DIR "C:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/USER/out/ENV/HM1")
set(INT_DIR "C:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/USER/tmp/ENV/HM1")
set(FPU NO_FPU)
set(BYTE_ORDER Little-endian)
set(OPTIMIZE speed)
set(DEBUG on)
set(CC_FLAGS_GLOBAL "-std=c99 -fno-rtti -funsigned-char -fshort-enums -fshort-wchar -ffunction-sections -w")
set(CXX_FLAGS_GLOBAL "-xc++ -std=c++11 -fno-rtti -funsigned-char -fshort-enums -fshort-wchar -ffunction-sections -w")
set(LD_FLAGS_GLOBAL "--library_type=microlib --map --load_addr_map_info --xref --callgraph --symbols --info sizes --info totals --info unused --info veneers --strict --summary_stderr --info summarysizes")
set(LD_SCRIPT "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/USER/ENV_HM1.sct")

set(DEFINES
  STM32F10X_HD
  USE_STDPERIPH_DRIVER
  __MICROLIB
)

set(INC_PATHS
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/USER"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/CORE"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/STM32F10x_FWLib/inc"
  "C:/Users/22H2/AppData/Local/arm/packs/Keil/STM32F1xx_DFP/2.4.1/Device/Include"
)

set(AS_ARM_SRC_FILES
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/CORE/startup_stm32f10x_hd.s"
)

set(CC_SRC_FILES
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/CORE/core_cm3.c"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/STM32F10x_FWLib/src/misc.c"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/STM32F10x_FWLib/src/stm32f10x_adc.c"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/STM32F10x_FWLib/src/stm32f10x_bkp.c"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/STM32F10x_FWLib/src/stm32f10x_can.c"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/STM32F10x_FWLib/src/stm32f10x_cec.c"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/STM32F10x_FWLib/src/stm32f10x_crc.c"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/STM32F10x_FWLib/src/stm32f10x_dac.c"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/STM32F10x_FWLib/src/stm32f10x_dbgmcu.c"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/STM32F10x_FWLib/src/stm32f10x_dma.c"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/STM32F10x_FWLib/src/stm32f10x_exti.c"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/STM32F10x_FWLib/src/stm32f10x_flash.c"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/STM32F10x_FWLib/src/stm32f10x_fsmc.c"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/STM32F10x_FWLib/src/stm32f10x_gpio.c"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/STM32F10x_FWLib/src/stm32f10x_i2c.c"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/STM32F10x_FWLib/src/stm32f10x_iwdg.c"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/STM32F10x_FWLib/src/stm32f10x_pwr.c"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/STM32F10x_FWLib/src/stm32f10x_rcc.c"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/STM32F10x_FWLib/src/stm32f10x_rtc.c"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/STM32F10x_FWLib/src/stm32f10x_sdio.c"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/STM32F10x_FWLib/src/stm32f10x_spi.c"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/STM32F10x_FWLib/src/stm32f10x_tim.c"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/STM32F10x_FWLib/src/stm32f10x_usart.c"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/STM32F10x_FWLib/src/stm32f10x_wwdg.c"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/USER/main.c"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/USER/stm32f10x_it.c"
  "c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/USER/system_stm32f10x.c"
)

set(AS_FLAGS_c:/Users/22H2/Documents/GitHub/embed-lab-homework/HM2/CORE/startup_stm32f10x_hd.s "-masm=auto")

# Toolchain config map

set(REGISTERED_TOOLCHAIN_ROOT "c:/Users/22H2/.vcpkg/artifacts/2139c4c6/compilers.arm.armclang/6.21.0/bin")
set(REGISTERED_TOOLCHAIN_VERSION "6.21.0")
set(TOOLCHAIN_VERSION_MIN "6.21.0")
set(TOOLCHAIN_VERSION_MAX "6.21.0")
include ("C:/Users/22H2/.vcpkg/artifacts/2139c4c6/tools.open.cmsis.pack.cmsis.toolbox/2.3.0/etc/AC6.6.18.0.cmake")
include ("C:/Users/22H2/.vcpkg/artifacts/2139c4c6/tools.open.cmsis.pack.cmsis.toolbox/2.3.0/etc/CMSIS-Build-Utils.cmake")

# Setup project

project(${TARGET} LANGUAGES AS_ARM C)

cbuild_get_running_toolchain(TOOLCHAIN_ROOT TOOLCHAIN_VERSION C)

# Global Flags

set(CMAKE_AS_ARM_FLAGS "${AS_ARM_CPU} ${AS_ARM_BYTE_ORDER} ${AS_ARM_DEFINES} ${AS_ARM_OPTIONS_FLAGS} ${AS_ARM_FLAGS}")
cbuild_get_system_includes(CC_SYS_INC_PATHS_LIST CC_SYS_INC_PATHS)
set(CMAKE_C_FLAGS "${CC_CPU} ${CC_BYTE_ORDER} ${CC_DEFINES} ${CC_OPTIONS_FLAGS} ${CC_FLAGS} ${CC_FLAGS_GLOBAL} ${CC_SYS_INC_PATHS}")
set(CMAKE_C_LINK_FLAGS "${LD_CPU} ${_LS}\"${LD_SCRIPT}\" ${LD_FLAGS_GLOBAL} ${LD_OPTIONS_FLAGS} ${LD_FLAGS}")

# Local Flags

foreach(SRC ${AS_ARM_SRC_FILES})
  string(REPLACE " " "?" S ${SRC})
  if(DEFINED AS_FLAGS_${S})
    set(AS_FLAGS_LOCAL "${AS_FLAGS_${S}}")
  else()
    set(AS_FLAGS_LOCAL "${AS_FLAGS_GLOBAL}")
  endif()
  set_source_files_properties(${SRC} PROPERTIES COMPILE_FLAGS "${AS_FLAGS_LOCAL}")
  set_source_files_properties(${SRC} PROPERTIES LANGUAGE AS_ARM)
endforeach()

# Compilation Database

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_custom_target(database COMMAND ${CMAKE_COMMAND} -E copy_if_different "${INT_DIR}/compile_commands.json" "${OUT_DIR}")

# Setup Target

add_executable(${TARGET} ${AS_ARM_SRC_FILES} ${CC_SRC_FILES})
set_target_properties(${TARGET} PROPERTIES PREFIX "" SUFFIX ".axf" OUTPUT_NAME "ENV")
set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUT_DIR} LINK_DEPENDS ${LD_SCRIPT})
target_include_directories(${TARGET} PUBLIC ${INC_PATHS})
