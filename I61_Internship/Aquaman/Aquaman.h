#ifndef AQUAMAN_H
#define AQUAMAN_H

//Environment--------------------------------
#include <wiringPi.h>
#include <iostream>
#include <string>
//Open Source--------------------------------
#include "HC-SR04.h"
#include "DS18B20.h"
#include "PC.h"
//-------------------------------------------

class Aquaman{
public:
	Aquaman(void);								//Initialize all sensors
	void collectData(void);				//Collect Temp and and water level
	float getWaterLevel(void);		//Collect water level
	float getWaterTemp(void);			//Collect water temperature
	void sendData(void);					//Send the data to other network members
	void dumpGallons(int gallons);//Release gallons
	void fillTank(void);					//Run pump until tank is full
	void pumpGallons(int gallons);//Pump gallons into the tank

private:
	bool tankIsFull = false;
};
#endif
