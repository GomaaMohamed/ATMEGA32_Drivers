# Atmega32_Drivers
## Microcontroller Abstraction Layer (MCAL) for Atmega32
```
This is a collection of device driver libraries for the Atmega32 microcontroller.
The libraries provide low-level access to various hardware peripherals and features of
the microcontroller, such as GPIO, ADC, EXTI, Timers, UART, SPI, I2C, WDG, EEPROM, etc.
```
## Hardware Abstraction Layer (HAL)
```
This is a collection of device driver libraries for some of hardware devices.
such as LED, BUZZER, LCD, KEYPAD, SEVEN SEGMENTS, EXTERNAL EEPROM, REAL TIME CLOCK,
GPS, SERVO MOTOR, ULTRA SONIC, LM35, PUSH BUTTON, etc.
```

## Installation
```
To use these device drivers in your projects, simply download the source code or clone 
this repository. You can then include the necessary header files and source files in your
code and link against the compiled library.
```
## Usage
#### To use the device drivers provided by these libraries, follow these steps:
```
>> Initialize the necessary hardware peripherals using the provided initialization 
   functions (e.g., ADC_Init, GPIO_Init, TIMER0_Init, LCD_init etc.).
>> Use the various functions provided by the libraries to interact with the hardware
   peripherals (e.g., GPIO_setPinDirection, etc.).
>> Be sure to properly configure and manage interrupts using the provided
   functions (e.g., EXTI_Init, etc.).
>> When you are finished using the device drivers, be sure to disable any interrupts and
   resources that were enabled by the libraries.
```
## Configuration
```
>> The libraries provide configuration options that allow you to customize the behavior of the
   device drivers. For example, you can configure the GPIO pins as input or output, or configure
   the Timers to use a specific clock source and prescaler.
>> To configure the libraries, you can modify the configuration files (MOD_config.h )
   to define the appropriate configuration macros. Alternatively, you can define the
   macros directly in your code before including the relevant header files.
```
## License
```
These device driver libraries are released under the GNU GPL License ↗. Feel free to use them in
your own projects, modify them, and distribute them as needed. If you find any issues or have
suggestions for improvement, please open an issue or submit a pull request.
```
