################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/EtherCAT_Src/ViCAT_ML_LSC_Proj.c \
../Core/EtherCAT_Src/ax58X00_hw.c \
../Core/EtherCAT_Src/coeappl.c \
../Core/EtherCAT_Src/ecatappl.c \
../Core/EtherCAT_Src/ecatcoe.c \
../Core/EtherCAT_Src/ecatslv.c \
../Core/EtherCAT_Src/mailbox.c \
../Core/EtherCAT_Src/objdef.c \
../Core/EtherCAT_Src/sdoserv.c 

OBJS += \
./Core/EtherCAT_Src/ViCAT_ML_LSC_Proj.o \
./Core/EtherCAT_Src/ax58X00_hw.o \
./Core/EtherCAT_Src/coeappl.o \
./Core/EtherCAT_Src/ecatappl.o \
./Core/EtherCAT_Src/ecatcoe.o \
./Core/EtherCAT_Src/ecatslv.o \
./Core/EtherCAT_Src/mailbox.o \
./Core/EtherCAT_Src/objdef.o \
./Core/EtherCAT_Src/sdoserv.o 

C_DEPS += \
./Core/EtherCAT_Src/ViCAT_ML_LSC_Proj.d \
./Core/EtherCAT_Src/ax58X00_hw.d \
./Core/EtherCAT_Src/coeappl.d \
./Core/EtherCAT_Src/ecatappl.d \
./Core/EtherCAT_Src/ecatcoe.d \
./Core/EtherCAT_Src/ecatslv.d \
./Core/EtherCAT_Src/mailbox.d \
./Core/EtherCAT_Src/objdef.d \
./Core/EtherCAT_Src/sdoserv.d 


# Each subdirectory must supply rules for building sources it contributes
Core/EtherCAT_Src/%.o Core/EtherCAT_Src/%.su Core/EtherCAT_Src/%.cyclo: ../Core/EtherCAT_Src/%.c Core/EtherCAT_Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/guan-ming.dennis-won/Documents/Code/Workspace/ViCAT_ML_LSC_Project/Workspace/ViCAT_ML_Monitoring_Proj/Core/EtherCAT_Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-EtherCAT_Src

clean-Core-2f-EtherCAT_Src:
	-$(RM) ./Core/EtherCAT_Src/ViCAT_ML_LSC_Proj.cyclo ./Core/EtherCAT_Src/ViCAT_ML_LSC_Proj.d ./Core/EtherCAT_Src/ViCAT_ML_LSC_Proj.o ./Core/EtherCAT_Src/ViCAT_ML_LSC_Proj.su ./Core/EtherCAT_Src/ax58X00_hw.cyclo ./Core/EtherCAT_Src/ax58X00_hw.d ./Core/EtherCAT_Src/ax58X00_hw.o ./Core/EtherCAT_Src/ax58X00_hw.su ./Core/EtherCAT_Src/coeappl.cyclo ./Core/EtherCAT_Src/coeappl.d ./Core/EtherCAT_Src/coeappl.o ./Core/EtherCAT_Src/coeappl.su ./Core/EtherCAT_Src/ecatappl.cyclo ./Core/EtherCAT_Src/ecatappl.d ./Core/EtherCAT_Src/ecatappl.o ./Core/EtherCAT_Src/ecatappl.su ./Core/EtherCAT_Src/ecatcoe.cyclo ./Core/EtherCAT_Src/ecatcoe.d ./Core/EtherCAT_Src/ecatcoe.o ./Core/EtherCAT_Src/ecatcoe.su ./Core/EtherCAT_Src/ecatslv.cyclo ./Core/EtherCAT_Src/ecatslv.d ./Core/EtherCAT_Src/ecatslv.o ./Core/EtherCAT_Src/ecatslv.su ./Core/EtherCAT_Src/mailbox.cyclo ./Core/EtherCAT_Src/mailbox.d ./Core/EtherCAT_Src/mailbox.o ./Core/EtherCAT_Src/mailbox.su ./Core/EtherCAT_Src/objdef.cyclo ./Core/EtherCAT_Src/objdef.d ./Core/EtherCAT_Src/objdef.o ./Core/EtherCAT_Src/objdef.su ./Core/EtherCAT_Src/sdoserv.cyclo ./Core/EtherCAT_Src/sdoserv.d ./Core/EtherCAT_Src/sdoserv.o ./Core/EtherCAT_Src/sdoserv.su

.PHONY: clean-Core-2f-EtherCAT_Src

