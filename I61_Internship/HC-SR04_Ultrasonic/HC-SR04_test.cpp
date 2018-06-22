/*I61 Ministries License
 * This code may only be used with the written consent of I61 Ministries and partners.
 */

/* 
 * File:   HC-SR04_test.cpp
 * Author: deepg
 *
 * Created on May 8, 2018, 2:11 PM
 */

#include <wiringPi.h>
#include "../Debug_MessagePrinter/MSG_Printer.h"
#include "HC-SR04.h"

/*
 * 
 */
int main(int argc, char** argv) {
    MSG_Printer print;
    print.info_msg("Starting test...");
    
    print.info_msg("Initializing HC-SR04");
    //HCSR04 hc(4, 5);
    HCSR04 hc(5, 4);
    print.info_msg("Distance(in): " + std::to_string(hc.distance(IMPERIAL)));
    
    print.info_msg("Finishing test...");
    return 0;
}

