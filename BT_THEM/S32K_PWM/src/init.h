#ifndef _INIT_H_
#define _INIT_H_
#include "s32k144.h"

/******************************************************************************/
/*                                                                            */
/*                                 FUNCTION                                   */
/*                                                                            */
/******************************************************************************/
void System_Clock_Out_Config(uint8_t EXTAL_OR_XTAL);
void GPIO_Config_Clock(GPIO_Typedef *GPIOx);
void GPIO_Config_Mode(PORT_Typedef *PORT_x,GPIO_Typedef *GPIOx,uint32_t pin,uint8_t MODE_INPUT_OUTPUT);
void System_Tick_Config(void);
void LPUART_Config(LPUART_Typedef *LPUART_x,PORT_Typedef *PORT_x,uint8_t pin_RX,uint8_t pin_TX,uint8_t interrupt);
void LPIT_Clock_Source(void);
void LPIT_Config(uint8_t channel,uint32_t ms,uint8_t interrupt);
void LPSPI_Config(LPSPI_Typedef *LPSPI_x);
void CLKOUT_Config(uint8_t source,PORT_Typedef *PORT_x,uint8_t pin);
void PORT_Config(PORT_Typedef *PORT_x);
void LPI2C_Config(LPI2C_Typedef *LPI2C_x,PORT_Typedef *PORT_x,uint8_t pin_SDA,uint8_t pin_SCL);
void Edge_Align_PWM_Config(FTM_Typedef *FTM_x,PORT_Typedef *PORT_x,uint8_t pin_channel0,uint8_t pin_channel1,uint8_t pin_channel2,uint8_t pin_channel3);
void Center_Align_PWM_Config(FTM_Typedef *FTM_x,PORT_Typedef *PORT_x,uint8_t pin_channel0,uint8_t pin_channel1,uint8_t pin_channel2,uint8_t pin_channel3);
void CAN_Init(FlexCAN_Typedef *FlexCAN_x,uint16_t id,PORT_Typedef *PORT_x,uint8_t Tx,uint8_t Rx);
#endif // _INIT_H_
