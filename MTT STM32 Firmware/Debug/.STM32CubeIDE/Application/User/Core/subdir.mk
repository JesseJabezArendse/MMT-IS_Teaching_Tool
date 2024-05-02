################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../.STM32CubeIDE/Application/User/Core/syscalls.c \
../.STM32CubeIDE/Application/User/Core/sysmem.c 

OBJS += \
./.STM32CubeIDE/Application/User/Core/syscalls.o \
./.STM32CubeIDE/Application/User/Core/sysmem.o 

C_DEPS += \
./.STM32CubeIDE/Application/User/Core/syscalls.d \
./.STM32CubeIDE/Application/User/Core/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
.STM32CubeIDE/Application/User/Core/%.o .STM32CubeIDE/Application/User/Core/%.su .STM32CubeIDE/Application/User/Core/%.cyclo: ../.STM32CubeIDE/Application/User/Core/%.c .STM32CubeIDE/Application/User/Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../../Core/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean--2e-STM32CubeIDE-2f-Application-2f-User-2f-Core

clean--2e-STM32CubeIDE-2f-Application-2f-User-2f-Core:
	-$(RM) ./.STM32CubeIDE/Application/User/Core/syscalls.cyclo ./.STM32CubeIDE/Application/User/Core/syscalls.d ./.STM32CubeIDE/Application/User/Core/syscalls.o ./.STM32CubeIDE/Application/User/Core/syscalls.su ./.STM32CubeIDE/Application/User/Core/sysmem.cyclo ./.STM32CubeIDE/Application/User/Core/sysmem.d ./.STM32CubeIDE/Application/User/Core/sysmem.o ./.STM32CubeIDE/Application/User/Core/sysmem.su

.PHONY: clean--2e-STM32CubeIDE-2f-Application-2f-User-2f-Core

