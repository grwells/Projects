# DS18B20 Temperature Sensor:
The DS18B20 temerature sensor uses the one-wire protocol to communicate with the parent controller. The one-wire protocol means that the device can be operated with only two wires, one for ground and one for the data transmission/power. The sensor actually has three wires, one for ground, one for data transmission, and finally a dedicated power wire. The extra power wire is included so that the device can be operated without depending on the parent device for power. When true one-wire protocol is being used, the sensor is "parasitic", deriving all power from the parent.

## Data Sheets:
  * [DS18B20 Programmable Resolution 1-Wire Digital Thermometer](https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf)
  * [HydroPi Guide](https://myhydropi.com/ds18b20-temperature-sensor-on-a-raspberry-pi)
  * [Raspberry Pi Foundation Guide](https://www.modmypi.com/blog/ds18b20-one-wire-digital-temperature-sensor-and-the-raspberry-pi)

## Usage:
1. Initialize One-Wire Driver
Add the following line to the /boot/config.txt: dtoverlay=w1-gpio

1. Boot Drivers
Run the following commands from the commandline to make the drivers boot:
  1. `sudo modprobe w1-gpio`
  1. `sudo modprobe w1-therm`

1. List Connected Devices
  1. `cd /sys/bus/w1/devices`
  1. `ls`

1. Read File for Sensor Data
  1. `cat /sys/bus/w1/devices/deviceid/w1_slave`


File w1_slave should contain two lines of text. The first checks for errors, if it ends in YES, everything was successful. Otherwise it failed. The second line will contain the temperature data after "t=".
