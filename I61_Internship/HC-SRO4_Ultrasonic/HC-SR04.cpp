#include "HC-SR04.h"

/*
* Constructor for sensor
* @param triggerPin Clears sensor for data transmission
* @param echoPin Pin echo is measured from
*/
HCSR04::HCSR04(int triggerPin, int echoPin){
	echo = echoPin;
	trigger = echoPin;

	//Initailize wiringPi
	wiringPiSetup();

	//Set pin modes
	pinMode(triggerPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

float HCSR04::readTime(void) {
	//Drive trigger low for 2s
	digitalWrite(triggerPin, LOW);
	delay(2000);

	//Drive trigger high for 10 microseconds then drive low to read
	digitalWrite(triggerPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(triggerPin, LOW);

	//Record last time echo is low
	while (digitalRead(echo) == LOW) {
		pulseStart = high_resolution_clock::now();
	}

	//Record how long echo is high
	while (digitalRead(echo) == HIGH) {
		pulseEnd = high_resolution_clock::now();
	}

	//Calculate time in seconds
	duration<float> timeLapse = duration_cast<duration<float>>(pulseEnd - pulseStart);	//record first time point
	time = timeLapse.count() / 2;														//how long one leg of trip takes
}

/*
* Read the value in cm 
* @return The distance in cm
*/
float HCSR04::distance(bool systemOfMeasurement){
	float distance;	//How far to the object immediately in front of sensor

	//Speed of sound in air @ ~70 degrees F
	double ftpsecond = 1128.0;
	double mpsecond = 343.3;

	if (systemOfMeasurement == INCH){
		distance = (readTime() * ftpsecond) * 12; //distance in inches
	}else if(systemOfMeasurement == CM){
		distance = (readTime() * mpsecond) * 100; //distance in cm
	}
		
	return distance;
}

/*
* Read the value in cm
* @return The distance in cm
*/
float HCSR04::distanceMM(void){
	return distance(CM) * 10;
}


