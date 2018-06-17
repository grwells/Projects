#include <string>
#include <fstream>

#include "/home/pi/Documents/GitHub/Personal/Projects/I61_Internship/Communication_System/CommSys.h"

int main(void){
    //TODO: send message to the user containing the last water level value
    std::ifstream file;
    file.open("waterlevel.log");
    
    string waterlevel;
    file.getline(waterlevel);

    //Send the data to the user
    //TODO: send data! UP and AWAY!
}
