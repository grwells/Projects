#ifndef BATMAN_H
#define BATMAN_H

//Environment-------------------------------------------------------------------
#include <wiringPi.h>
#include <fstream>
#include <iostream>
#include <chrono>
#include <thread>
//------------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////
//Open Source-------------------------------------------------------------------
#include "../Tolako5V_CurrentSensor/Tolako5V.h"
#include "../INA219_CurrentSensor/INA219.h"
#include "../Debug_MessagePrinter/MSG_Printer.h"
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
//------------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////
//Name Spaces-------------------------------------------------------------------
using namespace std::chrono;
//------------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////

struct Data {
    //System Data
    float currentIN = 0.0; //The current reading from the input sensor
    float currentOUT = 0.0; //Current reading from the load sensor
    float netCurrentFlow = 0.0; //Net current flow 
    float systemVoltage = 0.0; //The system voltage, read from the input sensor
    float netCharge = 0.0; //The net charge of the battery in milliamps
    bool batteryIsLow = false; //TODO: Implement battery charge checking    
    float maxCharge = 0.0; //The maximum potential charge of the battery

    //Time
    float time_point = 0.0; //The last point in time the loop started(milliseconds)
    float time_step = 0.0; //The change in the time(seconds)
    float total_time = 0.0; //How long the system has been running in seconds

} data;

class Batman {
private:
    MSG_Printer print;
    
    //File Variables
    std::string filename = CSV; //CSV data collection file 
    std::ofstream file_in;
    std::string data_string; //data to be written to the file
    
    //Time Variables
    high_resolution_clock::time_point startingPoint;
    high_resolution_clock::time_point endPoint;

    //Program Variables and Sensors
    bool debug, verbose, record; 
    int linesToCollect; //How many lines of data to collect before killing program
    float chargeLowerLim; //If battery charge dips below this level the user is alerted to perform system maintenance
    INA219 input; //Sensor that read the input current, the current going to the battery
    INA219 output; //Sensor that read the current to the load from the battery

public:
    Batman(bool print_debug); //Do not record data, only print debug statements if needed
    Batman(bool print_debug, bool record_data, bool print_data); //Record an unlimited number of lines of data
    Batman(bool print_debug, bool record_data, int number_of_Lines); //Record a set number of lines of data and then return
    
    float getChargeLevel(float *netCharge, float *maxCharge); //Get the level of charge of the battery
    float calcCurrentCharge(float *netCharge, float *time_step); //Calculates the state of the battery based on current flow over time

    void logData(std::string filename, std::string data); //Prints data to a file as a string    
    void sendData(void); //Sends the data to the user when necessary
    void sendWarning(std::string message); //Sends a warning message to the user when something goes wrong
    bool batteryIsLow(void); //If true the user better charge or replace battery
    int[] print_data(void); //Prints the data collected to an array of values

    float getCurrent(float *currentIn, float *currentOut, float *netCurrentFlow); //Measure the net current flow
    float getVoltage(float *voltage); //Measures the voltage on the INA219

    

};
#endif BATMAN_H
