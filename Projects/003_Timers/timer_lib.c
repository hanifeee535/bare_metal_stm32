/* ####################################
Author: MD. Soyabbir Abu Hanif
 MSc in Embedded Systems
Tampere University, Finland
Email: hanifseceee535@gmail.com 
######################################
*/


#include <stdint.h>    
#include "header.h"
//#include "stm32f10x.h"

// Function to select the timer based on input
Timer_TypeDef* select_timer(uint8_t timer_number) {
    switch (timer_number) {
        case 1: return TIM1;
        case 2: return TIM2;
        case 3: return TIM3;
        case 4: return TIM4;
        default: return 0; // Invalid timer number
    }
}

void start_timer_in_Microsecond (uint8_t timer_number, uint16_t delay){
	 uint16_t prescaller = 72-1;
	 // Enable the appropriate timer clock
    if (timer_number == 1) {
        RCCAPB2 |= 1 << 11; // Enable APB2 bus for Timer 1
    } else {
        RCCAPB1 |= 1 << (timer_number - 2); // Enable APB1 bus for Timer 2, 3, or 4
    }
	 Timer_TypeDef *timer = select_timer(timer_number);
	 timer->CNT = 0;
	 timer->PSC = prescaller;
	 timer->ARR = delay-1;
	 timer->CR1 |= (1<<0);
	
}

void start_timer_in_Milisecond (uint8_t timer_number, uint16_t delay){
	 uint16_t prescaller = 36000-1;
	 // Enable the appropriate timer clock
    if (timer_number == 1) {
        RCCAPB2 |= 1 << 11; // Enable APB2 bus for Timer 1
    } else {
        RCCAPB1 |= 1 << (timer_number - 2); // Enable APB1 bus for Timer 2, 3, or 4
    }
	 Timer_TypeDef *timer = select_timer(timer_number);
	 timer->CNT = 0;
	 timer->PSC = prescaller;
	 timer->ARR = (delay*2)-1;
	 timer->CR1 |= (1<<0);
	
}

void delay_microSecond (uint8_t timer, uint16_t delay){
	Timer_TypeDef *timerx = select_timer(timer);
	start_timer_in_Microsecond(timer, delay);
	
  while (!(timerx->SR & (1 << 0))) {
                // Wait until the timer reaches the ARR value
            }
            timerx->SR &= ~(1 << 0); // Clear the UIF flag           
        
}

void delay_miliSecond(uint8_t timer, uint16_t delay) {
	Timer_TypeDef *timerx = select_timer(timer);
	start_timer_in_Milisecond(timer, delay);
	
  while (!(timerx->SR & (1 << 0))) {
                // Wait until the timer reaches the ARR value
            }
            timerx->SR &= ~(1 << 0); // Clear the UIF flag 

}

void timer_irq_microSecond_start (uint8_t timer, uint16_t delay){
	Timer_TypeDef *timerx = select_timer(timer);
	start_timer_in_Microsecond(timer, delay);
	timerx->DIER |= (1<<0);
	__disableirq();
	switch (timer) {
		case 1 : NVIC_ISER0 |= (1<<25); break;
		case 2 : NVIC_ISER0 |= (1<<28); break;
		case 3 : NVIC_ISER0 |= (1<<29); break;
		case 4 : NVIC_ISER0 |= (1<<30); break;
	
	}
	__enableirq();

}

void timer_irq_milisecond_start (uint8_t timer, uint16_t delay){
	Timer_TypeDef *timerx = select_timer(timer);
	 start_timer_in_Milisecond (timer, delay);
	timerx->DIER |= (1<<0);
	__disableirq();
	switch (timer) {
		case 1 : NVIC_ISER0 |= (1<<25); break;
		case 2 : NVIC_ISER0 |= (1<<28); break;
		case 3 : NVIC_ISER0 |= (1<<29); break;
		case 4 : NVIC_ISER0 |= (1<<30); break;
	
	}
	__enableirq();

}

void stop_timer_irq (uint8_t timer) {
	Timer_TypeDef *timerx = select_timer(timer);
	timerx->DIER &= ~(1 << 0);
	__disableirq();
	switch (timer) {
		case 1 : NVIC_ISER0 &= ~(1 <<25); break;
		case 2 : NVIC_ISER0 &= ~(1 <<28); break;
		case 3 : NVIC_ISER0 &= ~(1 <<29); break;
		case 4 : NVIC_ISER0 &= ~(1 <<30); break;
	
	}
	__enableirq();

}

void stop_timer (uint8_t timer) {
	Timer_TypeDef *timerx = select_timer(timer);
	timerx->CR1 &= ~(1<<0);
	// Disable the appropriate timer clock
    if (timer == 1) {
        RCCAPB2 &= ~(1 << 11); // Enable APB2 bus for Timer 1
    } else {
        RCCAPB1 &= ~(1 << (timer - 2)); // Enable APB1 bus for Timer 2, 3, or 4
    }
		stop_timer_irq (timer);
}


 

