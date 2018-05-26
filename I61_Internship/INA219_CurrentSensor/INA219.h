#ifndef INA_219
#define INA_219

#include <iostream>
#include <string>
#include <wiringPiI2C.h>

class INA219
{
  private:
    int fd;
    int ina219_calValue = 4096;
    int current_Divider_mA = 1;
    int ina219_powerDivider_mW = 1;
    bool setupSuccess;

  public:
    INA219(void); //Default constructor, does nothing except initialize global variables
 
    //Setup Functions-------------------------------------------------------------------------------------------- 
    bool setup(void); //Sets the current sensor with default values
    bool setup(int ina_addr); //Sets the current specified by the supplied addrss 

    //Configure--------------------------------------------------------------------------------------------------
    void set_32V_1A(void); //Set the sensor to read values at or below 32 Volts and 1 Amp
    void set_32V_2A(void); //Set the sensor to read values at or below 32 Volts and 2 Amps
    void set_16V_400mA(void); //Set the sensor to read values at or below 16 Volts and 400 milliAmps

    //Current Functions------------------------------------------------------------------------------------------
    float getCurrent_mA(void); //Reads the current from the sensor in milliAmps
    float getCurrent_A(void); //Reads the current from the sensor and converts to Amps

    //Voltage Functions------------------------------------------------------------------------------------------
    float getShuntVoltage_mV(void); //Reads the voltage between V- and V+, this is the voltage drop across the shunt resistor
    float getShuntVoltage_V(void); //Reads the shunt voltage and converts to Volts

    float getBusVoltage_mV(void); //Reads the voltage across GND and V-, the total voltage seen by the circuit under test
    float getBusVoltage_V(void); //Reads the bus voltage and converts to Volts

    std::string prints(void);
};
#endif
