ds18b20: DS18B20_test.cpp DS18B20.o MSG_Printer.o 
	g++ -o DS18B20_T DS18B20_test.cpp DS18B20.o MSG_Printer.o

DS18B20.o: DS18B20.cpp DS18B20.h
	g++ -c DS18B20.cpp	

MSG_Printer.o: ../Debug_MessagePrinter/MSG_Printer.cpp
	g++ -c ../Debug_MessagePrinter/MSG_Printer.cpp -o MSG_Printer.o

clean:
	rm MSG_Printer.o DS18B20_T
