/*
 * Tolako 5V Hall-Effect Current Sensor Source Code
 * @author Garrett Wells
 * @version 1.0
 */
#include "Tolako5V.h"

Tolako5V::Tolako5V(int pinNumber){
	wiringPiSetup(); //prints error message if fail
	pinNum = pinNumber;
	pinMode(pinNum, INPUT);
}

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

