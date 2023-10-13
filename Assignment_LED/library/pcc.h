/*
 * pcc.h
 *
 *  Created on: Sep 25, 2023
 *      Author: TIN
 */

#ifndef PCC_H_
#define PCC_H_

#include <stdint.h>

typedef struct
{
	volatile uint32_t PCC_FTFC;
	volatile uint32_t PCC_DMAMUX;
	volatile uint32_t RES_0;
	volatile uint32_t RES_1;
	volatile uint32_t PCC_FlexCAN0;
	volatile uint32_t PCC_FlexCAN1;
	volatile uint32_t PCC_FTM3;
	volatile uint32_t PCC_ADC1;
	volatile uint32_t RES_2;
	volatile uint32_t RES_3;
	volatile uint32_t RES_4;
	volatile uint32_t PCC_FlexCAN2;
	volatile uint32_t PCC_LPSPI0;
	volatile uint32_t PCC_LPSPI1;
	volatile uint32_t PCC_LPSPI2;
	volatile uint32_t RES_5;
	volatile uint32_t RES_6;
	volatile uint32_t PCC_PDB1;
	volatile uint32_t PCC_CRC;
	volatile uint32_t RES_7;
	volatile uint32_t RES_8;
	volatile uint32_t RES_9;
	volatile uint32_t PCC_PDB0;
	volatile uint32_t PCC_LPIT;
	volatile uint32_t PCC_FTM0;
	volatile uint32_t PCC_FTM1;
	volatile uint32_t PCC_FTM2;
	volatile uint32_t PCC_ADC0;
	volatile uint32_t RES_10;
	volatile uint32_t PCC_RTC;
	volatile uint32_t RES_11;
	volatile uint32_t RES_12;
	volatile uint32_t PCC_LPTMA0;
	volatile uint32_t RES_13;
	volatile uint32_t RES_14;
	volatile uint32_t RES_15;
	volatile uint32_t RES_16;
	volatile uint32_t RES_17;
	volatile uint32_t RES_18;
	volatile uint32_t RES_19;
	volatile uint32_t RES_20;
	volatile uint32_t PCC_PORTA;
	volatile uint32_t PCC_PORTB;
	volatile uint32_t PCC_PORTC;
	volatile uint32_t PCC_PORTD;
	volatile uint32_t PCC_PORTE;
	volatile uint32_t RES_21;
	volatile uint32_t RES_22;
	volatile uint32_t RES_23;
	volatile uint32_t RES_24;
	volatile uint32_t RES_25;
	volatile uint32_t RES_26;
	volatile uint32_t PCC_SAI0;
	volatile uint32_t PCC_SAI1;
	volatile uint32_t RES_27;
	volatile uint32_t RES_28;
	volatile uint32_t RES_29;
	volatile uint32_t RES_30;
	volatile uint32_t PCC_FlexIO;
	volatile uint32_t RES_31;
	volatile uint32_t RES_32;
	volatile uint32_t RES_33;
	volatile uint32_t RES_34;
	volatile uint32_t RES_35;
	volatile uint32_t RES_36;
	volatile uint32_t PCC_EWM;
	volatile uint32_t RES_37;
	volatile uint32_t RES_38;
	volatile uint32_t RES_39;
	volatile uint32_t RES_40;
	volatile uint32_t PCC_LPI2C0;
	volatile uint32_t PCC_LPI2C1;
	volatile uint32_t RES_41;
	volatile uint32_t RES_42;
	volatile uint32_t PCC_LPUART0;
	volatile uint32_t PCC_LPUART1;
	volatile uint32_t PCC_LPUART2;
	volatile uint32_t RES_43;
	volatile uint32_t PCC_FTM4;
	volatile uint32_t PCC_FTM5;
	volatile uint32_t PCC_FTM6;
	volatile uint32_t PCC_FTM7;
	volatile uint32_t RES_44;
	volatile uint32_t PCC_CMP0;
	volatile uint32_t RES_45;
	volatile uint32_t RES_46;
	volatile uint32_t PCC_QSPI;
	volatile uint32_t RES_47;
	volatile uint32_t RES_48;
	volatile uint32_t PCC_ENET;
}PCC_Type;
#define PCC_BASE	((uint32_t)0x40065080)
#define PCC			((PCC_Type*)PCC_BASE)

#endif /* PCC_H_ */
