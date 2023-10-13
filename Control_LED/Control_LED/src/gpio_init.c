#include "init.h"

volatile uint8_t button2_is_pressed = 0;

void init_gpio(void)
{
	// set output
	PORT_D->PCR[0] &= ~(0x07u << 8);
	PORT_D->PCR[0] |= (0x01 << 8);
	PORT_D->PCR[15] &= ~(0x07u << 8);
	PORT_D->PCR[15] |= (0x01 << 8);
	PORT_D->PCR[16] &= ~(0x07u << 8);
	PORT_D->PCR[16] |= (0x01 << 8);
	
	GPIOD->PDDR |= (1U << 0);
	GPIOD->PDDR |= (1U << 15);
	GPIOD->PDDR |= (1U << 16);
	
	GPIOD->PSOR = (1 << 0);
	GPIOD->PSOR = (1 << 15);
	GPIOD->PSOR = (1 << 16);
	
	// set input
	PORT_C->PCR[12] &= ~(0x07u << 8);
	PORT_C->PCR[12] |= (0x01 << 8);
	PORT_C->PCR[13] &= ~(0x07u << 8);
	PORT_C->PCR[13] |= (0x01 << 8);
	
	GPIOC->PDDR &= ~(1U << 12);
	GPIOC->PDDR &= ~(1U << 13);
	
	// Enable interrupt rising edge for PTC12, both for PTC13
	PORT_C->PCR[12] &= ~(0x0Fu << 16);
	PORT_C->PCR[12] |= (0x09 << 16);
	PORT_C->PCR[13] &= ~(0x0Fu << 16);
	PORT_C->PCR[13] |= (0x0B << 16);
	NVIC->ISER[1] |= (1u << 29);
	
	// RX LPUART1
	PORT_C->PCR[6] &= ~(0x07u << 8);
	PORT_C->PCR[6] |= (0x02 << 8);
	// TX LPUART1
	PORT_C->PCR[7] &= ~(0x07u << 8);
	PORT_C->PCR[7] |= ((0x02 << 8));
}

void PORTC_IRQHandler(void)
{
	if((PORT_C->PCR[12] & (1 << 24)) != 0)
	{
		PORT_C->PCR[12] |= (1u << 24);
		DELAY += 100;
		counter++;
		if(DELAY > 1500)
		{
			DELAY = 1500;
		}
		if(counter > 20)
		{
			counter = 20;
		}
	}

	else if((PORT_C->PCR[13] & (1 << 24)) != 0)
	{
		PORT_C->PCR[13] |= (1u << 24);
		button2_is_pressed ^= 1;
		if(button2_is_pressed == 0)
		{
			DELAY -= 100;
			counter--;
			if(DELAY < 500)
			{
				DELAY = 500;
			}
			if(counter <= 0)
			{
				counter = 0;
			}
		}
	}
}
