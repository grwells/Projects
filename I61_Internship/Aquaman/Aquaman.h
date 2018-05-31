#ifndef AQUAMAN_H
#define AQUAMAN_H

//Environment-------------------------------------------------------------------
#include <wiringPi.h>
#include <iostream>
#include <string>
#include <fstream>
//------------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////
//Open Source-------------------------------------------------------------------
#include "../HC-SRO4_Ultrasonic/HC-SR04.h"
#include "../DS18B20_TemperatureSensor/DS18B20.h"
#include "../Power_Controller/PC.h"
#include "../Debug_MessagePrinter/MSG_Printer.h"
//------------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////
//Macros------------------------------------------------------------------------
#define AQUAMAN_CSV "aquaman_journal.csv"
#define AQUAMAN_CONFIG "aquaman.config"
#define AQUAMAN_CSV_HEADER "Temperature, Water Level, HC-SR04 Primary, HC-SR04 Secondary, HC-Failsafe"

//HC-SR04 Pins
#define HC_TRIGGER 26
#define PRIMARY_ECHO 27
#define SECONDARY_ECHO 28
#define FAILSAFE_ECHO 29

//DS18B20 Pin
#define DS18B20 10

//Power Controller Pins---------------------------------------------------------
#define PC_1 6
#define PC_2 10
#define PC_3 11
#define PC_4 31
//------------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////

class Aquaman {
public:
    Aquaman(bool print_debug, bool print_verbose); //Initialize all sensors
	Aquaman(bool print_debug, bool print_verbose, bool debugMode); //Allows the user to run from command line
																   // without needing to write a config file
    void collectData(void); //Collect Temp and and water level, only used if writing to CSV
	void sendWarning(std::string data); //Send the data to other network members

    float getWaterLevel(void); //Collect water level
    float getWaterTemp(void); //Collect water temperature

  	void pumpGallons(int gallons); //Pump gallons into the tank
    void dumpGallons(int gallons); //Release gallons
    void fillTank(void); //Run pump until tank is full

	void pause(float time); //Pause for the alloted time in minutes


private:
    void readConfig(std::string config_filename); //Parses provided config file

    //IO
    bool debug = false;
    bool verbose = false;
  	bool debugMode = false;

    MSG_Printer print;

    std::string csv_filename;
    std::string config_filename;

    //Config Values
    bool systemOfMeasurement = IMPERIAL;
    float tankHeight = 0.0; //The total height of the tank, bottom to top, that can be filled with water
    float heightOffset = 0.0; //How far the bottom of the sensor is from the maximum water height
    float criticalLow = 0.0; //When the user wants to be notified that the water level is critically low

    //Water Level
    bool tankIsFull = false;
    bool tankIsEmpty = true;
    float primaryLevel = 0;
    float secondaryLevel = 0;
    float failsafeLevel = 0;

    //Temperature Data
    float temperature;

  	//Pump/Valve Variables
	float pumpflowRate = 0.0; //Number of gallons pumped per minute
    float valveflowRate = 0.0; //Galons per minute

    //Sensors
    DS18B20 tempSensor;
    HCSR04 primary(HC_TRIGGER, PRIMARY_ECHO);
    HCSR04 secondary(HC_TRIGGER, SECONDARY_ECHO);
    HCSR04 failsafe(HC_TRIGGER, FAILSAFE_ECHO);

    //Power Controllers
    PC pump(PC_1);
    PC release_valve(PC_2);
};
#endif
