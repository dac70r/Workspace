################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/ethercat/New_Analog.c \
../Core/Src/ethercat/ax58400_hw.c \
../Core/Src/ethercat/coeappl.c \
../Core/Src/ethercat/ecatappl.c \
../Core/Src/ethercat/ecatcoe.c \
../Core/Src/ethercat/ecatfoe.c \
../Core/Src/ethercat/ecatslv.c \
../Core/Src/ethercat/foeappl.c \
../Core/Src/ethercat/mailbox.c \
../Core/Src/ethercat/objdef.c \
../Core/Src/ethercat/sdoserv.c 

OBJS += \
./Core/Src/ethercat/New_Analog.o \
./Core/Src/ethercat/ax58400_hw.o \
./Core/Src/ethercat/coeappl.o \
./Core/Src/ethercat/ecatappl.o \
./Core/Src/ethercat/ecatcoe.o \
./Core/Src/ethercat/ecatfoe.o \
./Core/Src/ethercat/ecatslv.o \
./Core/Src/ethercat/foeappl.o \
./Core/Src/ethercat/mailbox.o \
./Core/Src/ethercat/objdef.o \
./Core/Src/ethercat/sdoserv.o 

C_DEPS += \
./Core/Src/ethercat/New_Analog.d \
./Core/Src/ethercat/ax58400_hw.d \
./Core/Src/ethercat/coeappl.d \
./Core/Src/ethercat/ecatappl.d \
./Core/Src/ethercat/ecatcoe.d \
./Core/Src/ethercat/ecatfoe.d \
./Core/Src/ethercat/ecatslv.d \
./Core/Src/ethercat/foeappl.d \
./Core/Src/ethercat/mailbox.d \
./Core/Src/ethercat/objdef.d \
./Core/Src/ethercat/sdoserv.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/ethercat/%.o Core/Src/ethercat/%.su Core/Src/ethercat/%.cyclo: ../Core/Src/ethercat/%.c Core/Src/ethercat/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/guan-ming.dennis-won/Documents/Code/Workspace/Workspace/STM32_Workspace/EtherCAT_Stack_2025/Core/Src/ads131a04" -I"C:/Users/guan-ming.dennis-won/Documents/Code/Workspace/Workspace/STM32_Workspace/EtherCAT_Stack_2025/Core/Src/app_core" -I"C:/Users/guan-ming.dennis-won/Documents/Code/Workspace/Workspace/STM32_Workspace/EtherCAT_Stack_2025/Core/Src/led_hearbeat" -I"C:/Users/guan-ming.dennis-won/Documents/Code/Workspace/Workspace/STM32_Workspace/EtherCAT_Stack_2025/Core/Src/chip_driver" -I"C:/Users/guan-ming.dennis-won/Documents/Code/Workspace/Workspace/STM32_Workspace/EtherCAT_Stack_2025/Core/Src/ethercat" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-ethercat

clean-Core-2f-Src-2f-ethercat:
	-$(RM) ./Core/Src/ethercat/New_Analog.cyclo ./Core/Src/ethercat/New_Analog.d ./Core/Src/ethercat/New_Analog.o ./Core/Src/ethercat/New_Analog.su ./Core/Src/ethercat/ax58400_hw.cyclo ./Core/Src/ethercat/ax58400_hw.d ./Core/Src/ethercat/ax58400_hw.o ./Core/Src/ethercat/ax58400_hw.su ./Core/Src/ethercat/coeappl.cyclo ./Core/Src/ethercat/coeappl.d ./Core/Src/ethercat/coeappl.o ./Core/Src/ethercat/coeappl.su ./Core/Src/ethercat/ecatappl.cyclo ./Core/Src/ethercat/ecatappl.d ./Core/Src/ethercat/ecatappl.o ./Core/Src/ethercat/ecatappl.su ./Core/Src/ethercat/ecatcoe.cyclo ./Core/Src/ethercat/ecatcoe.d ./Core/Src/ethercat/ecatcoe.o ./Core/Src/ethercat/ecatcoe.su ./Core/Src/ethercat/ecatfoe.cyclo ./Core/Src/ethercat/ecatfoe.d ./Core/Src/ethercat/ecatfoe.o ./Core/Src/ethercat/ecatfoe.su ./Core/Src/ethercat/ecatslv.cyclo ./Core/Src/ethercat/ecatslv.d ./Core/Src/ethercat/ecatslv.o ./Core/Src/ethercat/ecatslv.su ./Core/Src/ethercat/foeappl.cyclo ./Core/Src/ethercat/foeappl.d ./Core/Src/ethercat/foeappl.o ./Core/Src/ethercat/foeappl.su ./Core/Src/ethercat/mailbox.cyclo ./Core/Src/ethercat/mailbox.d ./Core/Src/ethercat/mailbox.o ./Core/Src/ethercat/mailbox.su ./Core/Src/ethercat/objdef.cyclo ./Core/Src/ethercat/objdef.d ./Core/Src/ethercat/objdef.o ./Core/Src/ethercat/objdef.su ./Core/Src/ethercat/sdoserv.cyclo ./Core/Src/ethercat/sdoserv.d ./Core/Src/ethercat/sdoserv.o ./Core/Src/ethercat/sdoserv.su

.PHONY: clean-Core-2f-Src-2f-ethercat

