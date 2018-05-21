#include <fstream>
#include "../DS18B20_TemperatureSensor/DS18B20.h"
#include "../INA219_CurrentSensor/INA219.h"
#include "../HC-SRO4_Ultrasonic/HC-SR04.h"
#include "../DHT11_HumiditySensor/DHT11.h"
#include "../SoilHumidity_Sensor/Hygrometer.h"
#include "../Debug_MessagePrinter/MSG_Printer.h"

MSG_Printer print;

HCSR04 hc(5, 4);
DS18B20 temp("28-0316516533ff");
DHT11 humidity(0);
Hygrometer hillary(2);
INA219 input;
INA219 ina2;


void readDS18B20(void){
	print.info_msg("Reading temperature...");
	print.msg("Temperature(Celsius): " + std::to_string(temp.read()), GREEN);
	print.msg("Temperature(Farenheit): " + std::to_string((temp.read() * 1.8) + 32), GREEN);
}

void readINA219(void){
	print.info_msg("Reading current sensors...");
	print.msg("Input(mA): " + std::to_string(input.getCurrent()), GREEN);
	print.msg("Output(mA): " + std::to_string(ina2.getCurrent()), GREEN);
}

void readHCSR04(void){
	print.info_msg("Reading Ultrasonic...");
	print.msg("Distance(inches): " + std::to_string(hc.distance(IMPERIAL)), GREEN);
}

void readHygrometer(void){	
	print.info_msg("Reading Hygrometer...");
	print.warning_msg(hillary.soil_isDry(), "Soil is dry, pour on the love!");
	if(!hillary.soil_isDry()){
	print.msg("Soil is fine, carry on", GREEN);
	}
}

void readDHT11(void){
	print.info_msg("Reading DHT11...");
	humidity.read();
}

int main(void){
	print.info_msg("Initializing sensors...");
	print.info_msg(input.setup(0x41), "Input current sensor setup successful");
	print.info_msg(ina2.setup(), "Output current sensor setup successful");

	while(true){
		readDS18B20();
		delay(2000); //Delay for 2 seconds
		
		readINA219();
		delay(2000); //Delay for 2 seconds

		readHCSR04();
		delay(2000); //Delay for 2 seconds

		readHygrometer();
		delay(2000);

		readDHT11();

		delay(5000); //Delay for 5 seconds

	}
	return 0;
}
