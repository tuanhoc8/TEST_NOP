#ifndef	PCC_TYPE_
#define PCC_TYPE_

#include <stdint.h>

#define	PCC_T_BASE	(0x40065080)

typedef struct PCC
{
	volatile uint32_t FTFC;
	volatile uint32_t DMAMUX;
	volatile uint32_t Reserved[2];
	volatile uint32_t FlexCAN0;
	volatile uint32_t FlexCAN1;
	volatile uint32_t FTM3;
	volatile uint32_t ADC1;
	volatile uint32_t Reserved1[3];
	volatile uint32_t FlexCAN2;
	volatile uint32_t LPSPI0;
	volatile uint32_t LPSPI1;
	volatile uint32_t LPSPI2;
	volatile uint32_t Reserved2[2];
	volatile uint32_t PDB1;
	volatile uint32_t CRC;
	volatile uint32_t Reserved3[3];
	volatile uint32_t PDB0;
	volatile uint32_t LPIT;
	volatile uint32_t FTM0;
	volatile uint32_t FTM1;
	volatile uint32_t FTM2;
	volatile uint32_t ADC0;
	volatile uint32_t Reserved4[1];
	volatile uint32_t RTC;
	volatile uint32_t Reserved5[2];
	volatile uint32_t LPTMR0;
	volatile uint32_t Reserved6[8];
	volatile uint32_t PORTA; 
	volatile uint32_t PORTB; 
	volatile uint32_t PORTC;
	volatile uint32_t PORTD;
	volatile uint32_t PORTE; 
	volatile uint32_t Reserved7[6];
	volatile uint32_t SAI0;
	volatile uint32_t SAI1;
	volatile uint32_t Reserved8[4];
	volatile uint32_t FlexIO;
	volatile uint32_t Reserved10[6];
	volatile uint32_t EWM;
	volatile uint32_t Reserved11[4];
	volatile uint32_t LPI2C0;
	volatile uint32_t LPI2C1;
	volatile uint32_t Reserved12[2];
	volatile uint32_t LPUART0;
	volatile uint32_t LPUART1;
	volatile uint32_t LPUART2;
	volatile uint32_t Reserved13;
	volatile uint32_t FTM4;
	volatile uint32_t FTM5;
	volatile uint32_t FTM6;
	volatile uint32_t FTM7;
	volatile uint32_t Reserved14;
	volatile uint32_t CMP0;
	volatile uint32_t Reserved15[2];
	volatile uint32_t QSPI;
	volatile uint32_t Reserved16[2];
	volatile uint32_t ENET;
}	PCC_t;

#define PCC ((PCC_t *)PCC_T_BASE)

#endif
