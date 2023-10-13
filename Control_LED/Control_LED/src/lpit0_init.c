#include "init.h"

static volatile uint32_t timer = 0;

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
	LPIT_T->TVAL1 = (20000000 / 2) - 1;
	
	LPIT_T->TCTRL1 |= (1 << 0);
}

void LPIT0_Ch0_IRQHandler(void)
{
	LPIT_T->MSR |= (1 << 0);
	timer--;
}

void LPIT0_Ch1_IRQHandler(void)
{
	LPIT_T->MSR |= (1 << 1);
	switch(counter)
	{
		case 0:
			send_uart("counter = 0\n");
			break;
		case 1:
			send_uart("counter = 1\n");
			break;
		case 2:
			send_uart("counter = 2\n");
			break;
		case 3:
			send_uart("counter = 3\n");
			break;
		case 4:
			send_uart("counter = 4\n");
			break;
		case 5:
			send_uart("counter = 5\n");
			break;
		case 6:
			send_uart("counter = 6\n");
			break;
		case 7:
			send_uart("counter = 7\n");
			break;
		case 8:
			send_uart("counter = 8\n");
			break;
		case 9:
			send_uart("counter = 9\n");
			break;
		case 10:
			send_uart("counter = 10\n");
			break;
		case 11:
			send_uart("counter = 11\n");
			break;
		case 12:
			send_uart("counter = 12\n");
			break;
		case 13:
			send_uart("counter = 13\n");
			break;
		case 14:
			send_uart("counter = 14\n");
			break;
		case 15:
			send_uart("counter = 15\n");
			break;
		case 16:
			send_uart("counter = 16\n");
			break;
		case 17:
			send_uart("counter = 17\n");
			break;
		case 18:
			send_uart("counter = 18\n");
			break;
		case 19:
			send_uart("counter = 19\n");
			break;
		case 20:
			send_uart("counter = 20\n");
			break;
	}
}

void delay_ms(uint32_t ms)
{
	LPIT_T->TCTRL0 |= (1 << 0);
	timer = ms;
	while(timer);
	while(button2_is_pressed);
	LPIT_T->TCTRL0 &= ~(1u << 0);
}
