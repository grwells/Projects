/*I61 Ministries License
 * This code may only be used with the written consent of I61 Ministries and partners.
 */

/* 
 * File:   DS18B20_test.cpp
 * Author: deepg
 *
 * Created on May 8, 2018, 2:39 PM
 */
#include "../DS18B20_TemperatureSensor/DS18B20.h"
#include "../Debug_MessagePrinter/MSG_Printer.h"

/*
 * 
 */
int main(int argc, char** argv) {
    MSG_Printer print;
    print.info_msg(true, "Starting test...");
    
    print.info_msg(true, "Initializing DS18B20...");
    DS18B20 ds18b20("28-0316516533ff");
    print.info_msg(true, "Temperature: " + ds18b20.print());
    
    print.info_msg(true, "Finishing test...");
    return 0;
}

