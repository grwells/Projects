#include <wiringPiI2C.h>

//Setup Functions
int wiringPiI2CSetup(int devId){return 0;}

//Read Write Functions
int wiringPiI2CRead(int fd){return 0;}
int wiringPiI2CWrite(int fd, int data){return 0;}
int wiringPiI2CWriteReg8(int fd, int reg, int data){return 0;}
int wiringPiI2CWriteReg16(int fd, int reg, int data){return 0;}
int wiringPiI2CReadReg8(int fd, int reg){return 0;}
int wiringPiI2CReadReg16(int fd, int reg){return 0;}
