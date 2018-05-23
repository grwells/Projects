#include <errno.h>
#include <stdint.h>
#include "INA219.h"

// INA219 VARIABLES ------------------------------------------------------------
#define INA219_ADDR                        (0x40)
#define INA219_COFIG                       (0x00)
#define INA219_SHUNTVOLTAGE                (0x01)
#define INA219_BUSVOLTAGE                  (0x02)
#define INA219_POWER                       (0x03)
#define INA219_CURRENT                     (0x04)
#define INA219_CALIBRATION                 (0x05)
//------------------------------------------------------------------------------

// INA219 CONFIG ---------------------------------------------------------------
#define INA219_BVOLTAGERANGE_32V           (0x2000)
#define INA219_GAIN_8_320MV                (0x1800)
#define INA219_BADCRES_12BIT               (0x0400)
#define INA219_SADCRES_12BIT_1S_532US      (0x0018)
#define INA219_MODE_SANDBVOLT_CONTINUOUS   (0x0007)
// -----------------------------------------------------------------------------

/*
 * Calls the basic setup function and sets the setupSuccess variable
 */
INA219::INA219(void)
{
  //Call the default setup method
  setupSuccess = setup();
  if(setupSuccess != true)
  {
	std::cout << "[ERROR]: setup failed, try changing address" << std::endl;
  }
} 

/*
 * Calls the basic setup function for the default address
 */
bool INA219::setup(void)
{
  fd = wiringPiI2CSetup(INA219_ADDR);

  uint16_t config = INA219_BVOLTAGERANGE_32V |
             INA219_GAIN_8_320MV |
             INA219_BADCRES_12BIT |
             INA219_SADCRES_12BIT_1S_532US |
             INA219_MODE_SANDBVOLT_CONTINUOUS;
 
  return (fd >= 0) && (wiringPiI2CWriteReg16(fd, INA219_CALIBRATION, config) >= 0);
}

/*
 * Call this constructor if the user knows the address of INA219
 * @param int addr: The address of the sensor
 * @return bool: True if successful, false if not
 */
bool INA219::setup(int addr)
{
  fd = wiringPiI2CSetup(addr);
  
  uint16_t config = INA219_BVOLTAGERANGE_32V |
             INA219_GAIN_8_320MV |
             INA219_BADCRES_12BIT |
             INA219_SADCRES_12BIT_1S_532US |
             INA219_MODE_SANDBVOLT_CONTINUOUS;

  return (fd >= 0) && wiringPiI2CWriteReg16(fd, INA219_CALIBRATION, config);
}

/*
 * Configures the sensor for reading values for 32V, 1A sources
 */ 
void INA219::set_32V_1A(void){
  ina219_calValue = 10240;
  ina219_currentDivider_mA = 25;
  ina219_powerDivider_mW = 1;  

  wiringPiI2CWriteReg16(INA219_REG_CALIBRATION, ina219_calValue);

  uint16_t config = INA219_CONFIG_BVOLTAGERANGE_32V |
                    INA219_CONFIG_GAIN_8_320MV |
                    INA219_CONFIG_BADCRES_12BIT |
                    INA219_CONFIG_SADCRES_12BIT_1S_532US |
                    INA219_CONFIG_MODE_SANDBVOLT_CONTINUOUS;

  wiringPiI2CWriteReg16(INA219_REG_CONFIG, config);
}

/*
 * Configures the sensor for reading values for 32V, 2A sources
 */
void INA219::set_32V_2A(void){
  ina219_calValue = 4096;
  current_Divider_mA = 10;
  ina219_powerDivider_mW = 2;

  wiringPiI2CWriteReg16(INA219_REG_CALIBRATION, ina219_calValue);

  uint16_t config = INA219_CONFIG_BVOLTAGERANGE_32V |
                    INA219_CONFIG_GAIN_8_320MV |
                    INA219_CONFIG_BADCRES_12BIT |
                    INA219_CONFIG_SADCRES_12BIT_1S_532US |
                    INA219_CONFIG_MODE_SANDBVOLT_CONTINUOUS;

  wiringPiI2CWriteReg16(INA219_REG_CONFIG, config);
}

/*
 * Configures the sensor for reading values for 16V, 400mA sources
 */
void INA219::set_16V_400mA(void){
  ina219_calValue = 8192;
  ina219_currentDivider_mA = 20;
  ina219_powerDivider_mW = 1;

  wiringPiI2CWriteReg16(INA219_REG_CALIBRATION, ina219_calValue);

  uint16_t config = INA219_CONFIG_BVOLTAGERANGE_16V |
                    INA219_CONFIG_GAIN_1_40MV |
                    INA219_CONFIG_BADCRES_12BIT |
                    INA219_CONFIG_SADCRES_12BIT_1S_532US |
                    INA219_CONFIG_MODE_SANDBVOLT_CONTINUOUS;

  wiringPiI2CWriteReg16(INA219_REG_CONFIG, config);
}

/*
 * Read the current across V- and V+
 * @return float: The current
 */
float INA219::getCurrent_mA(void){
  // Call to prevent resetting errors
  wiringPiI2CWrite(INA219_CALIBRATION, ina219_calValue);

  return (float)wiringPiI2CReadReg16(fd, INA219_CURRENT)/10; //Reads the voltage from the current register
}

/*
 * Read the current in milliAmps and then convert to Amps
 * @return float: The current
 */
float INA219::getCurrent_A(void){
  return getCurrent_mA();
}
 
 /*
  * Read the voltage from V- to V+
  * @return float: The voltage in milliVolts
  */
float INA219::getShuntVoltage_mV(void){
  return (uint16_t)wiringPiI2CReadReg16(fd, INA219_SHUNTVOLTAGE)* 0.01;
}

/*
 * The shunt voltage in Volts
 * @return float: The in Volts
 */
float INA219::getShuntVoltage_V(void){
  return getShuntVoltage_mA() * 0.001;
}

/*
 * The Voltage in milliVolts
 * @return float: The voltage
 */
float INA219::getBusVoltage_mV(void){
  return (uint16_t)wiringPiI2CReadReg16(fd, INA219_BUSVOLTAGE);
}

/*
 * The voltage in volts
 * @return float: The voltage 
 */
float INA219::getBusVoltage_V(void){
  return getBusVoltage_mA * 0.001;  
}

/*
 * Print the current and voltage information and return a string.
 */
std::string INA219::prints(void)
{
  std::string info = "Current: " + std::to_string(getCurrent()) + ", Voltage: " + std::to_string(getVoltage()) + "\n";
  return info;
}
