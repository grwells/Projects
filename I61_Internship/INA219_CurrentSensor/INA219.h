#ifndef INA_219
#define INA_219

#include <iostream>
#include <string>
#include <wiringPiI2C.h>

class INA219
{
  private:
    int fd;
    float current_mA;
    float voltage_mV;
    float currentRaw;    
    bool setupSuccess;

  public:
    INA219(void);
  
    bool setup(void);
    bool setup(int ina_addr); 
    
    float getCurrent(); //Reads the current from the sensor in mA
    float getVoltage(); //Reads the current frm the sensor in mV
    std::string prints(void);
};
#endif
