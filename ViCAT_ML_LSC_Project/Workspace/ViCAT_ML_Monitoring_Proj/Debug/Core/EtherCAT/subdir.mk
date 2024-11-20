################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/EtherCAT/ViCAT_ML_LSC_Proj.c \
../Core/EtherCAT/ax58X00_hw.c \
../Core/EtherCAT/coeappl.c \
../Core/EtherCAT/ecatappl.c \
../Core/EtherCAT/ecatcoe.c \
../Core/EtherCAT/ecatslv.c \
../Core/EtherCAT/mailbox.c \
../Core/EtherCAT/objdef.c \
../Core/EtherCAT/sdoserv.c 

OBJS += \
./Core/EtherCAT/ViCAT_ML_LSC_Proj.o \
./Core/EtherCAT/ax58X00_hw.o \
./Core/EtherCAT/coeappl.o \
./Core/EtherCAT/ecatappl.o \
./Core/EtherCAT/ecatcoe.o \
./Core/EtherCAT/ecatslv.o \
./Core/EtherCAT/mailbox.o \
./Core/EtherCAT/objdef.o \
./Core/EtherCAT/sdoserv.o 

C_DEPS += \
./Core/EtherCAT/ViCAT_ML_LSC_Proj.d \
./Core/EtherCAT/ax58X00_hw.d \
./Core/EtherCAT/coeappl.d \
./Core/EtherCAT/ecatappl.d \
./Core/EtherCAT/ecatcoe.d \
./Core/EtherCAT/ecatslv.d \
./Core/EtherCAT/mailbox.d \
./Core/EtherCAT/objdef.d \
./Core/EtherCAT/sdoserv.d 


# Each subdirectory must supply rules for building sources it contributes
Core/EtherCAT/%.o Core/EtherCAT/%.su Core/EtherCAT/%.cyclo: ../Core/EtherCAT/%.c Core/EtherCAT/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/guan-ming.dennis-won/Documents/Code/Workspace/ViCAT_ML_LSC_Project/Workspace/ViCAT_ML_Monitoring_Proj/Core/EtherCAT" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-EtherCAT

clean-Core-2f-EtherCAT:
	-$(RM) ./Core/EtherCAT/ViCAT_ML_LSC_Proj.cyclo ./Core/EtherCAT/ViCAT_ML_LSC_Proj.d ./Core/EtherCAT/ViCAT_ML_LSC_Proj.o ./Core/EtherCAT/ViCAT_ML_LSC_Proj.su ./Core/EtherCAT/ax58X00_hw.cyclo ./Core/EtherCAT/ax58X00_hw.d ./Core/EtherCAT/ax58X00_hw.o ./Core/EtherCAT/ax58X00_hw.su ./Core/EtherCAT/coeappl.cyclo ./Core/EtherCAT/coeappl.d ./Core/EtherCAT/coeappl.o ./Core/EtherCAT/coeappl.su ./Core/EtherCAT/ecatappl.cyclo ./Core/EtherCAT/ecatappl.d ./Core/EtherCAT/ecatappl.o ./Core/EtherCAT/ecatappl.su ./Core/EtherCAT/ecatcoe.cyclo ./Core/EtherCAT/ecatcoe.d ./Core/EtherCAT/ecatcoe.o ./Core/EtherCAT/ecatcoe.su ./Core/EtherCAT/ecatslv.cyclo ./Core/EtherCAT/ecatslv.d ./Core/EtherCAT/ecatslv.o ./Core/EtherCAT/ecatslv.su ./Core/EtherCAT/mailbox.cyclo ./Core/EtherCAT/mailbox.d ./Core/EtherCAT/mailbox.o ./Core/EtherCAT/mailbox.su ./Core/EtherCAT/objdef.cyclo ./Core/EtherCAT/objdef.d ./Core/EtherCAT/objdef.o ./Core/EtherCAT/objdef.su ./Core/EtherCAT/sdoserv.cyclo ./Core/EtherCAT/sdoserv.d ./Core/EtherCAT/sdoserv.o ./Core/EtherCAT/sdoserv.su

.PHONY: clean-Core-2f-EtherCAT

