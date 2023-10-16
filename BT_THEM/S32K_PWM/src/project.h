#ifndef _PROJECT_H_
#define _PROJECT_H_
#include "init.h"
#include "function.h"
#include "stdio.h"
void Project_Config(void);
void Project_Do(void);
void PWM_Out(void);
void ChangeDutyMode(void);
void PORTC_IRQHandler(void);
void LPIT0_Ch0_IRQHandler(void);
void PWM_Config(FTM_Typedef *FTM_x,PORT_Typedef *PORT_x,uint8_t pin_channel0,uint8_t pin_channel1,uint8_t pin_channel2,uint8_t pin_channel3);
void PWM_Disable(FTM_Typedef *FTM_x,uint8_t channel);
void Can_Recieve_Stop_msg(FlexCAN_Typedef *FlexCAN_x);
void Can_Recieve_Reset_msg(FlexCAN_Typedef *FlexCAN_x);
void Can_Transmit_msg(FlexCAN_Typedef *FlexCAN_x);



#endif // _PROJECT_H_
