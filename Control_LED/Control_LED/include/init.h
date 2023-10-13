#ifndef INIT_ALL_
#define INIT_ALL_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "PCC_Type.h"
#include "PORT_Type.h"
#include "GPIO_Type.h"
#include "SYSTICK_Type.h"
#include "NVIC_Type.h"
#include "SCG_Type.h"
#include "LPIT_Type.h"
#include "LPUART_Type.h"

// extern variable
extern volatile int8_t counter;
extern volatile uint16_t DELAY;
extern volatile uint8_t button2_is_pressed;

#endif
