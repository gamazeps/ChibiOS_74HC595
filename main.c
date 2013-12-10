#include "ch.h"
#include "hal.h"
#include "shift_register.h"

#define LATCH 2
#define REG_CLK 4
#define DATA_IN 0


// Simple exemple of how to use the shift_reg functions 
int main(void){
        halInit(); // initialize Hardware Abstraction Layer
        chSysInit(); // initialize ChibiOS kernel
	shiftreg_init(GPIOD, LATCH, GPIOD, REG_CLK, GPIOD, DATA_IN);
	
	// A simple binary counter using the shift_reg functions
	uint8_t count = 0;
        while(1){
		shiftreg_send_octet(count, GPIOD, LATCH, GPIOD, REG_CLK,
			       	GPIOD, DATA_IN;
		count ++;
                chThdSleepMilliseconds(500); // sleeps for 500ms
        }
}

