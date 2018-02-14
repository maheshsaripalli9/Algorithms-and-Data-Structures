################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Node.cpp \
../STLVectorList.cpp \
../SortedList.cpp \
../Sortedvector.cpp \
../TestSuite.cpp 

OBJS += \
./Node.o \
./STLVectorList.o \
./SortedList.o \
./Sortedvector.o \
./TestSuite.o 

CPP_DEPS += \
./Node.d \
./STLVectorList.d \
./SortedList.d \
./Sortedvector.d \
./TestSuite.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


