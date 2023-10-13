################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lpit.c \
../src/lpuart.c \
../src/main.c \
../src/scg.c \
../src/sim.c \
../src/systick.c 

OBJS += \
./src/lpit.o \
./src/lpuart.o \
./src/main.o \
./src/scg.o \
./src/sim.o \
./src/systick.o 

C_DEPS += \
./src/lpit.d \
./src/lpuart.d \
./src/main.d \
./src/scg.d \
./src/sim.d \
./src/systick.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/lpit.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


