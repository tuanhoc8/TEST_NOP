/*
 * lpit.c
 *
 *  Created on: Oct 4, 2023
 *      Author: phana
 */
#include"s32k.h"
#include"lpit.h"

void LPIT0_Init(void)
{
	PCC->PCCn[PCC_LPIT_INDEX] &= ~(1u<<30);	// Ensure CLK is disable for config
	PCC->PCCn[PCC_LPIT_INDEX] |= (3u<<24);	// Choose FIRCDVI2_CLK
	PCC->PCCn[PCC_LPIT_INDEX] |= (1u<<30);	// Enable CLK
	LPIT0->MCR |= (1u<<3);					// Allow timer run in Debug mode
	LPIT0->MCR |= 1u;						// Module Clock Enable
}

void LPIT0_Ch0_Config(uint32_t time, uint8_t mode)
{
	//NVIC->IPR[12] |= 10u;					// Set LPTT0_Ch0 Interrupt highest
	LPIT0->MIER |= 1u;						// Enable Channel 0 Timer Interrupt

	LPIT0->TCTRL0 &= ~(3u<<2); 				// Set Mode
	LPIT0->TCTRL0 |= (mode<<2);

	LPIT0->TVAL0 = time;					// Set time
}

void LPIT0_Ch1_Config(uint32_t time, uint8_t mode)
{
	//NVIC->IPR[12] &= ~(255u<<8);			// Set LPTT0_Ch1 Interrupt highest
	LPIT0->MIER |= (1u<<1);					// Enable Channel 1 Timer Interrupt

	LPIT0->TCTRL1 &= ~(3u<<2); 				// Set Mode
	LPIT0->TCTRL1 |= (mode<<2);

	LPIT0->TVAL1 = time;				    // Set time
}

