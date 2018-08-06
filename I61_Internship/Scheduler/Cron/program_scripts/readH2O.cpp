#include <string>
#include <fstream>
#include <iostream>

#include "/home/pi/Documents/GitHub/Personal/Projects/I61_Internship/HC-SR04_Ultrasonic/HC-SR04.h"
#include "home/pi/Documents/GitHub/Personal/Projects/I61I61_Internship/Communication_System/FONA/FONA.h"

void sendWarning(void){
   //TODO: send message to the user, print to debug file for now
   std::ofstream file;
   file.open("debug.log");

   file << "[ERROR]: water level dangerously low";
}

int main(void){
    //Read the sensor values and store them in a log file
    std::string filename = "/home/pi/Documents/GitHub/Personal/Projects/I61_Internship/Scheduler/Cron/program_scripts/waterlevel.log";

    //Open the file to read
    std::ofstream file;
    file.open(filename);

    //Initialize the sensor and read from it
    int echoPin = 4, trigPin = 5;
    HCSR04 hc(trigPin, echoPin);
    float distance_toH2O = hc.distance(IMPERIAL);

    //Determine whether or not to send emergency message
    //TODO: read config file to get tank height
    int tank_height = 20;
    if(distance_toH2O >= (0.5*tank_height)){sendWarning();}

    //Write the sensor values to the file
    //TODO: append the data, don't overwrite
    file << std::to_string(distance_toH2O);

    //Return!
    return 1;
}
