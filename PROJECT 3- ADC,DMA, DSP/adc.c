/*
 * adc.c file
 *
 *  Created on: Dec 4, 2018
 *      Author: Smitha Bhaskar and Tanmay Chaturvedi

 		Description:
 		This is the source file for the ADC code file. 
 		It uses two functions
 		adc_init: Initialises the ADC 
 		uint16_t adc_read: Reads the ADC value 
 */

#include "MKL25Z4.h"
#include "ADC.h"


void adc_init()
{
	//Enabling the Clocks
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;	// ADC 0 clock
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;	// PTB0 clock
	ADC0_CFG1 = 0; // Reset register

	
	ADC0_CFG1 = ADC_CFG1_ADICLK(0)|//Bus clock selected
					    ADC_CFG1_MODE(3)|//16 bit mode for conversion(resolution)
					    ADC_CFG1_ADIV(1);//clock div
	
	ADC0_CFG2 |= ADC_CFG2_ADLSTS(3);
			ADC0_SC3 = 0; // Reset SC3
	ADC0_SC2  |= ADC_SC2_DMAEN_MASK;//Activating DMA
	ADC0_SC1A =31;
	ADC0_SC1A =26;
		

	}

	
	uint16_t adc_read()
	{
		ADC0_SC1A = 0x9A;     // Write to SC1A to start conversion
		while(ADC0_SC2 & ADC_SC2_ADACT_MASK); 	 // Conversion in progress
		while(!(ADC0_SC1A & ADC_SC1_COCO_MASK)); // Run until the conversion is complete
		return ADC0_RA;
	}