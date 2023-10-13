#include "scg.h"

void SCG_SOSC_80MHz_config(void)
{
	/*SOSC 8Mhz to create CORE_CLK 80MHz, BUS_CLK 40MHz, FLASH_CLK 26.67MHz, SPLLDIV1 80MHz, SPLLDIV2 40Mhz	*/

	uint32_t value;
	/* Wait unlock bit in CSR Register */
	while (((SCG->SOSCCSR) & (1 << 23)) == 1);
	/* Disable ClkSource bit */
	value = SCG->SOSCCSR;
	value |= (0U << 0);
	SCG->SOSCCSR = value;
	/* Set value to CFG Register */
	value = SCG->SOSCCFG;
	value &= ~(3U << 4); //clear bit 4 and 5 (RANGE) to 0 before write value 10
	value |= ((2u << 4) | (1U << 2)); //Medium frequency(10) | Internal crystal oscillator
	SCG->SOSCCFG = value;
	/* Wait unlock bit in SOSCCSR Register */
	while (((SCG->SOSCCSR) & (1 << 23)) == 1);
	/* System OSC Enable */
	value = SCG->SOSCCSR;
	value |= (1U << 0);
	SCG->SOSCCSR = value;
	/* Wait for bit System OSC valid */
	while (((SCG->SOSCCSR) & (1 << 24)) == 0);
	/* Configure for the system PLL */
	/* check LK == 0. if true then write. check before write */
	while (((SCG->SPLLCSR) & (1 << 23)) == 1);
	/* Disable System SPLL bit */
	value = SCG->SPLLCSR;
	value |= (0U << 0);
	SCG->SPLLCSR = value;

	/* Configure for the register SCG_SPLLCFG */
	value = SCG->SPLLCFG;
	value |= ((24U << 16) | (1U << 8) | (0U << 0)); //MULT = 24: multiply by 40 | PREDIV = 1: divide by 2 | Source: internal crystal oscillator
	SCG->SPLLCFG = value;
	/* Configure for the register SCG_SPLLDIV */
	value = SCG->SPLLDIV;
	value |= ((2u << 8) | (1u << 0)); //SPLLDIV2 = 2: divided by 2 | SPLLDIV1 = 1: divided by 1
	SCG->SPLLDIV = value;
	/* Wait unlock bit in SPLLCSR Register */
	while (((SCG->SPLLCSR) & (1 << 23)) == 1);
	/* Enable System SPLL bit */
	value = SCG->SPLLCSR;
	value |= (1U << 0);
	SCG->SPLLCSR = value;
	/* Wait for bit System PLL valid */
	while ((SCG->SPLLCSR >> 24) == 0); //check bit 24
	/* Configure for the DIVCORE and DIVBUS */
	value = SCG->RCCR;
	value &= ~(15U << 24);
	value |= ((6U << 24) | (0U << 16) | (1U << 4) | (2U << 0)); //System PLL (0110) | DIVCORE divided by 1 | DIVBUS divided by 2 | DIVSLOW divided by 3
	SCG->RCCR = value;

	while (((SCG->CSR) & (0xfu << 24)) != ((SCG->RCCR) & (0xfu << 24)));
}

void SCG_FIRC_80MHz_config(void)
{
	/*SOSC 8Mhz to create CORE_CLK 80MHz, BUS_CLK 40MHz, FLASH_CLK 26.67MHz, SPLLDIV1 80MHz, SPLLDIV2 20Mhz	*/

	uint32_t value;

	//Configure for the system PLL
	//check LK == 0. if true then write. check before write
	while (((SCG->SPLLCSR) & (1 << 23)) == 1);
	/* Disable System SPLL bit */
	value = SCG->SPLLCSR;
	value |= (0U << 0);
	SCG->SPLLCSR = value;

	/* Configure for the register SCG_SPLLCFG */
	value = SCG->SPLLCFG;
	value |= ((4U << 16) | (5U << 8) | (1U << 0)); //MULT = 4: multiply by 20 | PREDIV = 5: divide by 6 | Source: Fast IRC
	SCG->SPLLCFG = value;
	/* Configure for the register SCG_SPLLDIV */
	value = SCG->SPLLDIV;
	value |= ((3u << 8) | (1u << 0)); //SPLLDIV2 = 011: divided by 4 | SPLLDIV1 = 1: divided by 1
	SCG->SPLLDIV = value;
	/* Wait unlock bit in SPLLCSR Register */
	while (((SCG->SPLLCSR) & (1 << 23)) == 1);
	/* Enable System SPLL bit */
	value = SCG->SPLLCSR;
	value |= (1U << 0);
	SCG->SPLLCSR = value;
	/* Wait for bit System PLL valid */
	while ((SCG->SPLLCSR >> 24) == 0); //check bit 24
	/* Configure for the DIVCORE and DIVBUS */
	value = SCG->RCCR;
	value &= ~(15U << 24);
	value |= ((6U << 24) | (0U << 16) | (1U << 4) | (2U << 0)); //System PLL (0110) | DIVCORE divided by 1 | DIVBUS divided by 2 | DIVSLOW divided by 3
	SCG->RCCR = value;

	while (((SCG->CSR) & (0xfu << 24)) != ((SCG->RCCR) & (0xfu << 24)));
}

void SCG_SOSC_24MHz_config(void)
{
	/*SOSC 8Mhz to create CORE_CLK 24MHz, BUS_CLK 12MHz, FLASH_CLK 8MHz, SPLLDIV1 24MHz, SPLLDIV2 12Mhz*/

	uint32_t value;
	/* Wait unlock bit in CSR Register */
	while (((SCG->SOSCCSR) & (1 << 23)) == 1);
	/* Disable ClkSource bit */
	value = SCG->SOSCCSR;
	value |= (0U << 0);
	SCG->SOSCCSR = value;
	/* Set value to CFG Register */
	value = SCG->SOSCCFG;
	value &= ~(3U << 4); //clear bit 4 and 5 (RANGE) to 0 before write value 10
	value |= ((2u << 4) | (1U << 2)); //Medium frequency(10) | Internal crystal oscillator
	SCG->SOSCCFG = value;
	/* Wait unlock bit in SOSCCSR Register */
	while (((SCG->SOSCCSR) & (1 << 23)) == 1);
	/* System OSC Enable */
	value = SCG->SOSCCSR;
	value |= (1U << 0);
	SCG->SOSCCSR = value;
	/* Wait for bit System OSC valid */
	while (((SCG->SOSCCSR) & (1 << 24)) == 0);
	/* Configure for the system PLL */
	/* check LK == 0. if true then write. check before write */
	while (((SCG->SPLLCSR) & (1 << 23)) == 1);
	/* Disable System SPLL bit */
	value = SCG->SPLLCSR;
	value |= (0U << 0);
	SCG->SPLLCSR = value;

	/* Configure for the register SCG_SPLLCFG */
	value = SCG->SPLLCFG;
	value |= ((8U << 16) | (3U << 8) | (0U << 0)); //MULT = 8: multiply by 24 | PREDIV = 3: divide by 4 | Source: internal crystal oscillator
	SCG->SPLLCFG = value;
	/* Configure for the register SCG_SPLLDIV */
	value = SCG->SPLLDIV;
	value |= ((2u << 8) | (1u << 0)); //SPLLDIV2 = 2: divided by 2 | SPLLDIV1 = 1: divided by 1
	SCG->SPLLDIV = value;
	/* Wait unlock bit in SPLLCSR Register */
	while (((SCG->SPLLCSR) & (1 << 23)) == 1);
	/* Enable System SPLL bit */
	value = SCG->SPLLCSR;
	value |= (1U << 0);
	SCG->SPLLCSR = value;
	/* Wait for bit System PLL valid */
	while ((SCG->SPLLCSR >> 24) == 0); //check bit 24
	/* Configure for the DIVCORE and DIVBUS */
	value = SCG->RCCR;
	value &= ~(15U << 24);
	value |= ((6U << 24) | (0U << 16) | (1U << 4) | (2U << 0)); //System PLL (0110) | DIVCORE divided by 1 | DIVBUS divided by 2 | DIVSLOW divided by 3
	SCG->RCCR = value;

	while (((SCG->CSR) & (0xfu << 24)) != ((SCG->RCCR) & (0xfu << 24)));
}

void SCG_SOSC_8MHz_config(void)
{
	/*SOSC 8Mhz to create CORE_CLK 8MHz, BUS_CLK 8MHz, FLASH_CLK 8MHz, SPLLDIV1 16MHz, SPLLDIV2 8Mhz*/

	uint32_t value;
	/* Wait unlock bit in CSR Register */
	while (((SCG->SOSCCSR) & (1 << 23)) == 1);
	/* Disable ClkSource bit */
	value = SCG->SOSCCSR;
	value |= (0U << 0);
	SCG->SOSCCSR = value;
	/* Set value to CFG Register */
	value = SCG->SOSCCFG;
	value &= ~(3U << 4); //clear bit 4 and 5 (RANGE) to 0 before write value 10
	value |= ((2u << 4) | (1U << 2)); //Medium frequency(10) | Internal crystal oscillator
	SCG->SOSCCFG = value;
	/* Wait unlock bit in SOSCCSR Register */
	while (((SCG->SOSCCSR) & (1 << 23)) == 1);
	/* System OSC Enable */
	value = SCG->SOSCCSR;
	value |= (1U << 0);
	SCG->SOSCCSR = value;
	/* Wait for bit System OSC valid */
	while (((SCG->SOSCCSR) & (1 << 24)) == 0);
	/* Configure for the system PLL */
	/* check LK == 0. if true then write. check before write */
	while (((SCG->SPLLCSR) & (1 << 23)) == 1);
	/* Disable System SPLL bit */
	value = SCG->SPLLCSR;
	value |= (0U << 0);
	SCG->SPLLCSR = value;

	/* Configure for the register SCG_SPLLCFG */
	value = SCG->SPLLCFG;
	value |= ((1U << 16) | (7U << 8) | (0U << 0)); //MULT = 1: multiply by 16 | PREDIV = 7: divide by 8 | Source: internal crystal oscillator
	SCG->SPLLCFG = value;
	/* Configure for the register SCG_SPLLDIV */
	value = SCG->SPLLDIV;
	value |= ((2u << 8) | (1u << 0)); //SPLLDIV2 = 2: divided by 2 | SPLLDIV1 = 1: divided by 1
	SCG->SPLLDIV = value;
	/* Wait unlock bit in SPLLCSR Register */
	while (((SCG->SPLLCSR) & (1 << 23)) == 1);
	/* Enable System SPLL bit */
	value = SCG->SPLLCSR;
	value |= (1U << 0);
	SCG->SPLLCSR = value;
	/* Wait for bit System PLL valid */
	while ((SCG->SPLLCSR >> 24) == 0); //check bit 24
	/* Configure for the DIVCORE and DIVBUS */
	value = SCG->RCCR;
	value &= ~(15U << 24);
	value |= ((6U << 24) | (1U << 16) | (1U << 4) | (1U << 0)); //System PLL (0110) | DIVCORE divided by 2 | DIVBUS divided by 2 | DIVSLOW divided by 2
	SCG->RCCR = value;

	while (((SCG->CSR) & (0xfu << 24)) != ((SCG->RCCR) & (0xfu << 24)));
}

void SCG_FIRC_48MHz_config(void)
{
	/*SOSC 8Mhz to create CORE_CLK 48MHz, BUS_CLK 24MHz, FLASH_CLK 12MHz, FIRCDIV1 24MHz, FIRCDIV2 24Mhz*/

	uint32_t value;
	/* Configure for the DIVCORE and DIVBUS */
	value = SCG->RCCR;
	value &= ~(15U << 24);
	value |= ((3U << 24) | (0U << 16) | (1U << 4) | (3U << 0)); //f=48x10^6 //FIRC(0011); DIVCORE devided by 1 and DIVBUS devided by 2 and DIVSLOW devided by 4
	SCG->RCCR = value;

	while (((SCG->FIRCCSR) & (1 << 23)) == 1)
	{
	}
	value = SCG->FIRCCSR;
	value |= (0U << 0);	//Disable the Fast IRC Enable
	SCG->FIRCCSR = value;

	value = SCG->FIRCDIV;
	value |= ((2U << 8)| (2u << 0)); //Configure the Fast IRC Divide Register, FIRCDIV1 divided by 2, FIRCDIV2 divided by 2
	SCG->FIRCDIV = value;

	//Enable the FIRC
	while (((SCG->FIRCCSR) & (1 << 23)) == 1)
	{
	}
	value = SCG->FIRCCSR;
	value |= (1U << 0);	//Enable the Fast IRC Enable
	SCG->FIRCCSR = value;
}
