/* ####################################
Author: MD. Soyabbir Abu Hanif
 MSc in Embedded Systems
Tampere University, Finland
Email: hanifseceee535@gmail.com 
######################################
*/



#include <stdint.h>    
#include "header.h"
/*int count = 0; 
void SysTick_Handler(void){
	count++; 
	if (count == 10){
		toggle_gpio (portA, 8); 
		count = 0;
	}
	
}
*/
/*void USART3_IRQHandler  (void){
	char message = 'c';
	message = USART_receive (3);
	USART_transmit (3, message);
}
*/

char data [2] = {0x01, 0x02};

int main ()
{
	i2c_init(1,i2c_FastMode);
	 //init_SPI(1, 128);
	//init_usart_receive_interrupt (3, 115200);
	//init_USART(3, 115200);
	systic_init();
	//RCCAPB2 |= (1<<0);
	//RCCAPB2 |= (1<<12);
	//configuring gpioC pins  as general purpose output push pull
	//config_gpio (portA, 4, output_50Mhz, gp_output);
	//config_gpio (portA, 5, output_50Mhz, af_pp_output);
	//config_gpio (portA, 6, input, pp_in);
	//config_gpio (portA, 7, output_50Mhz, af_pp_output);
	//timer_irq_milisecond_start ( t4, 00);
	//timer_PWM_Microsecond ( portA , 8, 100, 100 );
	//timer_PWM_Microsecond( portA , 9, 100, 75 );
	//timer_PWM_Microsecond( portA , 10, 100, 50 );
	//timer_PWM_Microsecond( portA , 11, 100, 25 );
	// Systic_interrupt ();
	
	//SPI1->CR1 |= 0x4;
  //SPI1->CR1 |= 0x31;
 // SPI1->CR2 |= 0x4;	
//	SPI1->CR1 |= 0x40;
//	write_gpio (portA, 4, HIGH);
	
	while (1){
		
		
		//Delay_Sys_MS(500);
		//write_gpio(portA, 4, LOW);
		//SPI1->DR = 'x';
		//while (SPI1->SR & 0x80) {}
		//write_gpio(portA, 4, HIGH);
		//spi_transmit(1, 'x');
		//spi_transmit(1, 'y');
		//toggle_gpio(portA, 4);
		//toggle_gpio(portA, 7);
		//delay_miliSecond( t1,  100 );		
		//toggle_gpio(portA, 9);
		//delay_miliSecond( t1,  100 );	
		//toggle_gpio(portA, 10);
		//delay_miliSecond( t1,  100 );	
		//toggle_gpio(portA, 4);
		//delay_miliSecond( t1,  100 );	
		//Delay_Sys_MS(500);
		//message = USART_receive (3);
		//USART_transmit (3, message);
		
		//timer_compare_MhZ( portA , 8, 10000, 100 );
		
		//spi_send_message (SPI_1, "ABCDEFGH");
		
		//Delay_Sys_MS (200);
		//write_gpio (portA, 4, LOW);
		//SPI1->DR = 'w';
		//while(SPI1->SR & 0x80 ){}
		//write_gpio (portA, 4, HIGH);	
		
		i2c_write (1, 0x78, data);
		Delay_Sys_MS (200);
		
		}
	


}



