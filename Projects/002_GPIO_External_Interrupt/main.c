#include <stdint.h>
#include "header.h"

volatile uint8_t interrupt_Occurred = 0;
void delay (int volatile rep);
//void EXTI0_IRQHandler (void) ;


void EXTI15_10_IRQHandler(void) {
	if (EXTI_PR & (1 << 13))  // Checking if EXT line 13 interrupt flag is set or not
		{
			
			if (interrupt_Occurred == 0){ interrupt_Occurred = 1; }
			else { interrupt_Occurred = 0; }
		
			EXTI_PR |= (1 << 13); // Clearing the interrupt flag
	  }
}


int main (){
	
	//configuring gpio P13 pin as input pull down
	config_gpio(portC, 13, input, pp_in);
	//configuring gpioC pin 0 as general purpose output push pull
	config_gpio (portC, 0, output_50Mhz, gp_output);
	
	configure_gpio_interrupt(13, INT_PORT_C, RISING);
	
	while (1){
		
		if (interrupt_Occurred){
			write_gpio (portC, 0, LOW);
			
			delay (5);
			write_gpio (portC, 0, HIGH);
			delay (5);
			
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