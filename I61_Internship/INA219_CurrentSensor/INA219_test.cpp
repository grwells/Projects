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

MSG_Printer print;

INA219 inaA;
INA219 inaB;

bool a-successful = false;
bool b-successful = false;

/*
 * Tests 2xINA219
 */
void test1(void){
    print.info_msg("Testing at 16V settings...");
        
    if(a_successful){
        print.info_msg("INA219-A setup successful...");
        inaA.set_16V_400mA();  
        print.info_msg("INA219-A Curren(mA)t: " + std::to_string(inaA.getCurrent_mA()));
        print.info_msg("INA219-A Voltage(mV): " + std::to_string(inaA.getShuntVoltage_mV()));
    }
    
    if(b_successful){
        print.info_msg("INA219-B setup successful...");
        inaB.set_16V_400mA();
        print.info_msg("INA219-B Current(mA): " + std::to_string(inaB.getCurrent_mA()));
        print.info_msg("INA219-B Voltage(mV): " + std::to_string(inaB.getShuntVoltage_mV()));
    }
}

/*
 * Tests 2xINA219
 */
void test2(void){
    print.info_msg("Testing with default settings...");

    if(a_successful){
        print.info_msg("INA219-A setup successful...");
        inaA.set_32V_1A();  
        print.info_msg("INA219-A Curren(mA)t: " + std::to_string(inaA.getCurrent_mA()));
        print.info_msg("INA219-A Voltage(mV): " + std::to_string(inaA.getShuntVoltage_mV()));
    }
    
    if(b_successful){
        print.info_msg("INA219-B setup successful...");
        inaB.set_32V_1A();
        print.info_msg("INA219-B Current(mA): " + std::to_string(inaB.getCurrent_mA()));
        print.info_msg("INA219-B Voltage(mV): " + std::to_string(inaB.getShuntVoltage_mV()));
    }
}

/*
 * Tests 2xINA219
 */
void test3(void){
    print.info_msg("Testing 32V 1A settings...");
        
    if(a_successful){
        print.info_msg("INA219-A setup successful...");
        inaA.set_32V_1A();  
        print.info_msg("INA219-A Curren(mA)t: " + std::to_string(inaA.getCurrent_mA()));
        print.info_msg("INA219-A Voltage(mV): " + std::to_string(inaA.getShuntVoltage_mV()));
    }
    
    if(b_successful){
        print.info_msg("INA219-B setup successful...");
        inaB.set_32V_1A();
        print.info_msg("INA219-B Current(mA): " + std::to_string(inaB.getCurrent_mA()));
        print.info_msg("INA219-B Voltage(mV): " + std::to_string(inaB.getShuntVoltage_mV()));
    
    }
}

/*
 * Tests 2xINA219
 */
void test4(void){
    print.info_msg("Testing 32V 2A settings...");
        
    if(a_successful){
        print.info_msg("INA219-A setup successful...");
        inaA.set_32V_2A();  
        print.info_msg("INA219-A Curren(mA)t: " + std::to_string(inaA.getCurrent_mA()));
        print.info_msg("INA219-A Voltage(mV): " + std::to_string(inaA.getShuntVoltage_mV()));
    }
    
    if(b_successful){
        print.info_msg("INA219-B setup successful...");
        inaB.set_32V_2A();
        print.info_msg("INA219-B Current(mA): " + std::to_string(inaB.getCurrent_mA()));
        print.info_msg("INA219-B Voltage(mV): " + std::to_string(inaB.getShuntVoltage_mV()));
    }
}

int main(int argc, char** argv) {
    print.info_msg(true, "Starting test...");

    if(inaA.setup()){
        a_successful = true;
    }

    if(inaB.setup(0x41)){
        b_successful = true;
    }

    test2();
    test1();
    test3();
    test4();
    

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

