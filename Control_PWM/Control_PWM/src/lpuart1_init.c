#include "init.h"

static volatile signed char indx = 0;
static volatile unsigned char changeFrez = 0;
char Data_RX[16] = {0};
char Data_TX[20] = {0};

void init_lpuart1(void)
{
	uint32_t baud = 0;
	
	baud |= (208 << 0);
	baud |= (0x09 << 24);
	LPUART1_T->BAUD = baud;
	
	LPUART1_T->CTRL |= (1 << 19);
	LPUART1_T->CTRL |= (1 << 18);
	
	LPUART1_T->FIFO |= (1 << 7);
	
	NVIC->ISER[1] |= (1 << 1);
	LPUART1_T->CTRL |= (1 << 21);
}

void send_uart(const char * data)
{
	for(unsigned int i = 0; i < strlen(data); i++)
	{
		while(((LPUART1_T->FIFO)&(1 << 23)) == 0){}
		LPUART1_T->DATA = data[i];
	}
}

void LPUART1_RxTx_IRQHandler(void)
{
	Data_RX[indx] = (LPUART1_T->DATA & 0xff);
	if(Data_RX[indx] == '.')
	{
		Data_RX[indx] = '\0';
		if(strcmp(Data_RX, "SW1") == 0)
		{
			dutyCycle = dutyCycle + (uint16_t)(dutyCycle * 0.1);
			if(dutyCycle >= frezPWM)
			{
				dutyCycle = frezPWM;
			}
			FTM_0->C1V = dutyCycle;
		}
		else if(strcmp(Data_RX, "SW2") == 0)
		{
			dutyCycle = dutyCycle - (uint16_t)(dutyCycle * 0.1);
			FTM_0->C1V = dutyCycle;
		}
		else if(strcmp(Data_RX, "SW3") == 0)
		{
			changeFrez ^= 1;
			switch(changeFrez)
			{
				case 0:
					frezPWM = 3999;
					dutyCycle = 1999;
					break;
				case 1:
					frezPWM = 1999;
					dutyCycle = 999;
					break;
			}
			FTM_0->MOD = frezPWM;
			FTM_0->C1V = dutyCycle;
		}
		
		else
		{
			send_uart("Invalid command !\n");
		}
		indx = -1;
	}
	indx++;
}
