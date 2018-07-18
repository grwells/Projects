#include <string>
#include <fstream>
#include <iostream>

#include "/home/pi/Documents/GitHub/Personal/Projects/I61_Internship/HC-SR04_Ultrasonic/HC-SR04.h"

float tankHeight = -1; // This is the value read from the config file

float read_tankHeight_Config(void){
   //TODO: read the height of the tank from the config file
   //1- assign that value to tankHeight
   	
}

void sendWarning(void){
   //TODO: send message to the user, print to debug file for now
   std::ofstream file;
   file.open("debug.log");

   //TODO: start the pump... run until tank is full 
   //or something.

   file << "[ERROR]: water level dangerously low";
}

int main(void){
	
    std::cout << "Reading Water Level..." << std::endl;
    //Read the sensor values and store them in a log file
    std::string filename = "/home/pi/Documents/GitHub/Personal/Projects/I61_Internship/Scheduler/Cron/program_scripts/waterlevel.log";
    
    //Open the file to read
    std::ofstream file;
    file.open(filename, std::ios::app);
    
    //Initialize the sensor and read from it
    int echoPin = 4, trigPin = 5;
    HCSR04 hc(trigPin, echoPin);
    float distance_toH2O = hc.distance(IMPERIAL);    
    
    //Read config value to determine tank height
    if(tankHeight < 0){tankHeight = read_tnakHeight_Config();}
    
    //Use the value to decide whether or not to send message
    if(distance_toH2O >= (0.5*tankHeight)){sendWarning();}

    //Write the sensor values to the file
    //TODO: append the data, don't overwrite
    file << std::to_string(distance_toH2O);
   
    //Return!
    return 1;
}
