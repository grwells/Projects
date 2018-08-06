#include <string>
#include <fstream>
#include <iostream>

#include "/home/pi/Documents/GitHub/Personal/Projects/I61_Internship/Communication_System/CommSys.h"

int main(void){
    std::ifstream file;
    file.open("waterlevel.log");
    
	std::string waterlevel;
	std::getline(file, waterlevel);
	
    std::cout << "water level: " << waterlevel << std::endl;

    //Send the data to the user
    //TODO: send data! UP and AWAY!

    std::cout << "Sent data to user" << std::endl; 
}
