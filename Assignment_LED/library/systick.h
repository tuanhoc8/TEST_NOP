/*
 * systick.h
 *
 *  Created on: Oct 2, 2023
 *      Author: TIN
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include <stdint.h>

#define SysTick_Base ((uint32_t) 0xE000E010)

typedef struct SysTick
{
	volatile uint32_t SYST_CSR; //SysTick Control and Status Register
	volatile uint32_t SYST_RVR; //SysTick Reload Value Register
	volatile uint32_t SYST_CVR; //SysTick Current Value Registe

}SysTick_Type;

void SysTick_Setup();
void delay(uint32_t time);

#endif /* SYSTICK_H_ */
