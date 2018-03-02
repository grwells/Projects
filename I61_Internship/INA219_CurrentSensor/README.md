# INA219 Current Sensor
This sensor uses a resistor to measure the current and voltage values across a wire. It uses the I2C interface protocol and is fully configurable for varying levels of robustness and accuracy.

## Datasheets:
* [Texas Instruments](https://cdn-shop.adafruit.com/datasheets/ina219.pdf)
* [Adafruit](https://cdn-learn.adafruit.com/downloads/pdf/adafruit-ina219-current-sensor-breakout.pdf)

##Usage:
1. Enable I2C interface on pi through raspiconfig
1. Include I2C library from wiringPi/Pi4J
1. Assign address to sensor and complete setup
1. Read values from sensor using INA219 libraries
