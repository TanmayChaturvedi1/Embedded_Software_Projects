#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
//#include"allocate.h"
#include"headers.h"


void print();

<<<<<<< HEAD
void print(){
printf("You have entered the command to allocate memory.\n");
printf("Enter the number of 32-bit words you would like to allocate \n ");
}

void allocate1(){

//int *p;
uint32_t n_bits;
=======
uint32_t n_bits; //Number of 32 bits locations to be allocated
>>>>>>> ee067d12a7089078d22f5404676f0e6844ef9f9b
uint32_t st_index = 1;
uint32_t* st_addr;
uint32_t en_index = 0;


void print(){
printf("You have entered the command to allocate memory.\n");
printf("Enter the number of 32-bit words you would like to allocate \n ");
}

void main(){


print();
scanf("%d",&n_bits); 

st_addr=(uint32_t*)malloc(n_bits * 4); //32 bit=4 bytes;

if (st_addr != NULL){	
	if (n_bits ){
		if (n_bits >=2){
			printf("'%d' 32-bits memory locations have been successfully allocated \n",n_bits);
			printf("The start-address of the allocated memory is %p, and location index is %d \n",st_addr,st_index ); //gives address range to the user//
<<<<<<< HEAD
			printf("The end-address of the allocated memory is %p, and location index is %d \n",st_addr +n_bits, en_index + n_bits ); 

		//	return *st_addr;

=======
			printf("The end-address of the allocated memory is %p, and location index is %d \n",st_addr +n_bits -1 , en_index + n_bits ); 
>>>>>>> ee067d12a7089078d22f5404676f0e6844ef9f9b
			//return *st_addr;
				}
		else {
			printf("'%d' 32-bits memory locations have been successfully allocated\n",n_bits);
                	printf("The start-address of the allocated memory is %p, and location index is %d \n",st_addr, st_index);
		     }
		}  
	else printf("Please enter a number more than 0\n");
}
else printf("Null pointer returned, no memory allocated");
}
}

