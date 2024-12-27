/* ####################################
Author: MD. Soyabbir Abu Hanif
 MSc in Embedded Systems
Tampere University, Finland
Email: hanifseceee535@gmail.com 
######################################
*/



#include <stdint.h>    
#include "header.h"

/*
void TIM1_UP_IRQHandler(){}
void TIM2_IRQHandler(){}
void TIM3_IRQHandler(){}
void TIM4_IRQHandler(){}


*/
uint8_t count = 0;

 void TIM4_IRQHandler(void) {
	
    if (TIM4->SR & (1 << 0)) {   // Check UIF (Update Interrupt Flag)
        TIM4->SR &= 0xFFFE;   // Clear UIF				
        toggle_gpio(portC, 0);  // Example: Toggle LED on interrupt
			  count ++; 
			  if (count == 20){
					//stop_timer_irq(t4);
					stop_timer(t4);
					stop_timer (t1);
				}
       }
}



int main ()
{
	
	
	//configuring gpioC pin 0 as general purpose output push pull
	config_gpio (portC, 0, output_50Mhz, gp_output);
	config_gpio (portC, 3, output_50Mhz, gp_output);
	timer_irq_milisecond_start ( t4, 500);
	
	while (1){
		 toggle_gpio(portC, 3);
		
		delay_miliSecond( t1,  500 );		
		
		}
	


}



