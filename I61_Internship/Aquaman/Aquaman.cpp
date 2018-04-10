#include "Aquaman.h"

/*
* Initializes Aquaman
*/
Aquaman::Aquaman(void){}

/*
* Collects water level and temperature and stores it in a file
*/
void Aquaman::collectData(void){}

/*
* Packages the data as text and sends it via the communication service
*/
void Aquaman::sendData(void){}

/*
* Measures the water level in the storage tank
* @return float The water level in inches
*/
float Aquaman::getWaterLevel(void){}

/*
* Measures the temperature of the water in the tank
* @return float The temperature of the water in degrees Farenheit
*/
float Aquaman::getWaterTemp(void){}

/*
* Pumps some number of gallons into the tank
* @param gallons The number of gallons to be pumped into the tank
*/
void Aquaman::pumpGallons(int gallons);

/*
* Releases some number of gallons from the tank
* @param gallons The number of gallons to be released from the tank
*/
void Aquaman::dumpGallons(int gallons){}

/*
* Pumps water into the tank until the tank is full
*/
void Aquaman::fillTank(void){}
