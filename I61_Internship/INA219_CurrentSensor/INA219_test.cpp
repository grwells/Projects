/*I61 Ministries License
 * This code may only be used with the written consent of I61 Ministries and partners.
 */

/* 
 * File:   INA219_test.cpp
 * Author: deepg
 *
 * Created on May 8, 2018, 1:54 PM
 */

#include <wiringPi.h>
#include "../Debug_MessagePrinter/MSG_Printer.h"
#include "INA219.h"

/*
 * Tests INA219
 */
int main(int argc, char** argv) {
    MSG_Printer print;
    print.info_msg(true, "Starting test...");
    
    print.info_msg(true, "Setting up INA219...");
    INA219 ina;
    print.error_msg(!ina.setup(), "INA219 setup failed...");
    
    print.info_msg(true, "Voltage: " + std::to_string(ina.getVoltage())); 
    print.info_msg(true, "Current: " + std::to_string(ina.getCurrent()));
    
    print.info_msg(true, "Ending test..");
    
    return 0;
}

