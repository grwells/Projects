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
#include <iostream>
#include <string>
#include "../Debug_MessagePrinter/MSG_Printer.h"
#include "INA219.h"

/*
 * Tests 2xINA219
 */
void test2(void){
    INA219 inaA;
    INA219 inaB;
    
    MSG_Printer print;

    print.info_msg(inaA.setup(), "INA219-A setup successful...");
    print.info_msg(inaB.setup(0x41), "INA219-B setup successful...");  

    print.info_msg("INA219-A Current: " + std::to_string(inaA.getCurrent()));
    print.info_msg("INA219-A Voltage: " + std::to_string(inaA.getVoltage()));

    print.info_msg("INA219-B Current: " + std::to_string(inaB.getCurrent()));
    print.info_msg("INA219-B Voltage: " + std::to_string(inaB.getVoltage()));
}

int main(int argc, char** argv) {
    MSG_Printer print;
    print.info_msg(true, "Starting test...");

    test2();

    /*
    print.info_msg(true, "Setting up INA219...");
    INA219 ina;
    print.error_msg(!ina.setup(), "INA219 setup failed...");
    
    print.info_msg(true, "Voltage: " + std::to_string(ina.getVoltage())); 
    print.info_msg(true, "Current: " + std::to_string(ina.getCurrent()));
    */
    print.info_msg(true, "Ending test..");
    
    return 0;
}

