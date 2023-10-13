/*
 * gpio.c
 *
 *  Created on: Oct 4, 2023
 *      Author: phana
 */
#include"gpio.h"
#include"s32k.h"

void LED_Init(void)
{
	PCC->PCCn[PCC_PORTD_INDEX] |= (1u<<30);			// Enable Clock Port D
	PORTD->PCR[0] |= (1u<<8);		// Choose GPIO mode PTD0
	PORTD->PCR[15] |= (1u<<8);		// Choose GPIO mode PTD15
	PORTD->PCR[16] |= (1u<<8);		// Choose GPIO mode PTD16

	GPIOD->PDDR |= 1u;				// Set output pin PTD0
	GPIOD->PDDR |= (3u<<15);		// Set output pin PTD15 and PTD16

	GPIOD->PDOR |= 1u;				// Turn off Blue Led
	GPIOD->PDOR |= (3u<<15);		// Turn off Red and Green Led
}

void BUTTON_Init(void)
{
	PCC->PCCn[PCC_PORTC_INDEX] |= (1<<30); 			// Enable Clock Port C
	PORTC->PCR[12] |= (1u<<8);		// Choose GPIO mode PTC12 - BUT1
	PORTC->PCR[13] |= (1u<<8);		// Choose GPIO mode PTC13 - BUT2
	PORTC->PCR[15] |= (1u<<8);		// Choose GPIO mode PTC14 - BUT3
	PORTC->PCR[15] |= (3u);		// Choose GPIO mode PTC14 - BUT3

	PORTC->PCR[12] |= (9u<<16);		// Interrupt on rising edge PTC12
	PORTC->PCR[13] |= (9u<<16);		// Interrupt on rising edge	PTC13
	PORTC->PCR[15] |= (9u<<16);		// Interrupt on rising edge	PTC14

	GPIOC->PDDR &= ~(3u<<12);		// Set input Pin
	GPIOC->PDDR &= ~(1u<<15);
}

void PTM_Output_Init(void)
{
	PCC->PCCn[PCC_PORTD_INDEX] |= (1u<<30);			// Enable Clock Port D
	PORTD->PCR[15] |=  (1u<<9);						// FTM_CH0
}

