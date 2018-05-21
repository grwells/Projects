#ifndef COMMSYS_H
#define COMMSYS_H

#include <wiringPi.h>
#include <wiringSerial.h>

#include "../Debug_MessagePrinter/MSG_Printer.h"

const static bool RADIO = true;
const static bool FONA = false;

class CommSys{
public:
  CommSys(bool radioOrFONA);
  
private:
};

#endif /*COMMSYS_H*/