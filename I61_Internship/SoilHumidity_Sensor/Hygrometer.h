#include <wiringPi.h>

class Hygrometer{
public:
  Hygrometer(int pinNum);
  bool soil_isDry(void);
  float readAnalog(void);

private:
  float threshold; // If moisture level is below this percentage, soil is too dry
};
