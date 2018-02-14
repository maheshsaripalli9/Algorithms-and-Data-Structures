################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DataAllZeroes.cpp \
../DataGenerator.cpp \
../DataRandom.cpp \
../DataReverseSorted.cpp \
../DataSorted.cpp \
../Element.cpp \
../InsertionSort.cpp \
../LinkedList.cpp \
../ListSorter.cpp \
../MergeSort.cpp \
../Node.cpp \
../QuickSortOptimal.cpp \
../QuickSortSuboptimal.cpp \
../QuickSorter.cpp \
../SelectionSort.cpp \
../ShellSortOptimal.cpp \
../ShellSortSuboptimal.cpp \
../SortTests.cpp \
../Sorter.cpp \
../VectorSorter.cpp 

OBJS += \
./DataAllZeroes.o \
./DataGenerator.o \
./DataRandom.o \
./DataReverseSorted.o \
./DataSorted.o \
./Element.o \
./InsertionSort.o \
./LinkedList.o \
./ListSorter.o \
./MergeSort.o \
./Node.o \
./QuickSortOptimal.o \
./QuickSortSuboptimal.o \
./QuickSorter.o \
./SelectionSort.o \
./ShellSortOptimal.o \
./ShellSortSuboptimal.o \
./SortTests.o \
./Sorter.o \
./VectorSorter.o 

CPP_DEPS += \
./DataAllZeroes.d \
./DataGenerator.d \
./DataRandom.d \
./DataReverseSorted.d \
./DataSorted.d \
./Element.d \
./InsertionSort.d \
./LinkedList.d \
./ListSorter.d \
./MergeSort.d \
./Node.d \
./QuickSortOptimal.d \
./QuickSortSuboptimal.d \
./QuickSorter.d \
./SelectionSort.d \
./ShellSortOptimal.d \
./ShellSortSuboptimal.d \
./SortTests.d \
./Sorter.d \
./VectorSorter.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


