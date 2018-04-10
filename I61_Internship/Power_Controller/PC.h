#ifndef POWERCONTROLLER
#define POWERCONTROLLER

#include <iostream>
#include <wiringPi.h>

const static bool ON = true;
const static bool OFF = false;

class PC{
public:
	PC(int controlPin);	//Set the pin for the pump control
	bool powerOn(void);	//Turn check if the pump is running
	void turnOn(void);
	void turnOff(void);

private:
	bool powerState = false;	//Whether the pump is on or off
	int pinNumber;				//The number of the pin the pump is connected to
};
#endif