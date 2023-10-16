#include "s32k144.h"
#include "project.h"
uint32_t rx_msg_count=0;
int main(void){
	Project_Config();
#ifdef NODE_A              /* Node A transmits first; Node B transmits after reception */
	Can_Transmit_msg(FlexCAN_0); /* Transmit initial message from Node A to Node B */
#endif
	for (;;)
	{                        			/* Loop: if a msg is received, transmit a msg */
		if ((FlexCAN_0->IFLAG1 >> 4) & 1) {  /* If CAN 0 MB 4 flag is set (received msg), read MB4 */
			Can_Recieve_msg(FlexCAN_0);      /* Read message */
			rx_msg_count++;               /* Increment receive msg counter */

			if (rx_msg_count == 1000) {   /* If 1000 messages have been received, */

				rx_msg_count = 0;           /*   and reset message counter */
			}

			Can_Transmit_msg(FlexCAN_0);     /* Transmit message using MB0 */
		}
		Project_Do();
	}

}
