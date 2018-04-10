#include <wiringPi.h>

class Hygrometer{
public:
  Hygrometer(int pinNum);
  bool read(void);
  float readAnalog(void);

private:
  bool soilIsDry = false;
};
