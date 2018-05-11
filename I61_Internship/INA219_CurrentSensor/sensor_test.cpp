#include <wiringPi.h>
#include <wiringPiI2C.h>
#include "INA219.h"
#include "../Tolako5V_CurrentSensor/Tolako5V.h"
#include "../Debug_MessagePrinter/MSG_Printer.h"
#include "string"
#include "iostream"

class Test{
public:
	Test(void);
	void test_tolako5V(void);
	void test_INA219(void);
	wiringPiSetup();
	pinMode(5, OUTPUT);
	digitalWrite(5, HIGH);

private:
	MSG_Printer print;
};

Test::Test(void){
	print.info_msg(true, "Beginning testing...");
	test_tolako5V();
	test_INA219();
	print.info_msg(true, "Testing complete...");
}

void Test::test_tolako5V(void){
	print.info_msg(true, "Initializing Tolako5V on pin 5...");
	Tolako5V tolako;

	tolako.setPin(0);
	print.info_msg(true, "Tolako5V Reading: " + std::to_string(tolako.readCurrent()));
}

void Test::test_INA219(void){
	print.info_msg(true, "Initializing INA219...");
	INA219 ina;
	print.info_msg(ina.setup(), "Sensor initialized...");
	print.info_msg(true, "INA219 Reading: " + std::to_string(ina.getCurrent()));
}

int main(void){
	Test();
	return 0;
}
