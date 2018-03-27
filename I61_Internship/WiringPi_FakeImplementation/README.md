# Wiring Pi Fake Implementations
All files in this directory can be used as substitutes for the wiringPi library on windows. Using these files the user can compile C++ files that include the wiringPi header. The result of compiling this way is not code that can be run, but a comprehensive analysis of whether or not the code compiles successfully without commenting out all references to wiringPi functions.

## Currently Implemented functions
  * [Setup](http://wiringpi.com/reference/setup/)
  * [Core Functions](http://wiringpi.com/reference/core-functions/)
  * [Raspberry Pi Specifics](http://wiringpi.com/reference/raspberry-pi-specifics/)
  * [Timing](http://wiringpi.com/reference/timing/)
  * [SPI Library](http://wiringpi.com/reference/spi-library/)
  * [I2C Library](http://wiringpi.com/reference/i2c-library/)
