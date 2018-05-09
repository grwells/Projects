hcsr04: HC-SR04_test.cpp MSG_Printer.o Ultrasonic.o
	g++ -o HCSR04_T HC-SR04_test.cpp Ultrasonic.o MSG_Printer.o -lwiringPi

Ultrasonic.o: HC-SR04.cpp HC-SR04.h
	g++ -c HC-SR04.cpp -o Ultrasonic.o

MSG_Printer.o: ../Debug_MessagePrinter/MSG_Printer.cpp ../Debug_MessagePrinter/MSG_Printer.h
	g++ -c ../Debug_MessagePrinter/MSG_Printer.cpp

clean:
	rm HCSR04_T MSG_Printer.o Ultrasonic.o
