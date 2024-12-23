/* ####################################
Author: MD. Soyabbir Abu Hanif
 MSc in Embedded Systems
Tampere University, Finland
Email: hanifseceee535@gmail.com 
######################################
*/




/* ################################################################################
 * GPIO Library Header File
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