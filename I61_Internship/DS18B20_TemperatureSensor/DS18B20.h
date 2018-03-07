#ifndef DS18B20
#define DS18B20

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

class DS18B20
{
public:
	DS18B20(void);			//Call the system setup commands
	float read(void);		//Read from the system file
	std::string print(void);//Print the temperature
};

#endif // !DS18B20
