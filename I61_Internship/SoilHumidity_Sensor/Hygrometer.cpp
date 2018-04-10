#include "Hygrometer.h"

Hygrometer::Hygrometer(int pinNum){
  wiringPiSetup();
  pinMode(pinNum, INPUT);
}

bool Hygrometer::read(void){
  soilIsDry = analogRead(pinNum);
  return soilIsDry;
}

float Hygrometer::readAnalog(void){
  //TODO
  // finish code
  return 0.0;
}
