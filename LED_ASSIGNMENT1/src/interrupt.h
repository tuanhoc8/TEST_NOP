#ifndef _INTERRUPT_H_
#define _INTERRUPT_H_
#include "s32k144.h"
#include "stdio.h"
#include "project.h"
#define  BUTTON(X)										    (11+X)//pin 12 PORT C

void LPIT0_Ch0_IRQHandler(void);
void LPIT0_Ch1_IRQHandler(void);
void PORTC_IRQHandler(void);
void changeToArrayChar(char str[5],int8_t number);
void sendUart(uint8_t *data_TX,LPUART_Typedef *LPUART_x);
extern uint8_t flag_LED;		// timer 0
extern uint8_t flag_BUTTON;		// PORT C

#endif //_INTERRUPT_H_
