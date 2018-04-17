# make file for batmanT
batmanT: batmanT.cpp INA219.o Tolako5V.o
	g++ -o -std=c++0x batmanT INA219.o Tolako5V.o -lwiringPi

INA219.o: INA219.cpp INA219.h
	g++ -c INA219.cpp 

Tolako5V.o: ../Tolako5V_CurrentSensor/Tolako5V.cpp ../Tolako5V_CurrentSensor/Tolako5V.h
	g++ -c ../Tolako5V_CurrentSensor/Tolako5V.cpp

clean:
	rm batmanT INA219.o Tolako5V.o