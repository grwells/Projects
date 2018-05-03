#ifndef DS18B20_H
#define DS18B20_H

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

#define DS18B20_PATH "/sys/bus/w1/devices/MAC_ADDRESS/w1_slave"

class DS18B20 {
public:
    DS18B20(void); //Call the system setup commands
    DS18B20(int pinNumber); // Use open source
    float read(void); //Read from the system file
    std::string print(void); //Print the temperature

private:
    std::string filename;
};

#endif // !DS18B20
