#ifndef DS18B20_H
#define DS18B20_H

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

const static int DS18B20_PIN = 10;

class DS18B20
{
public:
	DS18B20(void);					//Call the system setup commands
	DS18B20(int pinNumber); // Use open source
	float read(void);				//Read from the system file
	std::string print(void);//Print the temperature
};

#endif // !DS18B20
