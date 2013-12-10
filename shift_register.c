#include "ch.h"
#include "hal.h"
#include "shift_register.h"

/* Initialises the GPIOs in order to use an 8-stage serial shift 
 * register (here a 74HC595) */
void shiftreg_init(GPIO_TypeDef * latch_chan, int latch_pin, 
		GPIO_TypeDef * clk_chan, int clk_pin, 
		GPIO_TypeDef * data_chan, int data_pin){
	palSetPadMode(latch_chan, latch_pin, PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(clk_chan, clk_pin, PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(data_chan, data_pin, PAL_MODE_OUTPUT_PUSHPULL);
}


/* Sends an 8 bits data to an 8-stage serial shift register (here a 
 * 74HC595).
 * The bits are send through data_pin the to the Serial Data Input 
 * pin (14) in between two bits the clk_pin is switched twice, in 
 * order to have a high edge to the Serial Register Clock Input (11).
 * The latch_pin is low during the data transfer, once it is over the 
 * pin is set high again and the outputs of the shift register are 
 * eventually updated, this communication is done through the Storage 
 * register Clock Input (12)  */

void shiftreg_send_octet(uint8_t data, 
		GPIO_TypeDef * latch_chan, int latch_pin,
	       	GPIO_TypeDef * clk_chan, int clk_pin, 
		GPIO_TypeDef * data_chan, int data_pin){
	palClearPad(latch_chan, latch_pin);
	for(int i=0; i<8; i++){
		palClearPad(clk_chan, clk_pin);
		if((data>>i)&1)
			palSetPad(data_chan, data_pin);
		else
			palClearPad(data_chan, data_pin);
		palSetPad(clk_chan, clk_pin);
	}
	palSetPad(latch_clk, latch_pin);
}

