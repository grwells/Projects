#include <wiringPi.h>
#include "../Tolako5V_CurrentSensor/Tolako5V.h"
#include "../Debug_MessagePrinter/MSG_Printer.h"

int main(void){
	wiringPiSetup();
	pinMode(5, INPUT);
	std::cout << std::to_string(digitalRead(5)) << std::endl;
	
	return 0;
}
