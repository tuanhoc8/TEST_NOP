/*
 * lpit.h
 *
 *  Created on: Oct 4, 2023
 *      Author: phana
 */

#ifndef LPIT_H_
#define LPIT_H_

void LPIT0_Init(void);
void LPIT0_Ch0_Config(uint32_t time, uint8_t mode);
void LPIT0_Ch1_Config(uint32_t time, uint8_t mode);

#endif /* LPIT_H_ */
