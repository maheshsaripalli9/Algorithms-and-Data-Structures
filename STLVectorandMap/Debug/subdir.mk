################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Constitution.cpp \
../TimedContainer.cpp \
../Word.cpp \
../WordMap.cpp \
../WordVector.cpp 

OBJS += \
./Constitution.o \
./TimedContainer.o \
./Word.o \
./WordMap.o \
./WordVector.o 

CPP_DEPS += \
./Constitution.d \
./TimedContainer.d \
./Word.d \
./WordMap.d \
./WordVector.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


