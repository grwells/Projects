/*I61 Ministries License
 * This code may only be used with the written consent of I61 Ministries and partners.
 */
#include "FONA.h"

/*
 * Initialize the FONA
 * @param string owner: The name attached to the owner of the FONA
 * @param string name: The name of the unit, can be a geographical location reference
 * @param string address: The phone number used for contacting this unit
 * @param float coordinateLocation[2]: The location of the unit
 */
FONA::FONA(std::string owner, std::string name, std::string address, float coordinateLocation[2]){
    this-> owner = owner;
    this-> name = name;
    this-> address address;
    this-> coordinateLocation = coordinateLocation;
}

/*
 * Sends a messagee to another user
 * @param string address: The address of the recipient
 * @param string message: The message to be sent to the user
 */
void FONA::sendMSG(std::string address, std::string message){}

/*
 * Gets a message that the unit has received from another unit
 * return string: The message in the system memory
 */
std::string FONA::getMSG(void){}

/*
 * Prints the messages that the unit has received
 * @return string: The messages
 */
std::string FONA::printMessages(void){}

/*
 * Deletes a selected message
 * @param int messageNumber: The number of the message to be accessed
 * @return string: The message that was deleted
 */
std::string FONA::deleteMessage(int messageNumber){}

/*
 * Accesses the location of the unit using the gps unit attached to the FONA
 * @return float: The location of the unit should be a float array
 */
float FONA::getLocation(void){}