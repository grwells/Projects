#include "DS18B20.h"

/*
* Run the system setup commands for the sensor
*/
DS18B20::DS18B20(void) {
	//INIT DRIVERS
	std::system("sudo modprobe w1-gpio");
	std::system("sudo modprobe w1-therm");


}

/*
* Read the sensor value from the system file
* @return float The sensor reading in degrees C
*/
float DS18B20::read(void) {
	return 0.0;
}

/*
* Print the sensor value
* @return string The temperature expressed as a string
*/
std::string DS18B20::print(void) {
	return "";
}