#include "init.h"

static volatile uint32_t counter = 0;

void init_lpit(void)
{
	LPIT_T->MCR |= (0x01 << 0);
	LPIT_T->MCR |= (0x01 << 3);
	LPIT_T->TCTRL0 &= ~(0x03u << 2);
	LPIT_T->TCTRL1 &= ~(0x03u << 2);
	LPIT_T->MIER |= (1 << 0);
	LPIT_T->MIER |= (1 << 1);
	
	NVIC->ISER[1] |= (1U << 16);
	NVIC->ISER[1] |= (1U << 17);
	
	LPIT_T->TVAL0 = (20000000 / 1000) - 1;
	LPIT_T->TVAL1 = (20000000 / 1) - 1;
	
	LPIT_T->TCTRL1 |= (1 << 0);
}

void LPIT0_Ch0_IRQHandler(void)
{
	LPIT_T->MSR |= (1 << 0);
	counter--;
}

void LPIT0_Ch1_IRQHandler(void)
{
	double dt = dutyCycle;
	double fr = frezPWM;
	double total;
	uint8_t send = 0;
	LPIT_T->MSR |= (1 << 1);
	total = ((dt / fr) * 100);
	send = (uint8_t)(total / 10);
	switch(send)
	{
		case 0:
			send_uart("duty cycle/10 = 0\n");
			break;
		case 1:
			send_uart("duty cycle/10 = 1\n");
			break;
		case 2:
			send_uart("duty cycle/10 = 2\n");
			break;
		case 3:
			send_uart("duty cycle/10 = 3\n");
			break;
		case 4:
			send_uart("duty cycle/10 = 4\n");
			break;
		case 5:
			send_uart("duty cycle/10 = 5\n");
			break;
		case 6:
			send_uart("duty cycle/10 = 6\n");
			break;
		case 7:
			send_uart("duty cycle/10 = 7\n");
			break;
		case 8:
			send_uart("duty cycle/10 = 8\n");
			break;
		case 9:
			send_uart("duty cycle/10 = 9\n");
			break;
		case 10:
			send_uart("duty cycle/10 = 10\n");
			break;
	}
}

void delay_ms(uint32_t ms)
{
	LPIT_T->TCTRL0 |= (1 << 0);
	counter = ms;
	while(counter);
	LPIT_T->TCTRL0 &= ~(1u << 0);
}
