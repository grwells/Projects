#include "PC.h"

/*
* Initializes wiringPi and sets the pinMode for the pump controller
* @param controlPin The pin the pump is connected to via relay
*/
PC::PC(int controlPin){
	pinNumber = controlPin;
	wiringPiSetup();
	PinMode(pinNumber, OUTPUT);
}

/*
* Checks to see if power is being supplied to the pump
* @return bool True if the pump is has power and false if not
*/
bool PC::powerOn(void){
	return powerState;
}

/*
* Sets the pin to HIGH and supplies power to the pump
*/
void PC::turnOn(void){
	powerState = ON;
	digitalWrite(pinNumber, HIGH);	
}

/*
* Sets the pin to LOW and cuts power to the pump
*/
void PC::turnOff(void){
	powerState = OFF;
	digitalWrite(pinNumber, LOW);
}