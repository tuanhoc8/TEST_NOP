/*
 * clock.h
 *
 *  Created on: Oct 4, 2023
 *      Author: phana
 */

#ifndef CLOCK_H_
#define CLOCK_H_

void SOSC_Init_8MHz(void);
void SPLL_Init_12MHz(void);
void FIRCDIV2_Init_6MHz(void);

#endif /* CLOCK_H_ */
