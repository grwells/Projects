demo: Demo.cpp HCSR04.o INA219.o DS18B20.o DHT11.o Hygrometer.o MSG_Printer.o
	g++ -o Demo Demo.cpp HCSR04.o INA219.o DS18B20.o DHT11.o Hygrometer.o MSG_Printer.o -lwiringPi

HCSR04.o: ../HC-SRO4_Ultrasonic/HC-SR04.cpp ../HC-SRO4_Ultrasonic/HC-SR04.h
	g++ -c ../HC-SRO4_Ultrasonic/HC-SR04.cpp -o HCSR04.o -lwiringPi

INA219.o: ../INA219_CurrentSensor/INA219.cpp ../INA219_CurrentSensor/INA219.h
	g++ -c ../INA219_CurrentSensor/INA219.cpp -o INA219.o

DS18B20.o: ../DS18B20_TemperatureSensor/DS18B20.cpp ../DS18B20_TemperatureSensor/DS18B20.h
	g++ -c ../DS18B20_TemperatureSensor/DS18B20.cpp -o DS18B20.o

DHT11.o: ../DHT11_HumiditySensor/DHT11.cpp ../DHT11_HumiditySensor/DHT11.h
	g++ -c ../DHT11_HumiditySensor/DHT11.cpp -o DHT11.o

Hygrometer.o: ../SoilHumidity_Sensor/Hygrometer.cpp ../SoilHumidity_Sensor/Hygrometer.h
	g++ -c ../SoilHumidity_Sensor/Hygrometer.cpp -o Hygrometer.o

MSG_Printer.o: ../Debug_MessagePrinter/MSG_Printer.cpp ../Debug_MessagePrinter/MSG_Printer.h
	g++ -c ../Debug_MessagePrinter/MSG_Printer.cpp -o MSG_Printer.o

clean:
	rm Demo HCSR04.o INA219.o DS18B20.o DHT11.o Hygrometer.o MSG_Printer.o
