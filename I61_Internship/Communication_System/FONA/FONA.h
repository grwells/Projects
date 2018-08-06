/*I61 Ministries License
 * This code may only be used with the written consent of I61 Ministries and partners.
 */

/*
 * File:   FONA.h
 * Author: deepg
 *
 * Created on May 13, 2018, 8:15 PM
 */

#ifndef FONA_H
#define FONA_H

#include <wiringPi.h> //May not be needed
#include <wiringSerial.h> //Also may not be needed
#include <string> //std::string
#include <cstdlib> //std::system()
#include <stdio.h> //popen()

class FONA{

public:

    FONA(std::string owner, std::string name, std::string address, float coordinateLocation[2]);
    FONA(void);

    int sendText(std::string address, std::string message); //Sends a message to another unit
    int callNum(std::string phone_num); //Calls another FONA or cell phone

    std::string getText(void); //Pulls up all messages
    std::string deleteText(int messageNumber); //Deletes a message from device history

    std::string printText(void); //Prints all messages received
    
    int call_cmd(std::string command); //Calls the specified command, forcing the FONA to execute it
    
    //Unit status and functionality checks
    float getLocation(void); //Reads the GPS for current location and stores it for future reference
    int startVerbose(void); //Tells the FONA to print debug messages in the terminal for commands
    bool isConnected(void); //Returns true if the FONA connection is correctly configured and operational
    int signal(void); //Returns the state of the signal with the APN
    int batteryState(void); //The charge state of the battery

private:
    std::string addressBook[30]; //Saved addresses for frequent contacts

    std::string owner; //Name of the owner
    std::string name; //Unit specific name
    std::string address; //The phone number address, whatever

    float coordinates[2]; //The location of the unit
};


#endif /* FONA_H */

