#include "HC-SR04.h"

/*
* Constructor for sensor
* @param triggerPin Clears sensor for data transmission
* @param echoPin Pin echo is measured from
*/
HCSR04::HCSR04(int triggerPin, int echoPin){
	//print.info_msg(true, "Trigger Pin: " + std::to_string(triggerPin) + "\n    Echo Pin: " + std::to_string(echoPin));
	echo = echoPin;
	trigger = triggerPin;

	//Initailize wiringPi
	//print.info_msg(true, "Calling wiringPi setup...");
	wiringPiSetup();

	//Set pin modes
	//print.info_msg(true, "Setting trigger pin to OUTPUT, echoPin to INPUT");
	pinMode(triggerPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

float HCSR04::readTime(void) {
	//print.info_msg("Reading the time...");
	int pulseA, pulseB;

	//Drive trigger low for 2s
	//print.info_msg("Driving trigger LOW for 2 seconds...");
	digitalWrite(trigger, LOW);
	delayMicroseconds(5);

	//Drive trigger high for 10 microseconds then drive low to read
	//print.info_msg("Driving trigger HIGH for 10 microseconds...");
	digitalWrite(trigger, HIGH);
	delayMicroseconds(10);
	//print.info_msg("Driving trigger LOW...");
	digitalWrite(trigger, LOW);

	//Record last time echo is low
	while (digitalRead(echo) == LOW) {
		pulseA = micros();
	}

	//Record how long echo is high
	while (digitalRead(echo) == HIGH) {
		pulseB = micros();
	}

	//Calculate time in seconds
	//print.info_msg("pulseB(microseconds): " + std::to_string(pulseB) + "\n    pulseA(microseconds): " + std::to_string(pulseA));
	int timeElapsed = pulseB - pulseA;

	//print.info_msg("Measuring time...");
	time = timeElapsed /2;

	//print.info_msg("Total Time: " + std::to_string(timeElapsed));
	//print.info_msg("Total/2 = " + std::to_string(time));
	
	return time;
}

/*
* Read the value in cm 
* @return The distance in cm
*/
float HCSR04::distance(bool systemOfMeasurement){
	//print.info_msg(true, "Preparing to measure distance from front of sensor...");

	float distance;	//How far to the object immediately in front of sensor

	//Speed of sound in air @ ~70 degrees F
	double imperialConst = 74;
	double metricConst = 29.1;

	if (systemOfMeasurement == IMPERIAL){
	//	print.info_msg("Returning distance in inches...");
		distance = (readTime() / imperialConst); //distance in inches
	}else if(systemOfMeasurement == METRIC){
	//	print.info_msg("Returning distance in centimeters...");
		distance = (readTime() / metricConst); //distance in cm
	}
			
	return distance;
}

/*
* Read the value in cm
* @return The distance in cm
*/
float HCSR04::distanceMM(void){
	return distance(METRIC) * 10;
}


