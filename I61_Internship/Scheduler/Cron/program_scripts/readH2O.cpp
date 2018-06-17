#include <string>
#include <fstream>
#include <iostream>

#include "/home/pi/Documents/GitHub/Personal/Projects/I61_Internship/HC-SR04_Ultrasonic/HC-SR04.h"

void sendWarning(void){
   //TODO: send message to the user, print to debug file for now
   std::ofstream file;
   file.open("debug.log");

   file << "[ERROR]: water level dangerously low";
}

int main(void){
    //Read the sensor values and store them in a log file
    std::string filename = "waterlevel.log";
    
    //Open the file to read
    std::ofstream file;
    file.open(filename);
    
    //Initialize the sensor and read from it
    //TODO: remove comment below
    //HCSR04 hc(5,2);
    //float distance_toH2O = hc.read();    
    float distance_toH2O = 5;

    //Determine whether or not to send emergency message
    if(distance_toH2O >= (0.5*tank_height)){sendWarning();}

    //Write the sensor values to the file
    file << std::to_string(distance_toH2O);
   
    //Return!
    return 1;
}
