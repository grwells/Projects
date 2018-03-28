# Soil Humidity Sensor
The soil humidity sensor can determined the amount of moisture in soil by measuring the resistance between two charged metal forks. The sensor can be read as true or false, the moisture is detected or not, or the percent moisture can be measured via an analog signal. Reading via analog requires an ADC if used with Raspberry Pi, which does not have its own analog pin.

## Data Sheets:
* [modmypi.com(basic functionality tutorial)](https://www.modmypi.com/blog/raspberry-pi-plant-pot-moisture-sensor-with-email-notification-tutorial)
* [modmypi.com(analog signal tutorial)](https://www.modmypi.com/blog/raspberry-pi-plant-pot-moisture-sensor-via-analogue-signals)

## Usage:
1. Calibrate by setting sensor in soil that has a proper moisture level and turning potentiometer until detection light turns on. Detection light will turn off if the moisture level drops below desired level.
1. Poll the D0 pin, if the reading changes from low to high water needs to be added.
