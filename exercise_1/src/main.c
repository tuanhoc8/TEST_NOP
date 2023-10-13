/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "s32k.h"
#include "clock.h"
#include "lpit.h"
#include "gpio.h"
#include "LPUART1.h"


uint32_t counter_variable __attribute__ ((section(".my_data")));
#define c_var (volatile uint32_t*) 0x20005000u

static uint8_t led_state=0;
static uint8_t LPIT0_Ch0_flag = 0;
static uint8_t LPIT0_Ch1_flag = 0;
static uint8_t button1_flag = 0;
static uint8_t button2_flag = 0;

void Blink_Led(void) __attribute__ ((section(".flash_blinkled")));
void Blink_Led(void)
{
	if (led_state%3 == 0){
		GPIOD->PDOR &= ~(1u<<15);				// Turn on Red Led
		GPIOD->PDOR |= 1u | (1u<<16);
	}
	else{
		// Do nothing
	}

	if (led_state%3 == 1){
		GPIOD->PDOR &= ~(1u<<16);				// Turn on Green Led
		GPIOD->PDOR |= 1u | (1u<<15);
	}
	else{
		// Do nothing
	}

	if (led_state%3 == 2){
		GPIOD->PDOR &= ~(1u);				    // Turn on Blue Led
		GPIOD->PDOR |= (1u<<15) | (1u<<16);
	}
	else{
		// Do nothing
	}
}


void LPUART1_send()
{
	LPUART1_transmit_string("Counter Variable = ");
	LPUART1_transmit_number(*c_var);
	LPUART1_transmit_string("\n");
}


void LPIT0_Ch0_IRQHandler(void)
{
	LPIT0_Ch0_flag = 1;
	LPIT0->MSR |= 1u;                           // Reset Timer 0 Interrupt Flag
}


void LPIT0_Ch1_IRQHandler(void){
	LPIT0_Ch1_flag = 1;
	LPIT0->MSR |= (1u<<1);               		// Reset Timer 1 Interrupt Flag

}


void PORTC_IRQHandler(void)
{
/*		SW2 Interrupt Handler		*/
	if((PORTC->PCR[12]>>24) & 1)
	{
		button1_flag = 1;
		PORTC->PCR[12] |= (1u<<24);				// Reset Interrupt Flag PTC12
	}
	else{
		//	Do nothing
	}

/*		SW3 Interrupt Handler		*/
	if((PORTC->PCR[13]>>24) & 1)
	{
		button2_flag = 1;
		PORTC->PCR[13] |= (1u<<24);		// Reset Interrupt Flag PTC13
	}
	else{
		// Do nothing
	}
}


int main(void)
{
	counter_variable = 10;
	FIRCDIV2_Init_6MHz();
	LED_Init();
	BUTTON_Init();
	LPIT0_Init();
	LPIT0_Ch0_Config(5999999u, 0u);		// Timer0 32-bit Periodic Counter, 1 second
	LPIT0_Ch1_Config(2999999u, 0u);		// Timer1 32-bit Periodic Counter, 0.5 second
	LPUART1_Init();
	LPUART1_transmit_string("LPUART1 is ready....\n");

	NVIC->ISER[1] |= (3u<<16);		// Enable LPIT0 and LPIT1 Interrupt
	NVIC->ISER[1] |= (1u<<29);		// Enable PORTC Interrupt

	LPIT0->SETTEN |= 3u;			// Enable Timer0 and Timer1

	while(1)
	{
		static int8_t time_state = 0;

		if (LPIT0_Ch0_flag == 1)
		{
			void (*ptr_func)(void) = (void (*)(void)) 0x0000a001;
			ptr_func();
			led_state++;
			LPIT0_Ch0_flag = 0;
		}


		if(LPIT0_Ch1_flag == 1)
		{
			LPUART1_send();
			LPIT0_Ch1_flag = 0;
		}


		if(button1_flag == 1)
		{
			if(time_state < 10)
			{
				time_state++;
				(*c_var)++;
			}
			else{
				// Do nothing
			}
			LPIT0->TVAL0 = 5999999u + (600000u*time_state);
			button1_flag = 0;
		}


		if(button2_flag == 1)
		{
			LPIT0->TCTRL0 &= ~(1u);			// Timer 0 Disable
			while((GPIOC->PDIR>>13) & 1)	// Wait for the SW3 released
			{
				if (LPIT0_Ch1_flag == 1)
				{
					LPUART1_send();
					LPIT0_Ch1_flag = 0;
				}
			}
			LPIT0->TCTRL0 |= (1u);			// Timer 0 Enable
			if(time_state >= -7)
			{
				time_state--;
				(*c_var)--;
			}
			else{
				// Do nothing
			}
			LPIT0->TVAL0 = 5999999u + (600000u*time_state);
			button2_flag = 0;
		}
	}
}
