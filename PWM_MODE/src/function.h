#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include "s32k144.h"
void GPIO_SetBits(GPIO_Typedef *GPIOx,uint8_t pin,uint8_t LEVEL);
uint8_t GPIO_ReadBits(GPIO_Typedef *GPIOx,uint8_t pin);
void Delay_ms(uint32_t ms);
void SysTick_Handler(void);
void LPUART1_RxTx_IRQHandler(void);
void sendUart(uint8_t *data_TX,LPUART_Typedef *LPUART_x);

extern uint8_t size_RX;
extern char Data_RX;
#endif // _FUNCTION_H_
