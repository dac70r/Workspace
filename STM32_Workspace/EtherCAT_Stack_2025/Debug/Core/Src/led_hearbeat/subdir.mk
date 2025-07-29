################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/led_hearbeat/led_heartbeat.c 

OBJS += \
./Core/Src/led_hearbeat/led_heartbeat.o 

C_DEPS += \
./Core/Src/led_hearbeat/led_heartbeat.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/led_hearbeat/%.o Core/Src/led_hearbeat/%.su Core/Src/led_hearbeat/%.cyclo: ../Core/Src/led_hearbeat/%.c Core/Src/led_hearbeat/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/guan-ming.dennis-won/Documents/Code/Workspace/Workspace/STM32_Workspace/EtherCAT_Stack_2025/Core/Src/ads131a04" -I"C:/Users/guan-ming.dennis-won/Documents/Code/Workspace/Workspace/STM32_Workspace/EtherCAT_Stack_2025/Core/Src/app_core" -I"C:/Users/guan-ming.dennis-won/Documents/Code/Workspace/Workspace/STM32_Workspace/EtherCAT_Stack_2025/Core/Src/led_hearbeat" -I"C:/Users/guan-ming.dennis-won/Documents/Code/Workspace/Workspace/STM32_Workspace/EtherCAT_Stack_2025/Core/Src/chip_driver" -I"C:/Users/guan-ming.dennis-won/Documents/Code/Workspace/Workspace/STM32_Workspace/EtherCAT_Stack_2025/Core/Src/ethercat" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-led_hearbeat

clean-Core-2f-Src-2f-led_hearbeat:
	-$(RM) ./Core/Src/led_hearbeat/led_heartbeat.cyclo ./Core/Src/led_hearbeat/led_heartbeat.d ./Core/Src/led_hearbeat/led_heartbeat.o ./Core/Src/led_hearbeat/led_heartbeat.su

.PHONY: clean-Core-2f-Src-2f-led_hearbeat

