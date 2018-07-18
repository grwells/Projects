#ifndef COMMSYS_H
#define COMMSYS_H

#include <wiringPi.h>
#include <wiringSerial.h>
#include "FONA/FONA.h"

#include "../Debug_MessagePrinter/MSG_Printer.h"

const static bool RADIO = true;
const static bool FONA = false;

class CommSys{
public:
  CommSys(bool radioOrFONA); // Starts the system using either FONA or Radio Control
  CommSys(void); // Starts the system but defers choosing communication method until later

  void selectCommSys(bool radioOrFONA); // Chooses the communication system to use

  bool sendMessage(std::string message); // Sends a message to no specific user
  bool getMessage(void); // Listens for a message
};

#endif /*COMMSYS_H*/
