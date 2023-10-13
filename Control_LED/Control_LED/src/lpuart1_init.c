#include "init.h"

static volatile signed char indx = 0;

void init_lpuart1(void)
{
	uint32_t baud = 0;
	
	baud |= (208 << 0);
	baud |= (0x09 << 24);
	LPUART1_T->BAUD = baud;
	
	LPUART1_T->CTRL |= (1 << 19);	//Transmit enable
	
	LPUART1_T->FIFO |= (1 << 7);
}

void send_uart(const char * data)
{
	for(unsigned int i = 0; i < strlen(data); i++)
	{
		while(((LPUART1_T->FIFO)&(1 << 23)) == 0){}
		LPUART1_T->DATA = data[i];
	}
}
