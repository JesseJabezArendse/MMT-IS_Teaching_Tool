################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../.STM32CubeIDE/Application/User/Startup/startup_stm32f407zgtx.s 

OBJS += \
./.STM32CubeIDE/Application/User/Startup/startup_stm32f407zgtx.o 

S_DEPS += \
./.STM32CubeIDE/Application/User/Startup/startup_stm32f407zgtx.d 


# Each subdirectory must supply rules for building sources it contributes
.STM32CubeIDE/Application/User/Startup/%.o: ../.STM32CubeIDE/Application/User/Startup/%.s .STM32CubeIDE/Application/User/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean--2e-STM32CubeIDE-2f-Application-2f-User-2f-Startup

clean--2e-STM32CubeIDE-2f-Application-2f-User-2f-Startup:
	-$(RM) ./.STM32CubeIDE/Application/User/Startup/startup_stm32f407zgtx.d ./.STM32CubeIDE/Application/User/Startup/startup_stm32f407zgtx.o

.PHONY: clean--2e-STM32CubeIDE-2f-Application-2f-User-2f-Startup
