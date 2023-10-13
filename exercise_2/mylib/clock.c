/*
 * clock.c
 *
 *  Created on: Oct 4, 2023
 *      Author: phana
 */
#include "clock.h"

void SOSCDIV1_Init(uint8_t mode)
{
	SCG->SOSCCFG |= (1<<2);					//  EREFS = 1: Internal Crystal oscillator
	SCG->SOSCCFG |= (1<<3); 				//  HGO   = 1: High-gain operator
	SCG->SOSCCFG &= ~(3u<<4);				//  High Frequency range
	SCG->SOSCCFG |= (3u<<4);

	SCG->SOSCDIV &= ~(7u);					//  Setting divided by mode
	SCG->SOSCDIV |=  mode;

	SCG->SOSCCSR |= (1<<0);					//  Enable System OSC
	while(!((SCG->SOSCCSR>>24) & 1));		//  Ensure system OSC is enable and output clock is valid
}


void SPLL_Init_12MHz(void)
{
	SCG->SPLLCSR &= ~(1u<<0);			// SPLL Disable
	SCG->SPLLDIV |= (1u<<8);		    // SPLLDIV2 divided by 2
	SCG->SPLLCFG &= !(1u<<0);			// System OSC
	SCG->SPLLCFG |= (7u<<8);			// PREDIV = 7

	SCG->SPLLCFG &= ~(31u<<16);			// Multiply Factor = 24
	SCG->SPLLCFG |= (8u<<16);

	SCG->SPLLCSR |= (1u<<0);				// Enable
	while(!((SCG->SPLLCSR>>24) & 1));	// Ensure SPLL is valid
}

void FIRCDIV2_Init_6MHz(void)
{
	SCG->FIRCCSR &= ~(1u<<0);			//  Disable Fast IRC
	SCG->FIRCCFG &= ~(3u<<0);			//  Fast IRC is trimmed to 48 MHz

	SCG->FIRCDIV &= ~(7u<<8);			//  FISCRDIV2 divided by 8
	SCG->FIRCDIV |= (4u<<8);

	SCG->FIRCCSR |= (1<<0);				//  Enable Fast IRC
	while(!((SCG->FIRCCSR>>24) & 1));	//  Ensure FIRC is valid
}

