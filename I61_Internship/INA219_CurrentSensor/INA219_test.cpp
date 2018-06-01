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

/*
 * Tests 2xINA219
 */
void test1(void){
    print.info_msg("Testing at 16V settings...");
    INA219 inaA;
    INA219 inaB;
    
    if(inaA.setup()){
        print.info_msg("INA219-A setup successful...");
        inaA.set_16V_400mA();  
        print.info_msg("INA219-A Curren(mA)t: " + std::to_string(inaA.getCurrent_mA()));
        print.info_msg("INA219-A Voltage(mV): " + std::to_string(inaA.getShuntVoltage_mV()));
    }else{
    	print.error_msg("\nINA219-A setup FAILED!\n");
    }
    
    if(inaB.setup(0x41)){
        print.info_msg("INA219-B setup successful...");
        inaB.set_16V_400mA();
        print.info_msg("INA219-B Current(mA): " + std::to_string(inaB.getCurrent_mA()));
        print.info_msg("INA219-B Voltage(mV): " + std::to_string(inaB.getShuntVoltage_mV()));
    }else{
    	print.error_msg("\nINA219-B setup FAILED!\n");
    }

}

/*
 * Tests 2xINA219
 */
void test2(void){
    print.info_msg("Testing with default settings...");

    INA219 inaA;
    INA219 inaB;
    
    if(inaA.setup()){
        print.info_msg("INA219-A setup successful...");
        inaA.set_32V_1A();  
        print.info_msg("INA219-A Curren(mA)t: " + std::to_string(inaA.getCurrent_mA()));
        print.info_msg("INA219-A Voltage(mV): " + std::to_string(inaA.getShuntVoltage_mV()));
    }else{
    	print.error_msg("\nINA219-A setup FAILED!\n");
    }

    if(inaB.setup(0x41)){
        print.info_msg("INA219-B setup successful...");
        inaB.set_32V_1A();
        print.info_msg("INA219-B Current(mA): " + std::to_string(inaB.getCurrent_mA()));
        print.info_msg("INA219-B Voltage(mV): " + std::to_string(inaB.getShuntVoltage_mV()));
    }else{
    	print.error_msg("\nINA219-B setup FAILED!\n");
    }
}

/*
 * Tests 2xINA219
 */
void test3(void){
    print.info_msg("Testing 32V 1A settings...");
    INA219 inaA;
    INA219 inaB;
    
    if(inaA.setup()){
        print.info_msg("INA219-A setup successful...");
        inaA.set_32V_1A();  
        print.info_msg("INA219-A Curren(mA)t: " + std::to_string(inaA.getCurrent_mA()));
        print.info_msg("INA219-A Voltage(mV): " + std::to_string(inaA.getShuntVoltage_mV()));
    }else{
    	print.error_msg("\nINA219-A setup FAILED!\n");
    }
    
    if(inaB.setup(0x41)){
        print.info_msg("INA219-B setup successful...");
        inaB.set_32V_1A();
        print.info_msg("INA219-B Current(mA): " + std::to_string(inaB.getCurrent_mA()));
        print.info_msg("INA219-B Voltage(mV): " + std::to_string(inaB.getShuntVoltage_mV()));
    
    }else{
    	print.error_msg("\nINA219-B setup FAILED!\n");
    }
}

/*
 * Tests 2xINA219
 */
void test4(void){
    print.info_msg("Testing 32V 2A settings...");
    INA219 inaA;
    INA219 inaB;
    
    if(inaA.setup()){
        print.info_msg("INA219-A setup successful...");
        inaA.set_32V_2A();  
        print.info_msg("INA219-A Curren(mA)t: " + std::to_string(inaA.getCurrent_mA()));
        print.info_msg("INA219-A Voltage(mV): " + std::to_string(inaA.getShuntVoltage_mV()));
    }else{
    	print.error_msg("\nINA219-A setup FAILED!\n");
    }
    
    if(inaB.setup(0x41)){
        print.info_msg("INA219-B setup successful...");
        inaB.set_32V_2A();
        print.info_msg("INA219-B Current(mA): " + std::to_string(inaB.getCurrent_mA()));
        print.info_msg("INA219-B Voltage(mV): " + std::to_string(inaB.getShuntVoltage_mV()));
    }else{
    	print.error_msg("\nINA219-B setup FAILED!\n");
    }
}

int main(int argc, char** argv) {
    print.info_msg(true, "Starting test...");

    test2();
    test1();
    test3();
    test4();
    

    print.success_msg("Test Complete");

    return 0;
}

