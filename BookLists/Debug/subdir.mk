################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Book.cpp \
../BookList.cpp \
../BookListsApp.cpp \
../BookNode.cpp 

OBJS += \
./Book.o \
./BookList.o \
./BookListsApp.o \
./BookNode.o 

CPP_DEPS += \
./Book.d \
./BookList.d \
./BookListsApp.d \
./BookNode.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


