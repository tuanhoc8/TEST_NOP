/*
 * LPUART1.c
 *
 *  Created on: Oct 5, 2023
 *      Author: phana
 */
/*
 * LPUART1.c
 *
 *  Created on: Oct 4, 2023
 *      Author: phana
 */

#include"s32k.h"
#include"LPUART1.h"

void LPUART1_Init(void){
	/* 	Setting Pin  */
	PCC->PCCn[PCC_PORTC_INDEX] |= (1<<30);		// Enable clock Port C
	PORTC->PCR[6] |= (1<<9);	// LPUART1_RX
	PORTC->PCR[7] |= (1<<9);	// LPUART1_TX

	/* 	Setting source clock  */
	PCC->PCCn[PCC_LPUART1_INDEX] &= ~(1<<30);	// Disable LPUART1 Clock for config

	PCC->PCCn[PCC_LPUART1_INDEX] &= ~(7u<<24);	// Choose SPLLDIV2_CLK
	PCC->PCCn[PCC_LPUART1_INDEX] |= (3u<<24);

	PCC->PCCn[PCC_LPUART1_INDEX] |= (1<<30);	// Enable LPUART1 Clock

	/* 	Setting BaudRate 9600  */

	LPUART1->BAUD |= ~(0x1F<<24); 	// Oversampling Ratio = 16

	LPUART1->BAUD &= ~(0x1FFFu<<0); // Baudrate Modulo Divisor = 39
	LPUART1->BAUD |= (39u<<0);

	/* 	Setting Frame  */
	LPUART1->BAUD &= ~(1<<13);	// One stop bits
	LPUART1->CTRL &= ~(1<<4);	// 8-bit data characters
	LPUART1->CTRL &= ~(1<<1);	// Disable Parity

	/* 	Enable TX and RX  */
	LPUART1->CTRL |= (1<<19);	// Transmit Enable
	LPUART1->CTRL |= (1<<18);	// Receive  Enable
}

void LPUART1_transmit_char(char data) {
	while(!((LPUART1->STAT>>23) & 1)); 	 // Wait for transmit buffer to be empty
	LPUART1->DATA = data;                // Send data
}

void LPUART1_transmit_string(char my_str[]){
	uint32_t i =0;
	while(my_str[i] != '\0'){
		LPUART1_transmit_char(my_str[i]);
		i++;
	}
}

char LPUART1_receive(void){
	char data;
	while(!((LPUART1->STAT>>21) & 1));
	data = LPUART1->DATA;
	return data;
}

void LPUART1_transmit_number(uint8_t a){
	char c;
	c = 48u + (a/10);
	LPUART1_transmit_char(c);
	c = 48u + (a%10);
	LPUART1_transmit_char(c);
}

