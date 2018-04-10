/*
 * Tolako 5V Hall-Effect Current Sensor Source Code
 * @author Garrett Wells
 * @version 1.0
 */
#include "Tolako5V.h"

#define TOLAKO_PIN 5

Tolako5V::Tolako5V(void){
	wiringPiSetup(); //prints error message if fail
	pinNum = TOLAKO_PIN;
	pinMode(pinNum, INPUT);
	current = 0.0;
}

/*
 * Set the pin that the sesor will read from to something other than the default
 * @param pinNumber The selected pin number
*/
void Tolako5V::setPin(int pinNumber){pinNum = pinNumber;}

/*
 * Read the current on the sensor
 * @return current The current flowing through the wires
 */
float Tolako5V::readCurrent(int pinNumber){
	pinMode(pinNumber, INPUT);
	current = analogRead(pinNumber); // Read the current flowing through the sensor
    	return current;
}

float Tolako5V::readCurrent(void) {
	current = analogRead(pinNum);
	return current;
}

/*
 * Print the current as a string
 * @return current The current flowing through the wires
 */
std::string Tolako5V::print(void){
    return std::to_string(current);
}

