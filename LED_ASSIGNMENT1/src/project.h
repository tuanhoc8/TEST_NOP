#ifndef _PROJECT_H_
#define _PROJECT_H_
#include "init.h"
#include "function.h"
#include "interrupt.h"
#define  TIMER_0										100//ms
#define	 TIMER_UART									 	500//ms
#define  TIME_LED_ORIGIN								1000//ms
#define VALUE_INIT										10
typedef enum{
	RED=0,
	GREEN=1,
	BLUE=2
}Color_LED;
void Project_Config(void);
void Project_Do(void);
void SetLED(void);
//void SetLED(void);
extern int8_t counter ;
extern uint8_t count_LED;
extern Color_LED led;
extern int8_t value;
#endif // _PROJECT_H_
