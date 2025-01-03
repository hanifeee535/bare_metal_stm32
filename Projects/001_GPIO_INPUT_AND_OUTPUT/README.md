# **GPIO Library for STM32 Microcontrollers**

This project provides a library for configuring, reading, and writing GPIO (General Purpose Input/Output) pins on STM32 microcontrollers. It is written in C and is intended to abstract GPIO operations to make programming GPIO pins easier and more efficient. This library is compatible with STM32's Cortex-M architecture.

---

## **Target Board**
This library is developed and tested on the **STM32 Nucleo-F103RB** development board.  
### **Board Features**
- **Microcontroller**: STM32F103RB
  - ARM Cortex-M3, 72 MHz
  - 64 KB Flash, 20 KB SRAM
- **GPIO Ports**:
  - GPIOA, GPIOB, GPIOC, GPIOD, and GPIOE
- **Development Features**:
  - Onboard ST-Link/V2-1 debugger and programmer
  - Pinout compatibility with Arduino Uno R3
- **Clock**:
  - 8 MHz external crystal oscillator
  - 72 MHz system clock
- **I/O Voltage Levels**: 3.3V logic levels (5V tolerant)

> Note: This library is specific to the GPIO peripheral but can be adapted for other STM32 microcontrollers in the F1 family.

---

## **Features**
### **1. GPIO Pin Configuration**
- Configure GPIO pins as input, output, or alternate functions.
- Support for various modes and configurations:
  - **Input Modes**:
    - Analog Input
    - Floating Input
    - Pull-up/Pull-down Input
  - **Output Modes**:
    - General-Purpose Push-Pull
    - Open Drain
    - Alternate Function Push-Pull
    - Alternate Function Open Drain
  - **Output Speeds**:
    - 10 MHz, 2 MHz, 50 MHz

---

### **2. GPIO Read and Write Operations**
- **Read GPIO Pin:**
  - Reads the digital value (HIGH or LOW) from a specified GPIO pin.
- **Write GPIO Pin:**
  - Writes a digital value (HIGH or LOW) to a specified GPIO pin.

---

### **3. Clock Management**
- Automatically enables the clock for the respective GPIO port before configuring the pins.

---

### **4. Hardware Register Abstraction**
- The library abstracts the complexity of accessing hardware registers.
- Uses logical offsets (`0, 1, 2, 3`) mapped to actual memory offsets (`0x00, 0x04, 0x08, 0x0C`) for configuration, input, and output registers.
  - Logical Offset Mapping:
    - `0x00` (Configuration Register Low) → Offset `0`
    - `0x04` (Configuration Register High) → Offset `1`
    - `0x08` (Input Data Register) → Offset `2`
    - `0x0C` (Output Data Register) → Offset `3`

---

## **Files**
### **1. `main.c`**
- Example usage of the library:
  - Configuring GPIO pins.
  - Reading and writing to GPIO pins.
  - Using delays and simple logic to toggle output pins.
- Example highlights:
  - Configure `GPIOC Pin 13` as input with pull-down.
  - Configure `GPIOC Pin 0` as general-purpose output.
  - Blink an LED based on the state of a button.

### **2. `gpiolib.c`**
- Contains the implementation of GPIO library functions:
  - `config_gpio`: Configure GPIO pins with specific mode and configuration.
  - `read_gpio`: Read the state of a GPIO pin.
  - `write_gpio`: Write a state to a GPIO pin.
- Detailed comments explaining:
  - Functionality.
  - Logical vs. actual hardware register offsets.
  - Usage examples.

### **3. `gpio_header.h`**
- Header file with:
  - Macro definitions for ports, modes, and configurations.
  - Prototypes for GPIO library functions.
  - Register base addresses and RCC clock control definitions.

---

## **Usage**

### **1. Include the Header**
Include the `gpio_header.h` file in your application:
```c
#include "gpio_header.h"

