################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Part1.c \
../src/Part2.c \
../src/Part3.c \
../src/Part4.c 

OBJS += \
./src/Part1.o \
./src/Part2.o \
./src/Part3.o \
./src/Part4.o 

C_DEPS += \
./src/Part1.d \
./src/Part2.d \
./src/Part3.d \
./src/Part4.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/onur/Documents/GIT_Repos/HWs/HW4/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


