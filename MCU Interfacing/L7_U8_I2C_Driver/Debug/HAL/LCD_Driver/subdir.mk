################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LCD_Driver/LCD.c 

OBJS += \
./HAL/LCD_Driver/LCD.o 

C_DEPS += \
./HAL/LCD_Driver/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LCD_Driver/%.o HAL/LCD_Driver/%.su: ../HAL/LCD_Driver/%.c HAL/LCD_Driver/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"E:/Workspace/STM32Cube/L7_U8_I2C_Driver/HAL/EEPROM" -I"E:/Workspace/STM32Cube/L7_U8_I2C_Driver/HAL/Keypad_Driver" -I"E:/Workspace/STM32Cube/L7_U8_I2C_Driver/HAL/LCD_Driver" -I"E:/Workspace/STM32Cube/L7_U8_I2C_Driver/STM32F103C6_Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HAL-2f-LCD_Driver

clean-HAL-2f-LCD_Driver:
	-$(RM) ./HAL/LCD_Driver/LCD.d ./HAL/LCD_Driver/LCD.o ./HAL/LCD_Driver/LCD.su

.PHONY: clean-HAL-2f-LCD_Driver

