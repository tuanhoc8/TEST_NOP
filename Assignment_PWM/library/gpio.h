/*
 * gpio.h
 *
 *  Created on: Sep 25, 2023
 *      Author: TIN
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>

typedef struct
{
	volatile uint32_t PDOR;
	volatile uint32_t PSOR;
	volatile uint32_t PCOR;
	volatile uint32_t PTOR;
	volatile uint32_t PDIR;
	volatile uint32_t PDDR;
	volatile uint32_t PIDR;
}GPIO_Type;
#define GPIO_A_BASE	((uint32_t)0x400FF000)
#define GPIO_B_BASE ((uint32_t)0x400FF040)
#define GPIO_C_BASE ((uint32_t)0x400FF080)
#define GPIO_D_BASE ((uint32_t)0x400FF0C0)
#define GPIO_E_BASE ((uint32_t)0x400FF100)
#define GPIO_A		((GPIO_Type*)GPIO_A_BASE)
#define GPIO_B		((GPIO_Type*)GPIO_B_BASE)
#define GPIO_C		((GPIO_Type*)GPIO_C_BASE)
#define GPIO_D		((GPIO_Type*)GPIO_D_BASE)
#define GPIO_E		((GPIO_Type*)GPIO_E_BASE)

#define GPIO_INPUT	0u	//Pin is configured as general-purpose input, for the GPIO function. The pin will be high-Z if the port input is disabled in GPIOx_PIDR register
#define GPIO_OUTPUT	1u	//Pin is configured as general-purpose output, for the GPIO function

#define ALT0 0u	//Pin disabled (Alternative 0) (analog)
#define ALT1 1u	//Alternative 1 (GPIO)
#define ALT2 2u	//Alternative 2 (chip-specific)
#define ALT3 3u	//Alternative 3 (chip-specific)
#define ALT4 4u	//Alternative 4 (chip-specific)
#define ALT5 5u	//Alternative 5 (chip-specific)
#define ALT6 6u	//Alternative 6 (chip-specific)
#define ALT7 7u	//Alternative 7 (chip-specific)
#endif /* GPIO_H_ */
