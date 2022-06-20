################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/Keypad_Driver/Keypad.c 

OBJS += \
./STM32F103C6_Drivers/Keypad_Driver/Keypad.o 

C_DEPS += \
./STM32F103C6_Drivers/Keypad_Driver/Keypad.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/Keypad_Driver/%.o STM32F103C6_Drivers/Keypad_Driver/%.su: ../STM32F103C6_Drivers/Keypad_Driver/%.c STM32F103C6_Drivers/Keypad_Driver/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"E:/Workspace/STM32Cube/L7_U8_I2C_Driver/STM32F103C6_Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32F103C6_Drivers-2f-Keypad_Driver

clean-STM32F103C6_Drivers-2f-Keypad_Driver:
	-$(RM) ./STM32F103C6_Drivers/Keypad_Driver/Keypad.d ./STM32F103C6_Drivers/Keypad_Driver/Keypad.o ./STM32F103C6_Drivers/Keypad_Driver/Keypad.su

.PHONY: clean-STM32F103C6_Drivers-2f-Keypad_Driver

