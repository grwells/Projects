#ifndef DHT11_H
#define DHT11_H

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../Debug_MessagePrinter/MSG_Printer.h"

class DHT11{
public:
	DHT11(int pinNum); //Initializes sensor on the specified pin
	float read(void); //Read the data

private:
	int pinNumber;
	int dht11_dat[5] = {0,0,0,0,0};
};

#endif
