/* ####################################
Author: MD. Soyabbir Abu Hanif
 MSc in Embedded Systems
Tampere University, Finland
Email: hanifseceee535@gmail.com 
######################################
*/





#ifndef HEADER_H
#define HEADER_H 
#include <stdint.h>



//*************************__SysTick__*************************

// Define SysTick base address
#define SYSTICK_BASE (0xE000E010)

// Define the SysTick structure
typedef struct {
    volatile uint32_t CTRL;   // SysTick Control and Status Register
    volatile uint32_t LOAD;   // SysTick Reload Value Register
    volatile uint32_t VAL;    // SysTick Current Value Register
    volatile uint32_t CALIB;  // SysTick Calibration Value Register
} SysTick_TypeDef;

// Define a pointer to the SysTick structure at the base address
#define SysTick ((SysTick_TypeDef *) SYSTICK_BASE)

//*************************__SysTick__*************************



#define __enableirq()  __asm("CPSIE I")  // Enable interrupts globally
#define __disableirq() __asm("CPSID I")  // Disable interrupts globally


//################__Timers__################

// Define Timer base addresses
#define TIM1_BASE (0x40012C00)
#define TIM2_BASE (0x40000000)
#define TIM3_BASE (0x40000400)
#define TIM4_BASE (0x40000800)

// Define the Timer structure
typedef struct {
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SMCR;
    volatile uint32_t DIER;
    volatile uint32_t SR;
    volatile uint32_t EGR;
    volatile uint32_t CCMR1;
    volatile uint32_t CCMR2;
    volatile uint32_t CCER;
    volatile uint32_t CNT;
    volatile uint32_t PSC;
    volatile uint32_t ARR;
    volatile uint32_t RCR;
    volatile uint32_t CCR1;
    volatile uint32_t CCR2;
    volatile uint32_t CCR3;
    volatile uint32_t CCR4;
    volatile uint32_t BDTR;
    volatile uint32_t DCR;
    volatile uint32_t DMAR;
} Timer_TypeDef;

// Define Timer base pointers
#define TIM1 ((Timer_TypeDef *)TIM1_BASE)
#define TIM2 ((Timer_TypeDef *)TIM2_BASE)
#define TIM3 ((Timer_TypeDef *)TIM3_BASE)
#define TIM4 ((Timer_TypeDef *)TIM4_BASE)


#define t1   1  //timer 1
#define t2   2  //timer 2
#define t3   3  //timer 3
#define t4   4  //timer 4


//################__Timers__################


// Base Addresses
#define RCCAPB2       *(volatile uint32_t *) 0x40021018
#define RCCAPB1       *(volatile uint32_t *) 0x4002101C

#define GPIOA         *(volatile uint32_t *) 0x40010800
#define GPIOB         *(volatile uint32_t *) 0x40010C00
#define GPIOC         *(volatile uint32_t *) 0x40011000
#define GPIOD         *(volatile uint32_t *) 0x40011400
#define GPIOE         *(volatile uint32_t *) 0x40011800

// GPIO Mode and Configuration Constants
//defining the ports:
#define portA 							1
#define portB 							2
#define portC 							3
#define portD 							4
#define portE 							5

#define input               0
#define output_10Mhz        1
#define output_2Mhz         2
#define output_50Mhz        3

#define analog_in           0
#define floating_in         1
#define pp_in               2

#define gp_output           0
#define open_drain_output   1
#define af_pp_output        2
#define af_od_output        3

#define HIGH                1
#define LOW                 0



// Interrupt Configuration
#define INT_PORT_A          0
#define INT_PORT_B          1
#define INT_PORT_C          2
#define INT_PORT_D          3
#define INT_PORT_E          4

#define RISING              0
#define FALLING             1
#define BOTH                2

#define AFIO_EXTR1          *(volatile uint32_t *) 0x40010008
#define AFIO_EXTR2          *(volatile uint32_t *) 0x4001000C
#define AFIO_EXTR3          *(volatile uint32_t *) 0x40010010
#define AFIO_EXTR4          *(volatile uint32_t *) 0x40010014

#define EXTI_IMR            *(volatile uint32_t *) 0x40010400
#define EXTI_PR             *(volatile uint32_t *) 0x40010414
#define EXTI_RTSR           *(volatile uint32_t *) 0x40010408
#define EXTI_FTSR           *(volatile uint32_t *) 0x4001040C

#define NVIC_ISER0          *(volatile uint32_t *) 0xE000E100
#define NVIC_ISER1          *(volatile uint32_t *) 0xE000E104



//####################################################################################################
// Function Prototypes
void config_gpio(uint32_t port, uint32_t pin, uint32_t mode, uint32_t config);
void write_gpio(uint32_t port, uint32_t pin, uint32_t state);
uint32_t read_gpio(uint32_t port, uint32_t pin);
void toggle_gpio(uint32_t port, uint32_t pin);
void configure_gpio_interrupt(uint8_t pin, uint8_t port, uint8_t trigger_type);
void delay_microSecond(uint8_t timer, uint16_t delay);
void delay_miliSecond(uint8_t timer, uint16_t delay);
void timer_irq_microSecond_start (uint8_t timer, uint16_t delay);
void timer_irq_milisecond_start (uint8_t timer, uint16_t delay);
void stop_timer_irq (uint8_t timer);
void stop_timer (uint8_t timer);
void timer_compare_MhZ(uint32_t port, uint8_t pin, uint16_t Load_value, uint16_t compare_value );
void timer_compare_khZ(uint32_t port, uint8_t pin, uint16_t Load_value, uint16_t compare_value );
void timer_PWM_Microsecond(uint32_t port, uint8_t pin, uint16_t period, uint16_t duty_cycle_percentage );
void timer_PWM_Milisecond(uint32_t port, uint8_t pin, uint16_t period, uint16_t duty_cycle_percentage );
void Delay_Sys_US (uint16_t t);
void Delay_Sys_MS (uint16_t t);
void systic_init(void);
void Systic_interrupt ();
#endif // HEADER_H
