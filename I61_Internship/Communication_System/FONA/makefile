FONA: FONA.cpp FONA.h
	g++ -o FONA.o  FONA.cpp

test: FONA_test.cpp FONA.o
	g++ -o FONA_T FONA_test.cpp FONA.o -lwiringPi

clean: 
	rm FONA.o FONA_T
