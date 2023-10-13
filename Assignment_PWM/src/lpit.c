/*
 * lpit.c
 *
 *  Created on: Oct 4, 2023
 *      Author: TIN
 */
#include "lpit.h"
#include "pcc.h"
#include "nvic.h"

void LPIT_config()
{
	/*	clock source bit 24 -26 : option 7 = 111	*/
	PCC->PCC_LPIT |= (7u<<24u);

	/*	enable clock source bit 30	*/
	PCC->PCC_LPIT |= (1u<<30u);

	/*	module clock enable	MCR[M_CEN] bit 0 	*/
	LPIT->MCR |= (1u<<0u);

	/*	Run in debug mode MCR[DBG_EN] bit 3	*/
	LPIT->MCR	|=	(1u<<3u);

	/*	Configure channel TCTRL[MODE] bit 2-3		*/
	LPIT->TCTRL0 &=	~(3u<<2u);

	/* 	Timer channel TCTRL[T_EN] bit 0	*/
	LPIT->TCTRL0	|=	(1u<<0u);
}

void LPIT_INTERRUPT_config()
{
	/*	clock source bit 24 -26 : option 7 = 111	*/
	PCC->PCC_LPIT |= (7u<<24u);

	/*	enable clock source bit 30	*/
	PCC->PCC_LPIT |= (1u<<30u);

	/*	module clock enable	MCR[M_CEN] bit 0 	*/
	LPIT->MCR |= (1u<<0u);

	/*	Run in debug mode MCR[DBG_EN] bit 3	*/
	LPIT->MCR	|=	(1u<<3u);

	/*	Configure channel TCTRL[MODE] bit 2-3		*/
	LPIT->TCTRL0 &=	~(3u<<2u);

	/* 	Timer channel TCTRL[T_EN] bit 0	*/
	LPIT->TCTRL0	|=	(1u<<0u);

	/*	Enable NVIC for LPIT channel 0	*/
	/*	32 + 16 = 48 => ID NVIC interrupt LPIT- table excel attack Reference manual*/
	NVIC_ISER1->SETENA_bits	|= (1u<<16u);

	/*	clock source bit 24 -26 : option 7 = 011	*/
	PCC->PCC_LPIT |= (3u<<24u);

	/*	enable clock source bit 30	*/
	PCC->PCC_LPIT |= (1u<<30u);

	/*	Enable chanel_0 timer interrupt */
	LPIT->MIER |= (1u<<0u);

	/*	module clock enable	MCR[M_CEN] bit 0 	*/
	LPIT->MCR |= (1u<<0u);

	/*	Run in debug mode MCR[DBG_EN] bit 3	*/
	LPIT->MCR |= (1u<<3u);

		/*	Set value timer start	*/
	LPIT->TVAL0 = 0x2DC6C00;

	/*	Configure channel TCTRL[MODE] bit 2-3		*/
	LPIT->TCTRL0 &= ~(3u<<2u);

	/* 	Timer channel TCTRL[T_EN] bit 0	*/
	LPIT->TCTRL0	|= (1u<<0u);
}

void LPIT0_Ch0_IRQHandler (void)
{
	/*
	Ex_u4_Clock_1s = 1;
	Ex_u4_ClockOffLed = 1;
	Ex_u4_ClockBlindLed1S = 1;
	*/
	/*	Clear Flag interrupt Timer	*/
	LPIT->MSR = 0x1;
}
