/*
 * pageCalc.c
 *
 *  Created on: Dec 3, 2017
 *      Author: maheshsaripalli
 */




#include <stdio.h>
int main(int argc, char *argv[])
{
unsigned long page;
unsigned long offset;
unsigned long address;
address = atol(argv[1]);
page = address >> 12;
offset = address & 0xfff;
printf("The address %lu contains: \n", address);
printf("page number = %lu\n", page);
printf("offset = %lu\n", offset);
return 0;
}
