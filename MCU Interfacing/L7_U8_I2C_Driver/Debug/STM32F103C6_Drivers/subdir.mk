################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/stm32f103c6_EXTI_driver.c \
../STM32F103C6_Drivers/stm32f103c6_I2C_driver.c \
../STM32F103C6_Drivers/stm32f103c6_RCC_driver.c \
../STM32F103C6_Drivers/stm32f103c6_SPI_driver.c \
../STM32F103C6_Drivers/stm32f103c6_USART_driver.c \
../STM32F103C6_Drivers/stm32f103c6_gpio_driver.c 

OBJS += \
./STM32F103C6_Drivers/stm32f103c6_EXTI_driver.o \
./STM32F103C6_Drivers/stm32f103c6_I2C_driver.o \
./STM32F103C6_Drivers/stm32f103c6_RCC_driver.o \
./STM32F103C6_Drivers/stm32f103c6_SPI_driver.o \
./STM32F103C6_Drivers/stm32f103c6_USART_driver.o \
./STM32F103C6_Drivers/stm32f103c6_gpio_driver.o 

C_DEPS += \
./STM32F103C6_Drivers/stm32f103c6_EXTI_driver.d \
./STM32F103C6_Drivers/stm32f103c6_I2C_driver.d \
./STM32F103C6_Drivers/stm32f103c6_RCC_driver.d \
./STM32F103C6_Drivers/stm32f103c6_SPI_driver.d \
./STM32F103C6_Drivers/stm32f103c6_USART_driver.d \
./STM32F103C6_Drivers/stm32f103c6_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/%.o STM32F103C6_Drivers/%.su: ../STM32F103C6_Drivers/%.c STM32F103C6_Drivers/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"E:/Workspace/STM32Cube/L7_U8_I2C_Driver/HAL/EEPROM" -I"E:/Workspace/STM32Cube/L7_U8_I2C_Driver/HAL/Keypad_Driver" -I"E:/Workspace/STM32Cube/L7_U8_I2C_Driver/HAL/LCD_Driver" -I"E:/Workspace/STM32Cube/L7_U8_I2C_Driver/STM32F103C6_Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32F103C6_Drivers

clean-STM32F103C6_Drivers:
	-$(RM) ./STM32F103C6_Drivers/stm32f103c6_EXTI_driver.d ./STM32F103C6_Drivers/stm32f103c6_EXTI_driver.o ./STM32F103C6_Drivers/stm32f103c6_EXTI_driver.su ./STM32F103C6_Drivers/stm32f103c6_I2C_driver.d ./STM32F103C6_Drivers/stm32f103c6_I2C_driver.o ./STM32F103C6_Drivers/stm32f103c6_I2C_driver.su ./STM32F103C6_Drivers/stm32f103c6_RCC_driver.d ./STM32F103C6_Drivers/stm32f103c6_RCC_driver.o ./STM32F103C6_Drivers/stm32f103c6_RCC_driver.su ./STM32F103C6_Drivers/stm32f103c6_SPI_driver.d ./STM32F103C6_Drivers/stm32f103c6_SPI_driver.o ./STM32F103C6_Drivers/stm32f103c6_SPI_driver.su ./STM32F103C6_Drivers/stm32f103c6_USART_driver.d ./STM32F103C6_Drivers/stm32f103c6_USART_driver.o ./STM32F103C6_Drivers/stm32f103c6_USART_driver.su ./STM32F103C6_Drivers/stm32f103c6_gpio_driver.d ./STM32F103C6_Drivers/stm32f103c6_gpio_driver.o ./STM32F103C6_Drivers/stm32f103c6_gpio_driver.su

.PHONY: clean-STM32F103C6_Drivers

