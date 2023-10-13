#include "sim.h"
#include "scg.h"

void CLKOUT_config(void)
{
	/* CLKOUT Select: (1000)SPLLDIV2, CLKOUT Divided by 2 (001) */
	uint32_t value;
	/* SCG CLKOUT Configuration Register */
	value = SCG->CLKOUTCNFG;
	value |= (3u << 24);  //Fast IRC (FIRC_CLK)
	/* CLKOUT Select | CLKOUT Divide Ratio */
	SCG->CLKOUTCNFG = value;
	value = SIM->CHIPCTL;
	value |= ((1u << 8) | (8u << 4));
	SIM->CHIPCTL = value;
	/* CLKOUT enable */
	value |= (1u << 11);
	SIM->CHIPCTL = value;
}
