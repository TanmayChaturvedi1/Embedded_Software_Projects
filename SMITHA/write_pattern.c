#include<stdio.h>
#include<stdlib.h>
#include"allocate.h"
#include<stdint.h>

void write_pattern();

void write_pattern(){

extern uint32_t* st_addr;
extern uint32_t st_index;
extern uint32_t en_index;
extern uint32_t n_bits;
extern uint32_t user_index;
u_int16_t seed;



printf("Enter the address where you wish to store the pattern \n");
scanf("%d",&user_index);

printf("Enter the number of 32-bit words you would like to allocate for the pattern \n ");
scanf("%d", &n_bits);

extern uint32_t allocated_memory_wp=(int*)malloc(n * 4);

printf("Enter a seed value which is any number within the range 1111-9999 \n ");
scanf("%hd", &seed);

//pseudo random number generator algorithm

__uint64_t x=seed;
x^=x >> 11;
x^=x << 13;
x^=x >> 15;
x^=x << 17;

extern uint64_t output_write =x;

printf("The pseudo random generated number is %d \n ", output_write);

*((volatile int *)user_index)=output_write; 

printf("The memory location has been updated with the pseudo random number \n");

}





