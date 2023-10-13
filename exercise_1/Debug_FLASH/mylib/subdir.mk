################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mylib/LPUART1.c \
../mylib/clock.c \
../mylib/gpio.c \
../mylib/lpit.c 

OBJS += \
./mylib/LPUART1.o \
./mylib/clock.o \
./mylib/gpio.o \
./mylib/lpit.o 

C_DEPS += \
./mylib/LPUART1.d \
./mylib/clock.d \
./mylib/gpio.d \
./mylib/lpit.d 


# Each subdirectory must supply rules for building sources it contributes
mylib/%.o: ../mylib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@mylib/LPUART1.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


