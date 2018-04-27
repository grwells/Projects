/*I61 Ministries License
 * This code may only be used with the written consent of I61 Ministries and partners.
 */

/* 
 * File:   Debug_MessagePrinter.h
 * Author: deepg
 *
 * Created on April 27, 2018, 3:11 PM
 */

#ifndef DEBUG_MESSAGEPRINTER_H
#define DEBUG_MESSAGEPRINTER_H

//System Include Files----------------------------------------------------------
#include <iostream>
#include <string>
//------------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////
//Message Templates-------------------------------------------------------------
#define ERROR "[\e[1;31mERROR\u001b[0m]:"
#define SUCCESS "[\e[1;32mSUCCESS\u001b[0m]:"
#define WARNING "[\e[1;33mwarning\u001b[0m]:"
#define INFO "[\e[1;33minfo\u001b[0m]:"
//------------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////

class MSG_Prnt{
public:
    void info_msg(bool print, std::string message);
    void success_msg(bool print, std::string message);
    void warning_msg(bool print, std::string message);
    void error_msg(bool print, std::string message);
};

#endif /* DEBUG_MESSAGEPRINTER_H */

