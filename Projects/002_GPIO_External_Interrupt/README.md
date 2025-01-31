# EXTI Interrupt Handling Library for STM32 (with GPIO Integration)

This section provides an **EXTI (External Interrupt)** library that works seamlessly with the **GPIO library** I developed in the previous section for STM32 microcontrollers. This combination allows users to configure GPIO pins for both general-purpose I/O and external interrupt handling, providing a flexible way to interact with external signals (e.g., buttons, sensors) and trigger actions based on those signals.

## Features

- **GPIO Pin Configuration**: Configure GPIO pins for input (with pull-up/down) or output (general-purpose).
- **External Interrupt Configuration**: Easily set up external interrupts (EXTI) on GPIO pins with customizable edge trigger types (Rising, Falling, or Both).
- **Interrupt Flag Handling**: Check and clear interrupt flags for configured EXTI lines in interrupt service routines (ISRs).
- **NVIC Integration**: Automatically enable and manage interrupts using the **Nested Vectored Interrupt Controller (NVIC)**.
- **Flexible Pin Management**: Allows users to configure GPIO pins for both input and output modes, while enabling interrupts only for specific pins.

## How to Use the EXTI Interrupt Library in Your Main Code

The **EXTI Interrupt Handling Library** can be easily integrated into your main application code that uses the **GPIO library**. Below is a step-by-step guide on how to configure an interrupt for a GPIO pin and handle it in the main function.


## How to invoke the interrupt handlers:
// EXTI Interrupt Handling Library for STM32 (with GPIO Integration)

#include "stm32f4xx.h"

// Function to configure GPIO pin as input or output
void config_gpio(GPIO_TypeDef* port, uint16_t pin, uint8_t mode, uint8_t pull) {
    // Configure GPIO pin here (input/output, pull-up/down)
}

// Function to configure GPIO pin interrupt
void configure_gpio_interrupt(uint16_t pin, uint8_t port, uint8_t edge) {
    // Configure EXTI for the pin and edge trigger
    if (edge == RISING) {
        // Set rising edge interrupt
    } else if (edge == FALLING) {
        // Set falling edge interrupt
    } else {
        // Set both edges interrupt
    }
    // Enable interrupt in NVIC for the specific EXTI line
}

// Interrupt handler for EXTI Line 0 (GPIO Pin 0)
void EXTI0_IRQHandler(void) {
    if (EXTI_PR & (1 << 0)) {  // Check if EXTI Line 0 interrupt is pending
        // Your interrupt handling code here
        
        EXTI_PR |= (1 << 0);  // Clear the interrupt flag for EXTI Line 0
    }
}

// Interrupt handler for EXTI Line 1 (GPIO Pin 1)
void EXTI1_IRQHandler(void) {
    if (EXTI_PR & (1 << 1)) {  // Check if EXTI Line 1 interrupt is pending
        // Your interrupt handling code here
        
        EXTI_PR |= (1 << 1);  // Clear the interrupt flag for EXTI Line 1
    }
}

// Interrupt handler for EXTI Line 2 (GPIO Pin 2)
void EXTI2_IRQHandler(void) {
    if (EXTI_PR & (1 << 2)) {  // Check if EXTI Line 2 interrupt is pending
        // Your interrupt handling code here
        
        EXTI_PR |= (1 << 2);  // Clear the interrupt flag for EXTI Line 2
    }
}

// Interrupt handler for EXTI Line 3 (GPIO Pin 3)
void EXTI3_IRQHandler(void) {
    if (EXTI_PR & (1 << 3)) {  // Check if EXTI Line 3 interrupt is pending
        // Your interrupt handling code here
        
        EXTI_PR |= (1 << 3);  // Clear the interrupt flag for EXTI Line 3
    }
}

// Interrupt handler for EXTI Line 4 (GPIO Pin 4)
void EXTI4_IRQHandler(void) {
    if (EXTI_PR & (1 << 4)) {  // Check if EXTI Line 4 interrupt is pending
        // Your interrupt handling code here
        
        EXTI_PR |= (1 << 4);  // Clear the interrupt flag for EXTI Line 4
    }
}

// Interrupt handler for EXTI Lines 5 to 9 (GPIO Pins 5 to 9)
void EXTI9_5_IRQHandler(void) {
    if (EXTI_PR & (1 << 5)) {  // Check if EXTI Line 5 interrupt is pending
        // Your interrupt handling code here
        
        EXTI_PR |= (1 << 5);  // Clear the interrupt flag for EXTI Line 5
    }
    
    if (EXTI_PR & (1 << 6)) {  // Check if EXTI Line 6 interrupt is pending
        // Your interrupt handling code here
        
        EXTI_PR |= (1 << 6);  // Clear the interrupt flag for EXTI Line 6
    }
    
    if (EXTI_PR & (1 << 7)) {  // Check if EXTI Line 7 interrupt is pending
        // Your interrupt handling code here
        
        EXTI_PR |= (1 << 7);  // Clear the interrupt flag for EXTI Line 7
    }

    if (EXTI_PR & (1 << 8)) {  // Check if EXTI Line 8 interrupt is pending
        // Your interrupt handling code here
        
        EXTI_PR |= (1 << 8);  // Clear the interrupt flag for EXTI Line 8
    }
    
    if (EXTI_PR & (1 << 9)) {  // Check if EXTI Line 9 interrupt is pending
        // Your interrupt handling code here
        
        EXTI_PR |= (1 << 9);  // Clear the interrupt flag for EXTI Line 9
    }
}

// Interrupt handler for EXTI Lines 10 to 15 (GPIO Pins 10 to 15)
void EXTI15_10_IRQHandler(void) {
    if (EXTI_PR & (1 << 10)) {  // Check if EXTI Line 10 interrupt is pending
        // Your interrupt handling code here
        
        EXTI_PR |= (1 << 10);  // Clear the interrupt flag for EXTI Line 10
    }
    
    if (EXTI_PR & (1 << 11)) {  // Check if EXTI Line 11 interrupt is pending
        // Your interrupt handling code here
        
        EXTI_PR |= (1 << 11);  // Clear the interrupt flag for EXTI Line 11
    }
    
    if (EXTI_PR & (1 << 12)) {  // Check if EXTI Line 12 interrupt is pending
        // Your interrupt handling code here
        
        EXTI_PR |= (1 << 12);  // Clear the interrupt flag for EXTI Line 12
    }
    
    if (EXTI_PR & (1 << 13)) {  // Check if EXTI Line 13 interrupt is pending
        // Your interrupt handling code here
        
        EXTI_PR |= (1 << 13);  // Clear the interrupt flag for EXTI Line 13
    }
    
    if (EXTI_PR & (1 << 14)) {  // Check if EXTI Line 14 interrupt is pending
        // Your interrupt handling code here
        
        EXTI_PR |= (1 << 14);  // Clear the interrupt flag for EXTI Line 14
    }
    
    if (EXTI_PR & (1 << 15)) {  // Check if EXTI Line 15 interrupt is pending
        // Your interrupt handling code here
        
        EXTI_PR |= (1 << 15);  // Clear the interrupt flag for EXTI Line 15
    }
}

// Example usage: Configuring GPIOC Pin 13 for Interrupt
void setup_gpio_interrupt() {
    // Configure GPIOC Pin 13 as input with pull-down resistor
    config_gpio(GPIOC, 13, INPUT, PP_IN); 

    // Configure GPIOC Pin 13 to trigger interrupt on rising edge
    configure_gpio_interrupt(13, INT_PORT_C, RISING);
}

// Main function
int main(void) {
    // Set up GPIOC Pin 13 for interrupt handling
    setup_gpio_interrupt();

    // Enable the interrupt in NVIC
    NVIC_EnableIRQ(EXTI15_10_IRQn);

    while (1) {
        // Main loop
        // Interrupt will trigger and be handled in EXTI15_10_IRQHandler()
    }

    return 0;
}



### Example Usage

In this example, we'll configure **GPIOC Pin 13: 
// 1. Configure GPIOC Pin 13 as input with pull-down resistor (for button or signal)
    config_gpio(portC, 13, input, pp_in);
    configure_gpio_interrupt(13, INT_PORT_C, RISING);



