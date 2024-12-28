/* ####################################
Author: MD. Soyabbir Abu Hanif
 MSc in Embedded Systems
Tampere University, Finland
Email: hanifseceee535@gmail.com 
######################################
*/



#include <stdint.h>    
#include "header.h"
int count = 0; 
void SysTick_Handler(void){
	count++; 
	if (count == 10){
		toggle_gpio (portA, 8); 
		count = 0;
	}
	
}


int main ()
{
	
	systic_init();
	
	//configuring gpioC pins  as general purpose output push pull
	config_gpio (portA, 8, output_50Mhz, gp_output);
	config_gpio (portA, 9, output_50Mhz, gp_output);
	//config_gpio (portA, 10, output_50Mhz, gp_output);
	//config_gpio (portA, 11, output_50Mhz, gp_output);
	//timer_irq_milisecond_start ( t4, 00);
	//timer_PWM_Microsecond ( portA , 8, 100, 100 );
	//timer_PWM_Microsecond( portA , 9, 100, 75 );
	//timer_PWM_Microsecond( portA , 10, 100, 50 );
	//timer_PWM_Microsecond( portA , 11, 100, 25 );
	 Systic_interrupt ();
	
	while (1){
		//toggle_gpio(portA, 8);
		//delay_miliSecond( t1,  100 );		
		//toggle_gpio(portA, 9);
		//delay_miliSecond( t1,  100 );	
		//toggle_gpio(portA, 10);
		//delay_miliSecond( t1,  100 );	
		//toggle_gpio(portA, 11);
		//delay_miliSecond( t1,  100 );	
		//Delay_Sys_MS(100);
		
		
		//timer_compare_MhZ( portA , 8, 10000, 100 );
		}
	


}



