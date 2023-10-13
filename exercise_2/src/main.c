/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "gpio.h"
#include "clock.h"
#include "LPUART1.h"


const uint32_t Freq[2] = {1000u, 500u};		// MOD value for Frequency 2KHz and 4KHz
const uint32_t Scale[2] = {100u, 50u};		/* i = 0 for 2kHz
											   i = 1 for 4KHz	*/

static uint32_t C0V;	// Set duty_cycle
static uint8_t	mode = 0; 	// Choose 2KHz or 4KHz

/* Interrupt Flag for main */
uint8_t button1_flag = 0;
uint8_t button2_flag = 0;
uint8_t button3_flag = 0;

void Delay_100ms();

void PTM0_CH0_PWM_Init(uint8_t prescale, uint32_t mod)
{
	PCC->PCCn[PCC_FTM0_INDEX] &= ~(1u<<30); 	// Ensure clock disable for config
	PCC->PCCn[PCC_FTM0_INDEX] |= (1u<<24);		// SOSCDIV1_CLK Source
	PCC->PCCn[PCC_FTM0_INDEX] |= (1u<<30);		// Enable clock

	FTM0->MODE |= (1u<<3);						// Write protect
	FTM0->SC |= (1u<<16);						// Enable FTM0_CH0
	FTM0->SC |= prescale;						// Prescaler = prescale

	FTM0->COMBINE = 0u;							// FTM mode settings used: DECAPEN0, MCOMBINE0, COMBINE0=0
	FTM0->POL = 0u;								// Polarity for channel 0 is high
	FTM0->MOD = mod - 0x0001;					// Frequency

	FTM0->CONTROLS[0].CnSC |= (1u<<5);			// MSB:MSA = 0b10d: Edge Align PWM
	FTM0->CONTROLS[0].CnSC |= (1u<<3);			// ELSB:ELSA = 0b10: High - True
	FTM0->CONTROLS[0].CnV = 0.5*mod;			// FTM0 CH0 compare value
}

void PORTC_IRQHandler(void)
{
	FTM0->SC &= ~(3u<<3);				// Disable FTM counter
/*		SW2 Interrupt Handler		*/
	if((PORTC->PCR[12]>>24) & 1)
	{
		button1_flag = 1;
		PORTC->PCR[12] |= (1u<<24);		// Reset Interrupt Flag PTC12
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

/*		BUTTON3 Interrupt Handler		*/
	if((PORTC->PCR[15]>>24) & 1)
	{
		Delay_100ms();
		button3_flag = 1;
		PORTC->PCR[15] |= (1u<<24);		// Reset Interrupt Flag PTC12
	}
	else{
		//	Do nothing
	}
}

void Delay_100ms()
{
	uint32_t a = 500000;
	while(a>0)
	{
		a--;
	}
}

int main(void)
{
	SOSCDIV1_Init(1); 						// SOSC = 8MHz, SOSCDIV1 divided by 1
	FIRCDIV2_Init_6MHz();
	BUTTON_Init();							// SW2 and SW3 with pull-down resistor
	LPUART1_Init();							// Init LPUART1 with Baudrate = 9600
	PTM_Output_Init();  					// PTD15 as PWM output
	NVIC->ISER[1] |= (1u<<29); 				// Enable Port C Interrupt
	PTM0_CH0_PWM_Init(2u, Freq[0]);			// Init PWM 2KHz, Duty cycle = 50%
	C0V = 0.5* Freq[0];						// Set default init Duty cycle = 50%
	FTM0->SC |= (3u<<3);
	LPUART1_transmit_string("Initial PWM 2KHz - Duty cycle: 50% \n");

	while(1)
	{
		static uint8_t pwm_state = 5;

		if(button1_flag == 1)
		{
			if (pwm_state < 10){
				pwm_state++;
				C0V += Scale[mode];
				FTM0->CONTROLS[0].CnV = C0V;
			}
			else{
				/// Do nothing
			}

			button1_flag = 0;
			FTM0->SC |= (3u<<3);				// Enable FTM counter
			LPUART1_transmit_string("Duty cycle: ");
			LPUART1_transmit_number(pwm_state);
			LPUART1_transmit_string("\n");
		}


		if(button2_flag == 1)
		{
			if (pwm_state > 0)
			{
				C0V -= Scale[mode];
				pwm_state--;
				FTM0->CONTROLS[0].CnV = C0V;
			}

			else{
				// Do nothing
			}

			button2_flag = 0;
			FTM0->SC |= (3u<<3);				// Enable FTM counter
			LPUART1_transmit_string("Duty cycle: ");
			LPUART1_transmit_number(pwm_state);
			LPUART1_transmit_string("\n");
		}


		else if(button3_flag == 1)
		{
			if (mode == 0){
				LPUART1_transmit_string("Change Frequency to 4KHz\n");
				mode = 1;
			}
			else{
				mode = 0;
				LPUART1_transmit_string("Change Frequency to 2KHz\n");
			}
			pwm_state = 5;
			FTM0->MOD = Freq[mode] - 0x0001;		// Frequency
			C0V = 0.5*Freq[mode];
			FTM0->CONTROLS[0].CnV = C0V;	// FTM0 CH0 compare value
			FTM0->SC |= (3u<<3);					// Enable FTM counter
			button3_flag = 0;
		}


		else{
			// Do nothing
		}
	}
}
