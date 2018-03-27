#include <wiringPi.h>

//Setup Functions
int wiringPiSetup (void){return 0;}
int wiringPiSetupGpio (void){return 0;}
int wiringPiSetupPhys (void){return 0;}
int wiringPiSetupSys (void){return 0;}
void pinMode (int pin, int mode){}

//Analog Functions
int analogRead (int pin){return 0;}
void analogWrite (int pin, int value){}

//Digital Functions
void digitalWrite (int pin, int value){}
int digitalRead (int pin){return 0;}

//PWM
void pwmWrite (int pin, int value){}

//Timing Functions
unsigned int millis(void){return 0;}
unsigned int micros(void){return 0;}
void delay(unsigned int howLong){}
void delayMicroseconds(unsigned int howLong){}

//Raspberry Pi Specifics
void digitalWriteByte(int value){}
void pwmSetRange(unsigned int range){}
void pwmSetMode(int mode){}
void pwmSetClock(int divisor){}
int piBoardRev(void){return 0;}
int wpiPinToGpio(int wPiPin){return 0;}
int physPinToGpio(int physPin){return 0;}
void setPadDrive(int group, int value){}
