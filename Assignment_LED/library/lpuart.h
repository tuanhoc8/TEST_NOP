/*
 * lpuart.h
 *
 *  Created on: Oct 4, 2023
 *      Author: TIN
 */

#ifndef LPUART_H_
#define LPUART_H_

#include <stdint.h>

typedef struct
{
	volatile uint32_t VERID;  //Version ID Register
	volatile uint32_t PARAM;  //Parameter Register
	volatile uint32_t GLOBAL; //Global Register
	volatile uint32_t PINCFG; //Pin Configuration Register
	volatile uint32_t BAUD;   //Baud Rate Register
	volatile uint32_t STAT;   //Status Register
	volatile uint32_t CTRL;   //Control Register
	volatile uint32_t DATA;   //Data Register
	volatile uint32_t MATCH;  //Match Address Register
	volatile uint32_t MODIR;  //Modem IrDA Register
	volatile uint32_t FIFO;   //FIFO Register
	volatile uint32_t WATER;  //Watermark Register
}LPUART_Type;
#define LPUART0_Base ((uint32_t)0x4006A000)
#define LPUART1_Base ((uint32_t)0x4006B000)
#define LPUART2_Base ((uint32_t)0x4006C000)
#define UART0 ((LPUART_Type*)LPUART0_Base)
#define UART1 ((LPUART_Type*)LPUART1_Base)
#define UART2 ((LPUART_Type*)LPUART2_Base)

void LPUART1_config(void);

#endif /* LPUART_H_ */
