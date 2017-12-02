# Arduino MECCANO / ERECTOR Infrared Library
This is not a "real" library. Just put it in jour sketch folder
## Features:
- Four channels (A, B, C, D)
- Same functionality as the original MECCANO transmitter (just forward, backwards, stop).
- The pulse arrays are stored in PROGMEM in order to save precious RAM
- Please note, that the pin numbers are hardcoded! Change them if needed.

New in V 1.1:
- Stop IR codes added in order to allow faster motor stop

New in V 1.2:
- Support for STM32F1 ARM MCU added

## Usage:

See [example](https://github.com/TheDIYGuy999/MeccanoIr/blob/master/MeccanoIr.ino).


(c) 2016 TheDIYGuy999
