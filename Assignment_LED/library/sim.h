/*
 * sim.h
 *
 *  Created on: Sep 27, 2023
 *      Author: TIN
 */

#ifndef SIM_H_
#define SIM_H_

#include <stdint.h>

typedef struct
{
	volatile uint32_t RESERVED_0;
	volatile uint32_t CHIPCTL;                           /**< Chip Control register, offset: 0x4 */
	volatile uint32_t RESERVED_1;
	volatile uint32_t FTMOPT0;                           /**< FTM Option Register 0, offset: 0xC */
	volatile uint32_t LPOCLKS;                           /**< LPO Clock Select Register, offset: 0x10 */
	volatile uint32_t RESERVED_2;
	volatile uint32_t ADCOPT;                            /**< ADC Options Register, offset: 0x18 */
	volatile uint32_t FTMOPT1;                           /**< FTM Option Register 1, offset: 0x1C */
	volatile uint32_t MISCTRL0;                          /**< Miscellaneous control register 0, offset: 0x20 */
	volatile uint32_t SDID;                              /**< System Device Identification Register, offset: 0x24 */
	volatile uint32_t RESERVED_3[6];
	volatile uint32_t PLATCGC;                           /**< Platform Clock Gating Control Register, offset: 0x40 */
	volatile uint32_t RESERVED_4[2];
	volatile uint32_t FCFG1;                             /**< Flash Configuration Register 1, offset: 0x4C */
	volatile uint32_t RESERVED_5;
	volatile uint32_t UIDH;                              /**< Unique Identification Register High, offset: 0x54 */
	volatile uint32_t UIDMH;                             /**< Unique Identification Register Mid-High, offset: 0x58 */
	volatile uint32_t UIDML;                             /**< Unique Identification Register Mid Low, offset: 0x5C */
	volatile uint32_t UIDL;                              /**< Unique Identification Register Low, offset: 0x60 */
	volatile uint32_t RESERVED_6;
	volatile uint32_t CLKDIV4;                           /**< System Clock Divider Register 4, offset: 0x68 */
	volatile uint32_t MISCTRL1;                          /**< Miscellaneous Control register 1, offset: 0x6C */
}SIM_Type;
#define SIM_BASE   ((uint32_t)0x40048000u)
#define SIM 	   ((SIM_Type *)SIM_BASE)

void CLKOUT_config(void);

#endif /* SIM_H_ */
