################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/DHT11.c \
../Core/Src/EX.c \
../Core/Src/EventClicks.c \
../Core/Src/ProjectOX.c \
../Core/Src/StartUpSystem.c \
../Core/Src/fonts.c \
../Core/Src/main.c \
../Core/Src/ssd1306.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c 

C_DEPS += \
./Core/Src/DHT11.d \
./Core/Src/EX.d \
./Core/Src/EventClicks.d \
./Core/Src/ProjectOX.d \
./Core/Src/StartUpSystem.d \
./Core/Src/fonts.d \
./Core/Src/main.d \
./Core/Src/ssd1306.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d 

OBJS += \
./Core/Src/DHT11.o \
./Core/Src/EX.o \
./Core/Src/EventClicks.o \
./Core/Src/ProjectOX.o \
./Core/Src/StartUpSystem.o \
./Core/Src/fonts.o \
./Core/Src/main.o \
./Core/Src/ssd1306.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/DHT11.d ./Core/Src/DHT11.o ./Core/Src/DHT11.su ./Core/Src/EX.d ./Core/Src/EX.o ./Core/Src/EX.su ./Core/Src/EventClicks.d ./Core/Src/EventClicks.o ./Core/Src/EventClicks.su ./Core/Src/ProjectOX.d ./Core/Src/ProjectOX.o ./Core/Src/ProjectOX.su ./Core/Src/StartUpSystem.d ./Core/Src/StartUpSystem.o ./Core/Src/StartUpSystem.su ./Core/Src/fonts.d ./Core/Src/fonts.o ./Core/Src/fonts.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/ssd1306.d ./Core/Src/ssd1306.o ./Core/Src/ssd1306.su ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su

.PHONY: clean-Core-2f-Src

