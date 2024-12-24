/* ####################################
Author: MD. Soyabbir Abu Hanif
 MSc in Embedded Systems
Tampere University, Finland
Email: hanifseceee535@gmail.com 
######################################
*/




/* ################################################################################
 *  Library Header File
 *
 * This header file provides base addresses, macros, and function prototypes 
 * for configuring, reading, and writing GPIO pins on an STM32 microcontroller.
 *
 * Features:
 * 1. Define GPIO ports (A to E).
 * 2. Modes: Input, Output with speed options.
 * 3. Input configurations: Analog, Floating, Pull-down.
 * 4. Output configurations: General-purpose, Open-drain, Alternate function.
 * 5. Functions:
 *    - `config_gpio`: Configure GPIO pins.
 *    - `read_gpio`: Read GPIO pin states.
 *    - `write_gpio`: Write states to GPIO pins.
 
 ###############################################################################
 */



#include <stdint.h>

//Reset and clock control register 
//base address: 0x40021000
//All gpio ports are connected to APB2 bus
//Offset of APB2 bus = 0x18
#define RCCAPB2 *(volatile uint32_t *) 0x40021018
	
//Base address of the GPIO Ports:
	
#define GPIOA *(volatile uint32_t *) 0x40010800
#define GPIOB *(volatile uint32_t *) 0x40010C00
#define GPIOC *(volatile uint32_t *) 0x40011000
#define GPIOD *(volatile uint32_t *) 0x40011400
#define GPIOE *(volatile uint32_t *) 0x40011800
	
//###################################################################################################

//Define interrupt ports:

#define INT_PORT_A 0
#define INT_PORT_B 1
#define INT_PORT_C 2
#define INT_PORT_D 3
#define INT_PORT_E 4

//Difining the triggering mode: 
#define RISING 0
#define FALLING 1
#define BOTH 2

//Defining the External interrupt configuration registers 
#define AFIO_EXTR1 *(volatile uint32_t *) 0x40010008  //offset for (AFIO_EXTICR1is 0x08 
#define AFIO_EXTR2 *(volatile uint32_t *) 0x4001000C  //offset for (AFIO_EXTICR2 is 0x0C
#define AFIO_EXTR3 *(volatile uint32_t *) 0x40010010  //offset for (AFIO_EXTICR3 is 0x10
#define AFIO_EXTR4 *(volatile uint32_t *) 0x40010014  //offset for (AFIO_EXTICR4 is 0x14
	
//EXTI interrupt mask register:
#define EXTI_IMR *(volatile uint32_t *) 0x40010400  //offset zero

//Pending register (EXTI_PR)
#define EXTI_PR *(volatile uint32_t *) 0x40010414  //offset 0x14
	
//Rising trigger selection register (EXTI_RTSR)
#define EXTI_RTSR *(volatile uint32_t *) 0x40010408  //offset is 0x08

//Falling trigger selection register (EXTI_FTSR)
#define EXTI_FTSR *(volatile uint32_t *) 0x4001040C  //offset is 0x0C

// Interrupt set-enable registers (NVIC_ISERx)
#define NVIC_ISER0 *(volatile uint32_t *) 0xE000E100  //offset is 0x00
#define NVIC_ISER1 *(volatile uint32_t *) 0xE000E104  //offset is 0x04
	
//####################################################################################################
	
//defining the ports:
#define portA 1
#define portB 2
#define portC 3
#define portD 4
#define portE 5

// Define Mode of ports
#define input 0
#define output_10Mhz 1
#define output_2Mhz 2
#define output_50Mhz 3

	
//Define the port configuration for input mode

#define analog_in 0
#define floating_in 1
#define pp_in 2

//Define the port configuration for output mode

#define gp_output 0
#define open_drain_output 1
#define af_pp_output 2
#define af_od_output 3

//Define State
#define HIGH 1
#define LOW 0


void config_gpio ( uint32_t port , uint32_t pin, uint32_t mode, uint32_t config);
void write_gpio (uint32_t port, uint32_t pin, uint32_t state);
uint32_t read_gpio (uint32_t port, uint32_t pin);
void configure_gpio_interrupt(uint8_t pin, uint8_t port, uint8_t trigger_type);
