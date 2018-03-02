/*
 * Tolako 5V Hall-Effect Current Sensor Source Code
 * @author Garrett Wells
 * @version 1.0
 */
#include "Tolako5V.h"

/*
 * Setup wiringPi and get the pin number from the user
 * @param pinNumber The pin that the sensor is connected to
 * @return bool if wiringPi setup function is successful return true
 */
void Tolako5V::setup(void){
    wiringPiSetup(); //prints error message if fail
};

/*
 * Read the current on the sensor
 * @return current The current flowing through the wires
 */
float Tolako5V::readCurrent(int pinNumber){
	pinMode(pinNumber, INPUT);
    current = analogRead(pinNumber); // Read the current flowing through the sensor
    return current;
};

/*
 * Print the current as a string
 * @return current The current flowing through the wires
 */
std::string Tolako5V::print(void){
    return std::to_string(current);
}

