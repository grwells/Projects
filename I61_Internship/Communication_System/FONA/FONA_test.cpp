#include "FONA.h"
#include <iostream>
#include <string>

int main(void){
	std::string dev = "/dev/ttyUSB0";
	int fd = serialOpen(dev.c_str(), 115200);
	
	std::string com = "AT";

	serialPuts(fd, com.c_str());
	//TODO: Make see if FONA has any output and parse
	if(
 	serialPuts(fd, com.c_str());

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
