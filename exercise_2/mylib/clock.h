/*
 * clock.h
 *
 *  Created on: Oct 4, 2023
 *      Author: phana
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include"s32k.h"
void SPLL_Init_12MHz(void);
void FIRCDIV2_Init_6MHz(void);
void SOSCDIV1_Init(uint8_t mode);

#endif /* CLOCK_H_ */
