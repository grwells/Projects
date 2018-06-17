# HC-SRO4 Ultrasonic Sensor
The HC-SRO4 ultrasonic sensor can be used to measure distance. It is a four pin device with a voltage in pin, trigger pin, echo pin, and ground. Unfortunately it requires a special communication protocol to read data from the sensor.

## Datasheets:
* [ModMyPi.com](https://www.modmypi.com/blog/hc-sr04-ultrasonic-range-sensor-on-the-raspberry-pi)
* [Adafruit Industries](https://learn.adafruit.com/dht?view=all#using-a-dhtxx-sensor)

## Usage:
1. Set trigger pin to output, and drive it LOW for 2 microseconds to allow the sensor to settle. If this is not done the data may be inaccurate.
1. Drive the trigger pin HIGH for 10 micro-seconds and then drive it low again, to start calculating range. As part of calculating the range the sensor fires 8 ultrasound bursts at 40kHz which create an echo that the sensor reads.
1. Wait for the echo pin to be driven HIGH, then measure how long it is driven high.
1. Calculate the distance traveled by the sound. In inches this means (time/2) / 74. In cm it is (time/2) / 29.1.
