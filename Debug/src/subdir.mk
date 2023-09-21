################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/SortedList.cpp \
../src/StressOS.cpp 

CPP_DEPS += \
./src/SortedList.d \
./src/StressOS.d 

OBJS += \
./src/SortedList.o \
./src/StressOS.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/SortedList.d ./src/SortedList.o ./src/StressOS.d ./src/StressOS.o

.PHONY: clean-src

