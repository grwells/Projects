hygrometer: Hygrometer_test.cpp Hygrometer.cpp Hygrometer.h MSG_Printer.o
	g++ -o Hygrometer_T Hygrometer_test.cpp Hygrometer.cpp MSG_Printer.o -lwiringPi

MSG_Printer.o: ../Debug_MessagePrinter/MSG_Printer.cpp ../Debug_MessagePrinter/MSG_Printer.h
	g++ -c ../Debug_MessagePrinter/MSG_Printer.cpp -o MSG_Printer.o

clean:
	rm Hygrometer_T MSG_Printer.o
