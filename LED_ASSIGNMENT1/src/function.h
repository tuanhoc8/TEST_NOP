#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include "s32k144.h"
void GPIO_SetBits(GPIO_Typedef *GPIOx,uint8_t pin,uint8_t LEVEL);
uint8_t GPIO_ReadBits(GPIO_Typedef *GPIOx,uint8_t pin);
void Delay_ms(uint32_t ms);
void Delay_us(uint32_t us);
void SysTick_Handler(void);
void LPUART1_RxTx_IRQHandler(void);


extern uint8_t size_RX;
extern char Data_RX;
extern uint8_t status;
#endif // _FUNCTION_H_
