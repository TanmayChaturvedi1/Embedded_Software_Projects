#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#include"Embedded_SW_Project1/PROJECT 1- COMMAND LINE UTILITY/INC/allocate.h"
#include"Embedded_SW_Project1/PROJECT 1- COMMAND LINE UTILITY/INC/global_variables.h"
#include"Embedded_SW_Project1/PROJECT 1- COMMAND LINE UTILITY/INC/exec_time.h"

void write_pattern();
 uint32_t output_write;

void write_pattern(){

uint16_t seed;

uint32_t start_clock = 0;
uint32_t end_clock = 1;

(double)exec_time(start_clock);


printf("Enter the index of address where you wish to store the pattern \n");
scanf("%d",&user_index);

printf("Enter a seed value which is any number within the range 1111-9999 \n ");
scanf("%hd", &seed);

//pseudo random number generator algorithm

__uint64_t x=seed;
x^=x >> 11;
x^=x << 13;
x^=x >> 15;
x^=x << 17;

 output_write =x;

printf("The pseudo random generated number is %d \n ", output_write);

*((volatile uint32_t *)(st_addr + user_index - 1))=output_write; 
double time_calc = exec_time(end_clock);

printf("The memory location has been updated with the pseudo random number \n");

printf("execution time in micro seconds = %f\n", time_calc*1000000);

}




