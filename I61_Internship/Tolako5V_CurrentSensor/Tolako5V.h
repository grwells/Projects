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
bool Tolako5V::setup(int pinNumber){
    pinNum = pinNumber;
    return wiringPiSetup();
};

/*
 * Read the current on the sensor
 * @return current The current flowing through the wires
 */
float Tolako5V::readCurrent(void){
    current = analogRead(pinNum); // Read the current flowing through the sensor
    current;
};

/*
 * Print the current as a string
 * @return current The current flowing through the wires
 */
string Tolako5V::print(void){
    return std::to_string(current);
}

