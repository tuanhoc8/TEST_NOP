/*
 * lpuart.c
 *
 *  Created on: Oct 4, 2023
 *      Author: TIN
 */
#include "lpuart.h"
#include "pcc.h"
#include "port.h"
#include "gpio.h"

void LPUART1_config(void)
{
	uint32_t value;
	//Setting Tx/Rx pin
	PCC->PCC_PORTC |= (1U << 30);
	PORT_C->PORT_PCR[6] |= (2U << 8); //Alternative 2 - RX
	PORT_C->PORT_PCR[7] |= (2U << 8); //Alternative 2 - TX
	//Select source LPUART
	PCC->PCC_LPUART1 |= (0U << 30); //Disable CGC
	PCC->PCC_LPUART1 |= (3U << 24); //FIRCDIV2  24Mhz
	PCC->PCC_LPUART1 |= (1U << 30);
	//Setting baud rate
	value = UART1->BAUD;
	value &= ~((15U << 24) | (4U << 0));
	value |= ((125U << 0) | (9U << 24));  //Baurd rate = 19200 OSR(9+1)
	//value |= ((250U << 0) | (9U << 24));  //Baurd rate = 9600 OSR(9+1)
	UART1->BAUD = value;
	//Setting Frame
	UART1->BAUD |= (0U << 13); //Select Stop Bit Number: 1 stop bit
	UART1->CTRL |= ((0U << 1) | (0U << 4)); //[0]Parity type, [1]Parity enable, [4]8-bit or 9-bit mode select
	//UART1->CTRL |= ((1U << 0) | (1U << 1) | (1U << 4)); //Set data characters number (If enable PARITY -> data = 9 bits), Set parity bit: CTRL[PE]
	//Enable transmitter & receiver
	UART1->CTRL |= ((1U << 19) | (1U << 18));  //Transmitter Enable: CTRL[TE], Receiver Enable: CTRL[RE]

}
