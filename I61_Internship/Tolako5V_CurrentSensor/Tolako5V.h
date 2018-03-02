#ifndef TOLAKO5V
#define TOLAKO5V

#include <string>
#include <wiringPi.h>

class Tolako5V
{
public:
	void setup(void);					//Calls wiringPi setup
	float readCurrent(int pinNumber);	//Performs an analog read on the sensor wire
	std::string print(void);			//Prints the current as a string

private:
	int pinNum;							//The number of the pin the sensor is connected to
	float current;						//The current measurement data from the last read
};

#endif TOLAKO5V