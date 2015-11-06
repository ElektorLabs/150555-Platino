# 150555-Platino
Arduino compatible universal AVR board for 28-pin and 40-pin ATmega devices.

Platino is a board that address the ever returning problem of adding a user interface to a project. With 
Platino this is solved so that you can concentrate on your application instead of fiddling with low-level
drivers for user interfacing.

To achieve this Platino features footprints for pushbuttons, rotary encoders, a buzzer, an (RGB) LED, and an
LCD. Pushbuttons and rotary encoders have a flexible layout allowing a user interface adapted to the applications.
Platino supports 2 lines by 16 characters (2x16), 4x16 and 4x20 LCDs.

An Arduino library/core is available that contains drivers for all the peripherals, making programming easy.
Don't worry about debouncing pushbuttons, controlling LCDs or reading rotary encoders, the library handles it all
for you.

For even more flexibility Platino has solder jumpers to configure the board, allowing peripherals to be connected
to different ports.

Platino supports the following MCUs:
- ATmega8
- ATmega16
- ATmega32
- ATmega48 (not supported in Arduino IDE)
- ATmega88
- ATmega164
- ATmega168
- ATmega324
- ATmega328
- ATmega644
- ATmega1284

Arduino compatible bootloaders for all supported processors (except ATmega48) are available too.

For easy installation Platino is contained in a Board Package for the Arduino IDE, see https://github.com/ElektorLabs/Arduino
