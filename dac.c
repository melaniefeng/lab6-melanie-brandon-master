// dac.c
// This software configures DAC output
// Runs on LM4F120 or TM4C123
// Program written by: put your names here
// Date Created: 3/6/17 
// Last Modified: 3/6/17 
// Lab number: 6
// Hardware connections
// TO STUDENTS "REMOVE THIS LINE AND SPECIFY YOUR HARDWARE********

#include <stdint.h>
#include "tm4c123gh6pm.h"

#define switch1 	
#define switch2
#define switch3 
// Code files contain the actual implemenation for public functions
// this file also contains an private functions and private data

// **************DAC_Init*********************
// Initialize 4-bit DAC, called once 
// Input: none
// Output: none

void DAC_Init(void){
	volatile unsigned long delay;
	SYSCTL_RCGCGPIO_R |= 0x22;
  delay++ ;
	delay++;
  GPIO_PORTB_DIR_R |= 0x0F;	
	GPIO_PORTE_DIR_R &= ~0x07;
	
	GPIO_PORTB_AFSEL_R &= ~0x0F;
	GPIO_PORTE_AFSEL_R &= ~0x07;
	
  GPIO_PORTB_DEN_R |= 0x0F;	
	GPIO_PORTE_DEN_R |= 0x07;
	
}

// **************DAC_Out*********************
// output to DAC
// Input: 4-bit data, 0 to 15 
// Output: none


void DAC_Out(uint32_t data){
	
		GPIO_PORTB_DATA_R |= data;
		
		

	
}


