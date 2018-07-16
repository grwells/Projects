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
    this-> coordinates[0] = coordinateLocation[0];
    this-> coordinates[1] = coordinateLocation[1];
    
    //Start system and then
    std::system("screen /dev/ttyAMA0 115200");
    //set default baud with: 'AT'
    std::system("AT");
}

FONA::FONA(void){
    std::cout << "Simple start for quick tests and simple debug" << std::endl;
    
    this -> owner = "owner";
    this -> name = "device_id";
    this -> address = "home";
    this -> coordinates[0] = 0.0;
    this -> coordinates[1] = 0.0;
    
    std::system("screen /dev/ttyAMA0 115200"); //Start interface with FONA
    std::system("AT"); //Set to default Baud rate, if returns 'OK' to interface, command was successful
}

/*
 * Sends a message to another user
 * @param string address: The address of the recipient
 * @param string message: The message to be sent to the user
 */
int FONA::sendText(std::string address, std::string message){
    //TODO: Send a text to somebody
    
    //Set to text mode: AT+CMGF=1
    std::system("AT+CMGF=1");
    
    //Send message: AT+CMGS="nnnnnn" 
    std::system("AT+CMGS=\"" + address + "\""); //Tell the FONA that you want to send a message
    std::system(message); //Print the message to the command line
    std::system("\x1A"); //Send the message with Ctrl-z
    
    //TODO: if cmdline returns 'OK' return good reading, otherwise return -1
    return 0;
}

/*
 * Calls some other phone
 * @param std::string phone_num: The number of the phone to call
 * @return int: 1 if successful, -1 if not
 */
int FONA::callNum(std::string phone_num){
    //TODO: Call somebody (867-5309 ;) )
    
    //To dial a number: ATDnnnnn;
    std::system("ATD" + phone_num + ";");
    //Hang up with: ATH
    std::system("ATH");
    
    return 0;
}

/*
 * Gets a message that the unit has received from another unit
 * return string: The message in the system memory
 */
std::string FONA::getText(void){
    //TODO: Receive text message
    
    //TODO: see if this functionality is actually possible
    return "";
}

/*
 * Prints the messages that the unit has received
 * @return string: The messages
 */
std::string FONA::printText(void){
    //TODO: make sure this possible...
    return "TODO: everything...";
}

/*
 * Deletes a selected message
 * @param int messageNumber: The number of the message to be accessed
 * @return string: The message that was deleted
 */
std::string FONA::deleteText(int messageNumber){
    //TODO: make sure this possible...
    return "TODO: everything...";
}

/*
 * Accesses the location of the unit using the gps unit attached to the FONA
 * @return float: The location of the unit should be a float array
 */
float FONA::getLocation(void){
    //Figure out how to read GPS function
    return 0.0;
}

int startVerbose(void){
    //AT+CMEE=2
    std::system("AT+CMEE=2"); //Print verbose comments for all commands entered
    
    //TODO: check for 'OK' and then return
    return 0;
}

bool isConnected(void){
    //AT+COPS
    std::system("AT+COPS");
    
    //TODO: check return, if true then connected other wise not
    return false;
}

int signal(void){
    //AT+CSQ 
    std::system("AT+CSQ"); //Check to see if the module has a signal
    
    //TODO: implement return
    return 0;
}

int batteryState(void){
    //AT+CBC
    std::system("AT+CBC");
    
    //TODO: implement return statement
    return 0;
}
    