#include <errno.h>
#include <stdint.h>
#include "INA219.h"

/*
 * Calls the basic setup function, assuming i2c device @ 0x40
 */
INA219::INA219(void)
{
  fd = 0;
  ina219_currentDivider_mA = 0;
  ina219_powerDivider_mW = 0;
}

/*
 * Prepares the sensor to read from the widest possible range of values
 * @param bool: True if the setup function was successful
 */
bool INA219::setup(void)
{
  std::cout << "Calling default setup" << std::endl;

  fd = wiringPiI2CSetup(INA219_ADDRESS);

  std::cout << "fd = " << fd << std::endl;

  if(fd < 0) std::cout <<"ERRROR!!!!: " << std::strerror(errno) << std::endl;

  set_32V_2A(); //Set the sensor to read widest possible range of values

  return (fd >= 0);
}

/*
 * Call this constructor if the user knows the address of INA219
 * @param int addr: The address of the sensor
 * @return bool: True if successful, false if not
 */
bool INA219::setup(int addr)
{
  std::cout << "Calling setup" << std::endl;

  fd = wiringPiI2CSetup(addr);

  std::cout << "fd = " << fd << std::endl;

  if(fd < 0) std::cout <<"ERRROR!!!!: " << std::strerror(errno) << std::endl;

  set_32V_2A(); //Set the sensor to read from as many values as possible

  return (fd >= 0);
}

/*
 * Configures the sensor for reading values for 32V, 1A sources
 */
void INA219::set_32V_1A(void){
  ina219_calValue = 10240;
  ina219_currentDivider_mA = 25;
  ina219_powerDivider_mW = 1;

  bool failed = true;
  int fileDescriptor;

  fileDescriptor = wiringPiI2CWriteReg8(fd, INA219_REG_CALIBRATION, ina219_calValue);

  uint16_t config = INA219_CONFIG_BVOLTAGERANGE_32V |
                    INA219_CONFIG_GAIN_8_320MV |
                    INA219_CONFIG_BADCRES_12BIT |
                    INA219_CONFIG_SADCRES_12BIT_1S_532US |
                    INA219_CONFIG_MODE_SANDBVOLT_CONTINUOUS;

  int second_fileDescriptor;
  second_fileDescriptor = wiringPiI2CWriteReg8(fd, INA219_REG_CONFIG, config);
  failed = fileDescriptor < 0 && second_fileDescriptor < 0;

  if(failed){
  	std::cout <<"ERRROR!!!!: " << std::strerror(errno) << std::endl;
  	throw_configError("set_32V_1A, fd1 = " + std::to_string(fileDescriptor) + " fd2 = " + std::to_string(second_fileDescriptor));
  }

}

/*
 * Configures the sensor for reading values for 32V, 2A sources
 */
void INA219::set_32V_2A(void){
  ina219_calValue = 4096;
  ina219_currentDivider_mA = 10;
  ina219_powerDivider_mW = 2;

  bool failed = true;
  int fileDescriptor;

  fileDescriptor = wiringPiI2CWriteReg16(fd, INA219_REG_CALIBRATION, ina219_calValue);

  uint16_t config = INA219_CONFIG_BVOLTAGERANGE_32V |
                    INA219_CONFIG_GAIN_8_320MV |
                    INA219_CONFIG_BADCRES_12BIT |
                    INA219_CONFIG_SADCRES_12BIT_1S_532US |
                    INA219_CONFIG_MODE_SANDBVOLT_CONTINUOUS;

  int second_fileDescriptor;
  second_fileDescriptor = wiringPiI2CWriteReg16(fd, INA219_REG_CONFIG, config);
  failed = fileDescriptor < 0 && second_fileDescriptor < 0;

  if(failed){
  	std::cout <<"ERRROR!!!!: " << std::strerror(errno) << std::endl;
  	throw_configError("set_32V_2A, fd1 = " + std::to_string(fileDescriptor) + " fd2 = " + std::to_string(second_fileDescriptor));
  }
}

/*
 * Configures the sensor for reading values for 16V, 400mA sources
 */
void INA219::set_16V_400mA(void){
  ina219_calValue = 8192;
  ina219_currentDivider_mA = 20;
  ina219_powerDivider_mW = 1;

  bool failed = true;
  int fileDescriptor;

  fileDescriptor = wiringPiI2CWriteReg16(fd, INA219_REG_CALIBRATION, ina219_calValue);

  uint16_t config = INA219_CONFIG_BVOLTAGERANGE_16V |
                    INA219_CONFIG_GAIN_1_40MV |
                    INA219_CONFIG_BADCRES_12BIT |
                    INA219_CONFIG_SADCRES_12BIT_1S_532US |
                    INA219_CONFIG_MODE_SANDBVOLT_CONTINUOUS;

  int second_fileDescriptor = 0;
  second_fileDescriptor = wiringPiI2CWriteReg16(fd, INA219_REG_CONFIG, config);
  failed = fileDescriptor < 0 && second_fileDescriptor < 0;

  if(failed){
  	std::cout <<"ERRROR!!!!: " << std::strerror(errno) << std::endl;
   	throw_configError("set_16V_400mA, fd1 = " + std::to_string(fileDescriptor) + " fd2 = " + std::to_string(second_fileDescriptor));
   }
}

/*
 * Read the current across V- and V+
 * @return float: The current
 */
float INA219::getCurrent_mA(void){
  // Call to prevent resetting errors
  int fileDescriptor = wiringPiI2CWrite(INA219_REG_CALIBRATION, ina219_calValue);

  if(fileDescriptor < 0) std::cout << "Failed to write conifg before reading sensor...\n" << std::endl;

  return (float)wiringPiI2CReadReg16(fd, INA219_REG_CURRENT)/10; //Reads the voltage from the current register
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
  return (uint16_t)wiringPiI2CReadReg16(fd, INA219_REG_SHUNTVOLTAGE)* 0.01;
}

/*
 * The shunt voltage in Volts
 * @return float: The in Volts
 */
float INA219::getShuntVoltage_V(void){
  return getShuntVoltage_mV() * 0.001;
}

/*
 * The Voltage in milliVolts
 * @return float: The voltage
 */
float INA219::getBusVoltage_mV(void){
  return (uint16_t)wiringPiI2CReadReg16(fd, INA219_REG_BUSVOLTAGE);
}

/*
 * The voltage in volts
 * @return float: The voltage
 */
float INA219::getBusVoltage_V(void){
  return getBusVoltage_mV() * 0.001;
}

/*
 * Print the current and voltage information and return a string.
 */
std::string INA219::prints(void)
{
  std::string info = "Current: " + std::to_string(getCurrent_mA()) + ", Voltage: " + std::to_string(getShuntVoltage_V()) + "\n";
  return info;
}

/*
 * Throws an error message
 * @param std::string config_message: The config function name, points to where the error occured
 */
void INA219::throw_configError(std::string config_message){
    std::cout << "[ERROR]: in config method -> " + config_message << std::endl;
}
