################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/clock_init.c \
../src/ftm0_init.c \
../src/gpio_init.c \
../src/lpit0_init.c \
../src/lpuart1_init.c \
../src/main.c 

OBJS += \
./src/clock_init.o \
./src/ftm0_init.o \
./src/gpio_init.o \
./src/lpit0_init.o \
./src/lpuart1_init.o \
./src/main.o 

C_DEPS += \
./src/clock_init.d \
./src/ftm0_init.d \
./src/gpio_init.d \
./src/lpit0_init.d \
./src/lpuart1_init.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/clock_init.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


