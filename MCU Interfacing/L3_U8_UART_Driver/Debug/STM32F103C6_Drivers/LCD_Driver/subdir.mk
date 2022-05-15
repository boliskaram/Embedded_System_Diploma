################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/LCD_Driver/LCD.c 

OBJS += \
./STM32F103C6_Drivers/LCD_Driver/LCD.o 

C_DEPS += \
./STM32F103C6_Drivers/LCD_Driver/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/LCD_Driver/LCD.o: ../STM32F103C6_Drivers/LCD_Driver/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Workspace/STM32Cube/L3_U8_UART_Driver/STM32F103C6_Drivers/LCD_Driver" -I"E:/Workspace/STM32Cube/L3_U8_UART_Driver/STM32F103C6_Drivers/Keypad_Driver" -I"E:/Workspace/STM32Cube/L3_U8_UART_Driver/STM32F103C6_Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/LCD_Driver/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

