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
#define ERROR "[\e[1;31mERROR\u001b[0m]: "
#define SUCCESS "[\e[1;32mSUCCESS\u001b[0m]: "
#define WARNING "[\e[1;33mwarning\u001b[0m]: "
#define INFO "[\e[1;33minfo\u001b[0m]: "

#define RESET "\u001b[0m]"
#define RED "[\e[1;31m"
#define GREEN "\e[1;32m"
#define YELLOW "\e[1;33m"
#define ORANGE "\e[1;33m"
//------------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////

class MSG_Printer{
public:
    void info_msg(std::string message);
    void info_msg(bool print, std::string message);
    void info_msg(bool print, int lineNum, std::string message);

    void success_msg(std::string message);
    void success_msg(bool print, std::string message);
    void success_msg(bool print, int lineNum, std::string message);

    void warning_msg(std::string message);
    void warning_msg(bool print, std::string message);
    void warning_msg(bool print, int lineNum, std::string message);

    void error_msg(std::string message);
    void error_msg(bool print, std::string message);
    void error_msg(bool print, int lineNum, std::string message);

    void msg(std::string message);
    void msg(std::string message, std::string color);
};

#endif /* DEBUG_MESSAGEPRINTER_H */

