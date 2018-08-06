#include "FONA.h"
#include <iostream>
#include <string>
#include <wiringSerial.h>

/*
 * printDataAvail prints the data available over the serial connection
 * @param int fd: The file descriptor for the device that the serial is connected to
*/
void printDataAvail(int fd){
	int num = serialDataAvail(fd);

	for(int i = 0; i < num; i++){
			std::cout << serialGetchar(fd);
	}

	std::cout << std::endl;

	serialFlush(fd);

}

void trySerialPuts(int fd){
	std::string command = "AT\n\r";

	serialPuts(fd, command.c_str());

	int chars = serialDataAvail(fd);

	std::cout << "Chars Available: " << chars << std::endl;

	for(int i = 0; i < 2; i++){
		std::cout << serialGetchar(fd);
	}
	std::cout << "\n";

	serialFlush(fd);
}

void trySerialPutchar(int fd){
	unsigned char command = 'A';

	serialPutchar(fd, command);

	command = 'T';

	serialPutchar(fd, command);

	int chars = serialDataAvail(fd);
	std::cout << "Chars Available: " << chars << std::endl;

	for(int i = 0; i < 2; i++){
		std::cout << serialGetchar(fd);
	}
	std::cout << "\n";

	serialFlush(fd);
}

void trySerialPrintf(int fd){
	std::string command = "AT\n\r";

	serialPrintf(fd, command.c_str());

	int chars = serialDataAvail(fd);
	std::cout << "Chars Available: " << chars << std::endl;

	for(int i = 0; i < 2; i++){
		std::cout << serialGetchar(fd);
	}
	std::cout << "\n";

	serialFlush(fd);
}

int setup(void){
	if(wiringPiSetup() == -1) std::cout << "ERROR: setup failed" << std::endl;
	std::string dev = "/dev/ttyS0";
	//std::string dev = "/dev/ttyUSB0";
	int fd = serialOpen(dev.c_str(), 115200);
	serialFlush(fd); //Flush the line to make sure it is clean

	std::string command = "ATE0";

	serialPuts(fd, command.c_str());

	std::cout << "Chars Available: " << serialDataAvail(fd) << std::endl;
	serialFlush(fd);

	if(fd < 0) std::cout << "ERROR: file descriptor < 0" << std::endl;
	return fd;	
}

int main(void){
	
	int fd = setup(); //Setup wiringPi and serial connections
	
	/*
	 * TODO: Try printing "\n\r" to terminate commands
	 * TODO: call serial flush after all output has beeb processed
	 * TODO: Try the system read() and write() functions
	*/

	trySerialPuts(fd);
	trySerialPutchar(fd);
	trySerialPrintf(fd);

	//std::cout << "\n";

	serialFlush(fd);
	
	serialClose(fd);
	return 0;
}
