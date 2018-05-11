#ifndef DS18B20_H
#define DS18B20_H

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include "../Debug_MessagePrinter/MSG_Printer.h"

#define DS18B20_PATH "/sys/bus/w1/devices/"
#define DS18B20_MAC "28-0316516533ff"

class DS18B20 {
public:
    DS18B20(std::string MAC_address); //Call the system setup commands
    DS18B20(int pinNumber); // Use open source
    DS18B20(void); //Call system setup with default MAC address
    
    float read(void); //Read from the system file
    std::string printTemp(void); //Print the temperature

private:
    std::string filename;
    MSG_Printer prints;
};

#endif // !DS18B20
