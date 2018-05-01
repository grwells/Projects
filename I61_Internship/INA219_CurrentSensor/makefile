# make file for batmanT
batmanT: batmanT.cpp INA219.o Tolako5V.o Debug_MessagePrinter.o
	g++ -o batmanT -std=c++0x batmanT.cpp INA219.o Tolako5V.o Debug_MessagePrinter.o -lwiringPi

INA219.o: INA219.cpp INA219.h
	g++ -c INA219.cpp 

Tolako5V.o: ../Tolako5V_CurrentSensor/Tolako5V.cpp ../Tolako5V_CurrentSensor/Tolako5V.h
	g++ -c ../Tolako5V_CurrentSensor/Tolako5V.cpp

Debug_MessagePrinter.o: ../Debug_MessagePrinter/Debug_MessagePrinter.cpp ../Debug_MessagePrinter/Debug_MessagePrinter.h 
	g++ -c ../Debug_MessagePrinter/Debug_MessagePrinter.cpp

clean:
	rm batmanT INA219.o Tolako5V.o Printer.o
