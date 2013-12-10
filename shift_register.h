#ifndef SHIFT_REGISTER_H
#define SHIFT_REGISTER_H

void shiftreg_init(GPIO_TypeDef * latch_chan, int latch_pin, 
		GPIO_TypeDef * clk_chan, int clk_pin, 
		GPIO_TypeDef * data_chan, int data_pin);
void shiftreg_send_octet(uint8_t data, 
		GPIO_TypeDef * latch_chan, int latch_pin,
	       	GPIO_TypeDef * clk_chan, int clk_pin, 
		GPIO_TypeDef * data_chan, int data_pin);

#endif

