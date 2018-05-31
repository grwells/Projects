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

#include <wiringPi.h>
#include <wiringSerial.h>
#include <string.h>

class FONA{
public:
    FONA(std::string owner, std::string name, std::string address, float coordinateLocation[2]);

    void sendMSG(std::string address, std::string message);

    std::string getMSG(void);
    std::string deleteMessage(int messageNumber);

    std::string printMessages(void);

    float getLocation(void);

private:
    std::string addressBook[5]; //Saved addresses for frequent contacts

    std::string owner; //Name of the owner
    std::string name; //Unit specific name
    std::string address; //The phone number address, whatever

    float coordinates[2]; //The location of the unit
};


#endif /* FONA_H */

