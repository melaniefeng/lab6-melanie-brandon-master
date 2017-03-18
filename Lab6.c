// Lab6.c
// Runs on LM4F120 or TM4C123
// Use SysTick interrupts to implement a 4-key digital piano
// MOOC lab 13 or EE319K lab6 starter
// Program written by: put your names here
// Date Created: 3/6/17 
// Last Modified: 3/6/17 
// Lab number: 6
// Hardware connections
// TO STUDENTS "REMOVE THIS LINE AND SPECIFY YOUR HARDWARE********


#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "Sound.h"
#include "Piano.h"
#include "TExaS.h"

// basic functions defined at end of startup.s
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts


#include "DAC.h"
int main(void){       
  TExaS_Init(SW_PIN_PE3210,DAC_PIN_PB3210,ScopeOn);    // bus clock at 80 MHz
  Piano_Init();
  Sound_Init(0);	
	
  unsigned long Data; // 0 to 15 DAC output
  PLL_Init();         // like Program 4.6 in the book, 80 MHz
  DAC_Init();
  for(;;) {
    DAC_Out(Data);
    Data = 0x0F&(Data+1); // 0,1,2...,14,15,0,1,2,...
  }
}

/*int main(void){      
  TExaS_Init(SW_PIN_PE3210,DAC_PIN_PB3210,ScopeOn);    // bus clock at 80 MHz
  Piano_Init();
  Sound_Init(0);
	
	

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
	
	
  // other initialization
  EnableInterrupts();
  while(1){ 
  }    
}*/


