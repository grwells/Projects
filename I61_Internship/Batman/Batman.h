#ifndef BATMAN_H
#define BATMAN_H

//Environment--------------------------------
#include <wiringPi.h>
#include <iostream>
#include <chrono>
#include <thread>
//Open Source--------------------------------
#include "Tolako5V.h"
#include "INA219.h"
//-------------------------------------------

using namespace std::chrono;
class Batman{
private:
	//File Variables
	std::string filename = "journal_file.csv"; //csv data collection file 
	std::ofstream file_in;
	std::string data;                          //data to be written to the file

	//Data Variables
	float charge;   //total charge in the battery
	float currentI; //current that is flowing into the battery 
	float voltage;  //the voltage supplied to the battery

	//Time Variables
	float deltaT; //time between collections
	float timeT;  //total time test has been running
	high_resolution_clock::time_point startingPoint;
	high_resolution_clock::time_point endPoint;

	//Program Variables and Sensors
	bool keepCollecting;
	bool batteryIsLow = false;
	INA219 ina219;
	Tolako5V talako;

public:
	Batman(void);
	float getChargeLevel(void);		//Get the level of charge of the battery
	void logData(std::string data);
	void sendData(void);
	float getCurrent(void);
	float getVoltage(void);
	float calcCurrentCharge(void);
	bool batteryIsLow(void) ;	

};
#endif BATMAN_H