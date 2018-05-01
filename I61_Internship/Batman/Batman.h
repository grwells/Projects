#ifndef BATMAN_H
#define BATMAN_H

//Environment-------------------------------------------------------------------
#include <wiringPi.h>
#include <iostream>
#include <chrono>
#include <thread>
//------------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////
//Open Source-------------------------------------------------------------------
#include "../Tolako5V_CurrentSensor/Tolako5V.h"
#include "INA219.h"
#include "../Debug_MessagePrinter/Debug_MessagePrinter.h"
//------------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////
//Macros------------------------------------------------------------------------
#define CSV "journal_batman.csv"

#define DEBUG_ON true
#define DEBUG_OFF false

#define RECORD_YES true
#define RECORD_NO false

#define PRINT_YES true
#define PRINT_NO false
//Name Spaces-------------------------------------------------------------------
using namespace std::chrono;
//------------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////

struct Data{
    
    //System Data
    float currentIN;
    float currentOUT;
    float systemVoltage;
    float netCharge;
    bool batteryIsLow = false;
    
    //Time
    float time_step;
    float total_time;
    
};

class Batman{
private:
	//File Variables
	std::string filename = CSV; //csv data collection file 
	std::ofstream file_in;
	std::string data;                          //data to be written to the file

	//Time Variables
	high_resolution_clock::time_point startingPoint;
	high_resolution_clock::time_point endPoint;

	//Program Variables and Sensors
	bool keepCollecting;	
	INA219 ina219;
	Tolako5V talako;

public:
	Batman(bool prnt_debug, bool record_data, bool print_data); 
	float getChargeLevel(void);                                 //Get the level of charge of the battery
	void logData(std::string data);                             //Prints data to a file as a string
	void sendData(void);                                        //Sends the data to the user when necessary
	float getCurrent(void);                                     //Measure the net current flow
	float getVoltage(void);                                     //Measures the voltage on the INA219
	float calcCurrentCharge(void);                              //Calculates the state of the battery based on current flow over time
	bool batteryIsLow(void);                                    //If true the user better charge or replace battery
        int[] print_data(void);                                     //Prints the data collected to an array of vals

};
#endif BATMAN_H