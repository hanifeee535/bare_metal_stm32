/* ####################################
Author: MD. Soyabbir Abu Hanif
 MSc in Embedded Systems
Tampere University, Finland
Email: hanifseceee535@gmail.com 
######################################
*/


/*
##################################################################################################################

 * Example: Using GPIO Library
 * 
 * This example demonstrates how to configure, read, and write GPIO pins using the custom library functions:
 * 
 * 1. **Configuring GPIO Pins**:
 *    - Use the `config_gpio(port, pin, mode, config)` function.
 *    - `port`: Port number (e.g., `portA`, `portB`, etc.).
 *    - `pin`: Pin number (0–15).
 *    - `mode`: Pin mode (e.g., `input`, `output_50Mhz`).
 *    - `config`: Configuration setting (e.g., `pp_in`, `gp_output`).
 * 
 * 2. **Reading GPIO Pin State**:
 *    - Use the `read_gpio(port, pin)` function.
 *    - Returns `1` for HIGH or `0` for LOW.
 * 
 * 3. **Writing to GPIO Pins**:
 *    - Use the `write_gpio(port, pin, state)` function.
 *    - `state`: `HIGH` (1) or `LOW` (0).
 * 
 * Below is a program that configures GPIO pins and toggles an LED based on the input state.
 
 
 ##############################################################################################################
 */



#include <stdint.h>
#include "gpio_header.h"

void delay (int volatile rep);


int main (){
	//configuring gpio P13 pin as input pull down
	config_gpio(portC, 13, input, pp_in);
	//configuring gpioC pin 0 as general purpose output push pull
	config_gpio (portC, 0, output_50Mhz, gp_output);
	
	while (1){
		
		if (read_gpio(portC,13) ==0) { //if input pin reading is high:
			write_gpio (portC, 0, LOW);			
			delay(10); 
			write_gpio(portC, 0, HIGH);
			delay(10);
		}
		else { write_gpio(portC, 0, HIGH);}
	
	}

}


void delay (int volatile rep)
{
	int volatile i;
	for (rep; rep>0; rep--)
	{
		for (i= 100000; i>0; i--)
		{
		
		}
	}
}

