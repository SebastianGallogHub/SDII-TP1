################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../utilities/fsl_debug_console.c \
../utilities/fsl_io.c \
../utilities/fsl_log.c \
../utilities/fsl_str.c 

OBJS += \
./utilities/fsl_debug_console.o \
./utilities/fsl_io.o \
./utilities/fsl_log.o \
./utilities/fsl_str.o 

C_DEPS += \
./utilities/fsl_debug_console.d \
./utilities/fsl_io.d \
./utilities/fsl_log.d \
./utilities/fsl_str.d 


# Each subdirectory must supply rules for building sources it contributes
utilities/%.o: ../utilities/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL46Z256VLL4 -DCPU_MKL46Z256VLL4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"C:\Users\Joaquin Allione\Documents\MCUXpressoIDE_11.3.0_5222\workspace\MEF_BLINK\board" -I"C:\Users\Joaquin Allione\Documents\MCUXpressoIDE_11.3.0_5222\workspace\MEF_BLINK\source" -I"C:\Users\Joaquin Allione\Documents\MCUXpressoIDE_11.3.0_5222\workspace\MEF_BLINK" -I"C:\Users\Joaquin Allione\Documents\MCUXpressoIDE_11.3.0_5222\workspace\MEF_BLINK\drivers" -I"C:\Users\Joaquin Allione\Documents\MCUXpressoIDE_11.3.0_5222\workspace\MEF_BLINK\utilities" -I"C:\Users\Joaquin Allione\Documents\MCUXpressoIDE_11.3.0_5222\workspace\MEF_BLINK\startup" -I"C:\Users\Joaquin Allione\Documents\MCUXpressoIDE_11.3.0_5222\workspace\MEF_BLINK\CMSIS" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

