#include "FONA.h"
#include <iostream>
#include <string>
#include <wiringSerial.h>

int main(void){
	wiringPiSetup();
	std::string dev = "/dev/ttyAMA0";
	int fd = serialOpen(dev.c_str(), 115200);
	
	std::string com = "AT";

	serialPuts(fd, com.c_str());
	serialPuts(fd, com.c_str());
	int charsAvail = serialDataAvail(fd);
	char output[6] = {};
	//TODO: Make see if FONA has any output and parse
	if(charsAvail > 0){
		for(int i = 0; i < charsAvail; i++){
			output[i] = serialGetchar(fd);
		}
	}

	std::cout << output << std::endl;
 	

	com = "AT+CMGF=1";

	serialPuts(fd, com.c_str());
	com = "AT+CMGS=\"2088013217\"";
	serialPuts(fd, com.c_str());
	std::string message = "Hello from FONA";
	serialPuts(fd, message.c_str());
	
	/*
	std::cout << "Starting test" << std::endl;
    std::system("sudo screen /dev/ttyUSB0 115200");
	std::system("AT");
	std::system("AT");
	
	std::system("AT+CMGF=1");
	std::system("AT+CMGS=\"2088013217\"");
	std::system("Hello from FONA");	
	*/
}
