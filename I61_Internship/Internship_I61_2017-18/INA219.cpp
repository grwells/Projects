#include <wiringPiI2C.h>
#include <iostream>
#include <errno.h>
#include <string.h>
#include <stdint.h>

// INA219 VARIABLES ------------------------------------------------------------
#define INA219_ADDR                        (0x40)
#define INA219_COFIG                       (0x00)
#define INA219_SHUNTVOLTAGE                (0x01)
#define INA219_BUSVOLTAGE                  (0x02)
#define INA219_POWER                       (0x03)
#define INA219_CURRENT                     (0x04)
#define INA219_CALIBRATION                 (0x05)
//------------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////
// INA219 CONFIG ---------------------------------------------------------------
#define INA219_BVOLTAGERANGE_32V           (0x2000)
#define INA219_GAIN_8_320MV                (0x1800)
#define INA219_BADCRES_12BIT               (0x0400)
#define INA219_SADCRES_12BIT_1S_532US      (0x0018)
#define INA219_MODE_SANDBVOLT_CONTINUOUS   (0x0007)
// -----------------------------------------------------------------------------

class INA219
{ 
  private:
    int fd;
    float current_mA;
    float voltage_mV;
  public:
    INA219(void);
    bool setup(void); // initializes the settings for I2C
    bool setup(int addr); // initializes the settings for I2C using user address
    float getCurrent(void);
    float getVoltage(void);
};

INA219::INA219(void)
{
  setupSuccess = setup();
}

// Call this setup if device is assumed to be connected to INA219_ADDR
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

// Call this constructor if the user knows the address of INA219
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

float INA219::getCurrent(void)
{
  // Call to prevent resetting errors
  wiringPiI2CWrite(INA219_CALIBRATION, 4096);

  currentRaw = (float)wiringPiI2CReadReg16(fd, INA219_CURRENT)/10;

  return currentRaw;
}

float INA219::getVoltage(void)
{
  uint16_t voltRaw = wiringPiI2CReadReg16(fd, INA219_SHUNTVOLTAGE);

  return voltRaw * 0.01;
}

// If main is called, the sensor can be run without master, will do 25 readings and close
int main(void)
{
    INA219 bat;
    
    if(bat.setupSuccess)
    {
      std::cout << "[OK] setup successful" << std::endl;
    }
    else
    {
      std::cout << "[ERROR]: " <<  strerror(errno) << std::endl;
    }

    bool noError = true;
    int i = 0;

    while (noError && i < 25)
    {
      noError = (bat.getCurrent() >= 0) && (bat.getVoltage() >= 0);
      std::cout << "Current: " << (float)bat.currentRaw << std::endl;
      std::cout << "Voltage: " << bat.getVoltage() << std::endl;
      i += 1;
    }
    
    if(!noError)
    { 
        std::cout << "[ERROR]: " << errno  << " " << strerror(errno) << std::endl;
    }

    std::cout << "Exiting..." << std::endl;
}

