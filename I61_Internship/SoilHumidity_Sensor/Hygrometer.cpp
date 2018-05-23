#include "Hygrometer.h"

Hygrometer::Hygrometer(int pinNum){
  wiringPiSetup();
  pinMode(pinNum, INPUT);
  pinNumber = pinNum;
}

/*
 * Performs a simple read whether the soil is dryer than the calibrated moisture level or not
 * @return bool: Returns true if the soil is too dry and false if it is moist
 */
bool Hygrometer::soil_isDry(void){
  return (digitalRead(pinNumber) == LOW);
}

/*
 * Read the percentage water level of the soil
 * @return float: The percentage water in the soil
 */
float Hygrometer::readAnalog(void){
  //TODO
  // finish code
  return 0.0;
}
