################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/function.c \
../src/init.c \
../src/main.c \
../src/project.c 

OBJS += \
./src/function.o \
./src/init.o \
./src/main.o \
./src/project.o 

C_DEPS += \
./src/function.d \
./src/init.d \
./src/main.d \
./src/project.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/function.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


