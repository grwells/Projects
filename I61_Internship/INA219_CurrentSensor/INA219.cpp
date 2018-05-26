#include <errno.h>
#include <stdint.h>
#include "INA219.h"

/*=========================================================================
    I2C ADDRESS/BITS
    -----------------------------------------------------------------------*/
    #define INA219_ADDRESS                         (0x40)    // 1000000 (A0+A1=GND)
    #define INA219_READ                            (0x01)
/*=========================================================================*/

/*=========================================================================
    CONFIG REGISTER (R/W)
    -----------------------------------------------------------------------*/
    #define INA219_REG_CONFIG                      (0x00)
    /*---------------------------------------------------------------------*/
    #define INA219_CONFIG_RESET                    (0x8000)  // Reset Bit
  
    #define INA219_CONFIG_BVOLTAGERANGE_MASK       (0x2000)  // Bus Voltage Range Mask
    #define INA219_CONFIG_BVOLTAGERANGE_16V        (0x0000)  // 0-16V Range
    #define INA219_CONFIG_BVOLTAGERANGE_32V        (0x2000)  // 0-32V Range
  
    #define INA219_CONFIG_GAIN_MASK                (0x1800)  // Gain Mask
    #define INA219_CONFIG_GAIN_1_40MV              (0x0000)  // Gain 1, 40mV Range
    #define INA219_CONFIG_GAIN_2_80MV              (0x0800)  // Gain 2, 80mV Range
    #define INA219_CONFIG_GAIN_4_160MV             (0x1000)  // Gain 4, 160mV Range
    #define INA219_CONFIG_GAIN_8_320MV             (0x1800)  // Gain 8, 320mV Range
  
    #define INA219_CONFIG_BADCRES_MASK             (0x0780)  // Bus ADC Resolution Mask
    #define INA219_CONFIG_BADCRES_9BIT             (0x0080)  // 9-bit bus res = 0..511
    #define INA219_CONFIG_BADCRES_10BIT            (0x0100)  // 10-bit bus res = 0..1023
    #define INA219_CONFIG_BADCRES_11BIT            (0x0200)  // 11-bit bus res = 0..2047
    #define INA219_CONFIG_BADCRES_12BIT            (0x0400)  // 12-bit bus res = 0..4097
    
    #define INA219_CONFIG_SADCRES_MASK             (0x0078)  // Shunt ADC Resolution and Averaging Mask
    #define INA219_CONFIG_SADCRES_9BIT_1S_84US     (0x0000)  // 1 x 9-bit shunt sample
    #define INA219_CONFIG_SADCRES_10BIT_1S_148US   (0x0008)  // 1 x 10-bit shunt sample
    #define INA219_CONFIG_SADCRES_11BIT_1S_276US   (0x0010)  // 1 x 11-bit shunt sample
    #define INA219_CONFIG_SADCRES_12BIT_1S_532US   (0x0018)  // 1 x 12-bit shunt sample
    #define INA219_CONFIG_SADCRES_12BIT_2S_1060US  (0x0048)  // 2 x 12-bit shunt samples averaged together
    #define INA219_CONFIG_SADCRES_12BIT_4S_2130US  (0x0050)  // 4 x 12-bit shunt samples averaged together
    #define INA219_CONFIG_SADCRES_12BIT_8S_4260US  (0x0058)  // 8 x 12-bit shunt samples averaged together
    #define INA219_CONFIG_SADCRES_12BIT_16S_8510US (0x0060)  // 16 x 12-bit shunt samples averaged together
    #define INA219_CONFIG_SADCRES_12BIT_32S_17MS   (0x0068)  // 32 x 12-bit shunt samples averaged together
    #define INA219_CONFIG_SADCRES_12BIT_64S_34MS   (0x0070)  // 64 x 12-bit shunt samples averaged together
    #define INA219_CONFIG_SADCRES_12BIT_128S_69MS  (0x0078)  // 128 x 12-bit shunt samples averaged together
  
    #define INA219_CONFIG_MODE_MASK                (0x0007)  // Operating Mode Mask
    #define INA219_CONFIG_MODE_POWERDOWN           (0x0000)
    #define INA219_CONFIG_MODE_SVOLT_TRIGGERED     (0x0001)
    #define INA219_CONFIG_MODE_BVOLT_TRIGGERED     (0x0002)
    #define INA219_CONFIG_MODE_SANDBVOLT_TRIGGERED (0x0003)
    #define INA219_CONFIG_MODE_ADCOFF              (0x0004)
    #define INA219_CONFIG_MODE_SVOLT_CONTINUOUS    (0x0005)
    #define INA219_CONFIG_MODE_BVOLT_CONTINUOUS    (0x0006)
    #define INA219_CONFIG_MODE_SANDBVOLT_CONTINUOUS (0x0007)  
/*=========================================================================*/

/*=========================================================================
    SHUNT VOLTAGE REGISTER (R)
    -----------------------------------------------------------------------*/
    #define INA219_REG_SHUNTVOLTAGE                (0x01)
/*=========================================================================*/

/*=========================================================================
    BUS VOLTAGE REGISTER (R)
    -----------------------------------------------------------------------*/
    #define INA219_REG_BUSVOLTAGE                  (0x02)
/*=========================================================================*/

/*=========================================================================
    POWER REGISTER (R)
    -----------------------------------------------------------------------*/
    #define INA219_REG_POWER                       (0x03)
/*=========================================================================*/

/*=========================================================================
    CURRENT REGISTER (R)
    -----------------------------------------------------------------------*/
    #define INA219_REG_CURRENT                     (0x04)
/*=========================================================================*/

/*=========================================================================
    CALIBRATION REGISTER (R/W)
    -----------------------------------------------------------------------*/
    #define INA219_REG_CALIBRATION                 (0x05)
/*=========================================================================*/

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
  fd = wiringPiI2CSetup(INA219_ADDRESS);

  uint16_t config = INA219_BVOLTAGERANGE_32V |
             INA219_GAIN_8_320MV |
             INA219_BADCRES_12BIT |
             INA219_SADCRES_12BIT_1S_532US |
             INA219_MODE_SANDBVOLT_CONTINUOUS;
 
  return (fd >= 0) && (wiringPiI2CWriteReg16(fd, INA219_REG_CALIBRATION, config) >= 0);
}

/*
 * Call this constructor if the user knows the address of INA219
 * @param int addr: The address of the sensor
 * @return bool: True if successful, false if not
 */
bool INA219::setup(int addr)
{
  fd = wiringPiI2CSetup(addr);
  
  uint16_t config = INA219_CONFIG_BVOLTAGERANGE_32V |
                    INA219_CONFIG_GAIN_8_320MV |
                    INA219_CONFIG_BADCRES_12BIT |
                    INA219_CONFIG_SADCRES_12BIT_1S_532US |
                    INA219_CONFIG_MODE_SANDBVOLT_CONTINUOUS;

  return (fd >= 0) && wiringPiI2CWriteReg16(fd, INA219_REG_CALIBRATION, config);
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

  wiringPiI2CWriteReg16(fd, INA219_REG_CALIBRATION, ina219_calValue);

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

  wiringPiI2CWriteReg16(fd, INA219_REG_CALIBRATION, ina219_calValue);

  uint16_t config = INA219_CONFIG_BVOLTAGERANGE_16V |
                    INA219_CONFIG_GAIN_1_40MV |
                    INA219_CONFIG_BADCRES_12BIT |
                    INA219_CONFIG_SADCRES_12BIT_1S_532US |
                    INA219_CONFIG_MODE_SANDBVOLT_CONTINUOUS;

  wiringPiI2CWriteReg16(fd, INA219_REG_CONFIG, config);
}

/*
 * Read the current across V- and V+
 * @return float: The current
 */
float INA219::getCurrent_mA(void){
  // Call to prevent resetting errors
  wiringPiI2CWrite(INA219_REG_CALIBRATION, ina219_calValue);

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
  return getBusVoltage_mA() * 0.001;  
}

/*
 * Print the current and voltage information and return a string.
 */
std::string INA219::prints(void)
{
  std::string info = "Current: " + std::to_string(getCurrent_mA()) + ", Voltage: " + std::to_string(getShuntVoltage_V()) + "\n";
  return info;
}
