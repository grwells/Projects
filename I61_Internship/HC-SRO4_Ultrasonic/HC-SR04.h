#ifndef HCSR04_H
#define HCSR04_H

#include <chrono>
#include <thread>
#include <wiringPi.h>
#include "../Debug_MessagePrinter/MSG_Printer.h"

using namespace std::chrono;

#define METRIC true
#define IMPERIAL false

class HCSR04 {
public:
    HCSR04(int triggerPin, int echoPin); //Initialize sensor
    float readTime(void); //Read the time for echo to return on default pin
    float distance(bool systemOfMeasurement); //Get distance in either inches or cm
    float distanceMM(); //Get distance in mm

private:
    int trigger; //The trigger pin
    int echo; //Echo pin
    float time; //How long for the sound wave to return
    high_resolution_clock::time_point pulseStart; //When echo starts
    high_resolution_clock::time_point pulseEnd; //WHen echo ends
    
    MSG_Printer print; //The debugging message printer

};

#endif
