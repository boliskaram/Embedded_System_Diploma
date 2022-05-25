################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/LCD_Driver/LCD.c 

OBJS += \
./STM32F103C6_Drivers/LCD_Driver/LCD.o 

C_DEPS += \
./STM32F103C6_Drivers/LCD_Driver/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/LCD_Driver/%.o STM32F103C6_Drivers/LCD_Driver/%.su: ../STM32F103C6_Drivers/LCD_Driver/%.c STM32F103C6_Drivers/LCD_Driver/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"E:/Workspace/STM32Cube/L5_U8_SPI_Driver/STM32F103C6_Drivers/Inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32F103C6_Drivers-2f-LCD_Driver

clean-STM32F103C6_Drivers-2f-LCD_Driver:
	-$(RM) ./STM32F103C6_Drivers/LCD_Driver/LCD.d ./STM32F103C6_Drivers/LCD_Driver/LCD.o ./STM32F103C6_Drivers/LCD_Driver/LCD.su

.PHONY: clean-STM32F103C6_Drivers-2f-LCD_Driver

