/*
 * LPUART1.h
 *
 *  Created on: Oct 5, 2023
 *      Author: phana
 */

#ifndef LPUART1_H_
#define LPUART1_H_

void LPUART1_Init(void);
char LPUART1_receive(void);
void LPUART1_transmit_char(char data);
void LPUART1_transmit_number(uint8_t a);
void LPUART1_transmit_string(char my_str[]);

#endif /* LPUART1_H_ */
