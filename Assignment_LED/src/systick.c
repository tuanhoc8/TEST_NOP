/*
 * systick.c
 *
 *  Created on: Oct 2, 2023
 *      Author: TIN
 */
#include "systick.h"

#define Timer ((SysTick_Type*)SysTick_Base)
#define CORE_CLK 4800000 //8MHz

void SysTick_Setup()
{
	Timer->SYST_CSR = (1u << 1);
	Timer->SYST_RVR = (CORE_CLK - 1); //100ms
	Timer->SYST_CVR = 0;
	Timer->SYST_CSR |= ((1<<0)|(0<<1)|(1<<2));
	while(!(Timer->SYST_CSR &(1<<16)))
	{
		//do nothing
	}
}

//void SysTick_Setup()
//{
//	Timer->SYST_CSR = 0;
//	Timer->SYST_RVR = (CORE_CLK - 1); //100ms
//	Timer->SYST_CVR = 0;
//	Timer->SYST_CSR |= ((1 << 0) | (0 << 1) | (1 << 2));
//	while (!(Timer->SYST_CSR & (1 << 16)))
//	{
//		//do nothing
//	}
//}

void delay(uint32_t time)
{
	for(uint32_t i=0 ; i < time; i++)
	{
		SysTick_Setup();
	}
}

