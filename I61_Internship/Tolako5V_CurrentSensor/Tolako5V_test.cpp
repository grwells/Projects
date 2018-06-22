/*I61 Ministries License
 * This code may only be used with the written consent of I61 Ministries and partners.
 */

/* 
 * File:   Tolako5V_test.cpp
 * Author: deepg
 *
 * Created on May 8, 2018, 2:06 PM
 */

#include <wiringPi.h>
#include "../Debug_MessagePrinter/MSG_Printer.h"
#include "Tolako5V.h"

/*
 * 
 */
int main(int argc, char** argv) {
    MSG_Printer print;
    print.info_msg(true, "Starting test...");
    
    print.info_msg(true, "Initializing Tolako5V...");
    Tolako5V tolako;
    tolako.setPin(5);
    
    print.info_msg(true, "Current: " + std::to_string(tolako.readCurrent()));
    
    print.info_msg(true, "Finishing test...");
    return 0;
}

