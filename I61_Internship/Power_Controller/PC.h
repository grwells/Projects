#ifndef POWERCONTROLLER
#define POWERCONTROLLER

#include <iostream>
#include <wiringPi.h>

const static bool ON = true;
const static bool OFF = false;

class PC{
public:
	PC(int controlPin, bool default_State);	//Set the pin that is connected to the relay
	bool powerOn(void);	//Turn check if power the relay is connected and powered on
	void turnOn(void); //Turn on power to the relay
	void turnOff(void); //Turn off power to the relay

private:
	bool default_Power_State = OFF; //Default power state of the relay
	bool powerState = ON;	//Whether the relay is on or off
	int pinNumber; //The number of the pin the relay is connected to
};
#endif