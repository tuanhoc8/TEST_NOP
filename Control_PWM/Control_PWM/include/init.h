#ifndef INIT_ALL_
#define INIT_ALL_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include "PCC_Type.h"
#include "PORT_Type.h"
#include "GPIO_Type.h"
#include "SYSTICK_Type.h"
#include "NVIC_Type.h"
#include "SCG_Type.h"
#include "LPIT_Type.h"
#include "LPUART_Type.h"
#include "FTM_Type.h"

// Extern function, variable
extern char Data_RX[16];
extern char Data_TX[20];
extern volatile uint8_t count;
extern volatile uint16_t frezPWM;
extern volatile uint16_t dutyCycle;

#endif
