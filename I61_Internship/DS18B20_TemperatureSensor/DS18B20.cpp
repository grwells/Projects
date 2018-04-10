#include "DS18B20.h"

/*
* Run the system setup commands for the sensor using the pi drivers
*/
DS18B20::DS18B20(void) {
	//INIT DRIVERS
	std::string serialNum = {"28-000005e2fdc3"}; //TODO replace serialNum with MAC address
	popen("sudo modprobe w1-gpio");
	popen("sudo modprobe w1-therm");
	FILE sensorData = popen("cat /sys/bus/w1/devices/" + serialNum + "/w1_slave", "r");
}

/*
* Run the setup for the commands, and use open source libraries
*/
DS18B20::DS18B20(int pinNumber) {
	//DO STUFF THE HARD WAY!!!
	std::cout << "[ERROR]: not implemented yet..." << std::endl;
}

/*
* Read the sensor value from the system file
* @return float The sensor reading in degrees C
*/
float DS18B20::read(void) {
	//TODO
	//finish method :)
	//
	return 0.0;
}

/*
* Print the sensor value
* @return string The temperature expressed as a string
*/
std::string DS18B20::print(void) {
	return std::to_string(read());
}
