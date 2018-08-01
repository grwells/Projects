#include "FONA.h"
#include <iostream>
#include <string>
#include <wiringSerial.h>

int main(void){

	if(wiringPiSetup() == -1) std::cout << "ERROR: setup failed" << std::endl;
	std::string dev = "/dev/ttyS0";
	int fd = serialOpen(dev.c_str(), 115200);

	if(fd < 0) std::cout << "ERROR: file descriptor < 0" << std::endl;
	
	std::string com = "AT";

	std::cout << "Sending commands" << std::endl;	
	serialPuts(fd, com.c_str());
	std::cout << "Available data: " << serialDataAvail(fd) << std::endl;
	delay(5000);

	serialPuts(fd, com.c_str());
	std::cout << "Available data: " << serialDataAvail(fd) << std::endl;
	delay(5000);

	serialPuts(fd, com.c_str());
	std::cout << "Available data: " << serialDataAvail(fd) << std::endl;
	delay(5000);

	std::cout << "Sending printf" << std::endl;
	serialPrintf(fd, com.c_str());
	std::cout << "Available data: " << serialDataAvail(fd) << std::endl;

	std::cout << "Getting available data" << std::endl;	
	int charsAvail = serialDataAvail(fd);

	char output[6] = {};

	//TODO: Check to see why serialDataAvail is returning -1 after sending 'AT' 2x
	std::cout << "chars available: " << charsAvail << std::endl;
	if(charsAvail > 0){
		for(int i = 0; i < charsAvail; i++){
			output[i] = serialGetchar(fd);
		}
	}else {
		std::cout << "Skipped loop" << std::endl;
	}

	std::cout << output << std::endl;
 	

	com = "AT+CMGF=1\x0D";
	serialPuts(fd, com.c_str());

	com = "AT+CMGS=\"2088013217\"\x0D";
	serialPuts(fd, com.c_str());

	std::string message = "Hello from FONA\x0D";
	serialPuts(fd, message.c_str());

	serialClose(fd);
}
