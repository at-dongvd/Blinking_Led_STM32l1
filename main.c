//******************** (C) Yifeng ZHU ********************
// @file    main.c
// @author  Yifeng Zhu
// @version V1.0.0
// @date    November-11-2012
// @note    
// @brief   C code for STM32L1xx Discovery Kit
// @note
//          This code is for the book "Embedded Systems with ARM Cortex-M3 
//          Microcontrollers in Assembly Language and C, Yifeng Zhu, 
//          ISBN-10: 0982692625.
// @attension
//          This code is provided for education purpose. The author shall not be 
//          held liable for any direct, indirect or consequential damages, for any 
//          reason whatever. More information can be found from book website: 
//          http://www.eece.maine.edu/~zhu/book
//********************************************************

#include <stdint.h>

/* Standard STM32L1xxx driver headers */
#include "stm32l1xx.h"

/* STM32L1xx Discovery Kit:
    - USER Pushbutton: connected to PA0 (GPIO Port A, PIN 0), CLK RCC_AHBENR_GPIOAEN
    - RESET Pushbutton: connected RESET
    - GREEN LED: connected to PB7 (GPIO Port B, PIN 7), CLK RCC_AHBENR_GPIOBEN 
    - BLUE LED: connected to PB6 (GPIO Port B, PIN 6), CLK RCC_AHBENR_GPIOBEN
    - Linear touch sensor/touchkeys: PA6, PA7 (group 2),  PC4, PC5 (group 9),  PB0, PB1 (group 3)
*/



//******************************************************************************************
//* The main program starts here
//******************************************************************************************


int main(void){  
	// Enable the clock to GPIO Port B	
	RCC->AHBENR		|= RCC_AHBENR_GPIOBEN | RCC_AHBENR_GPIOAEN; 
  
	// Set pin 6,7 I/0 mode as general-purpose output
	// 00 = digital input(default),   01 = digital output
	// 10 = alternative function,     11 = analog
	GPIOB->MODER &= ~(0x03<<(2*6));
	GPIOB->MODER |= 0x01<<(2*6);
	GPIOB->MODER &= ~(0x03<<(2*7));
	GPIOB->MODER |= 0x01<<(2*7);
	
	// Set output type of pin 6,7 as push-pull
	GPIOB->OTYPER &= ~(1<<6);
	GPIOB->OTYPER &= ~(1<<7);
	// Set output speed
	GPIOB->OSPEEDR &= ~(0x03<<(2*6));
	GPIOB->OSPEEDR |= 0x01<<(2*6);
	GPIOB->OSPEEDR &= ~(0x03<<(2*7));
	GPIOB->OSPEEDR |= 0x01<<(2*7);
	// Set I/O as no pull-up pull-down
	// 00 = no pull-up, no pull-down(default)
	// 01 = pull-up, 10 = pull-down, 11 = reserved
	GPIOB->PUPDR &= ~(0x03<<(2*6)) ;
	GPIOB->PUPDR &= ~(0x03<<(2*7)) ;
	// Set pin 0 I/0 mode as general-purpose output
	// 00 = digital input(default),   01 = digital output
	// 10 = alternative function,     11 = analog
	GPIOA->MODER &= ~(0x03);
	
	// Set output type of pin 6,7 as push-pull
	GPIOA->OTYPER &= ~(0x1);
	
	// Set output speed
	GPIOA->OSPEEDR &= ~(0x03);
  GPIOA->OSPEEDR |= (0x01);
	
	// Set I/O as no pull-up pull-down
	// 00 = no pull-up, no pull-down(default)
	// 01 = pull-up, 10 = pull-down, 11 = reserved
	GPIOA->PUPDR &= ~(0x03);
	// Dead loop & program hangs here
	
	while(1){
			
	if(GPIOA->IDR & (1<<0)){
			GPIOB->ODR ^= 1<< 6 | 1<< 7;	  
		}
	}
}