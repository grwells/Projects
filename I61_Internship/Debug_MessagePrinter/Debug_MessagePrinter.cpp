/*I61 Ministries License
 * This code may only be used with the written consent of I61 Ministries and partners.
 */

#include "Debug_MessagePrinter.h"

/*
 * Prints a basic informational message
 * @param bool print: If true, print the message
 * @param string message: The text that the user wants printed
 */
void MSG_Prnt::info_msg(bool print, std::string message){
    if(print){std::cout << INFO << message << std::endl;}
}

/*
 * Prints a basic success message
 * @param bool print: If true, print the message
 * @param string message: The text that the user wants printed
 */
void MSG_Prnt::success_msg(bool print, std::string message){
    if (print) {
        std::cout << SUCCESS << message << std::endl;
    }
}

/*
 * Prints a basic warning message
 * @param bool print: If true, print the message
 * @param string message: The text that the user wants printed
 */
void MSG_Prnt::warning_msg(bool print, std::string message){
    if (print) {
        std::cout << WARNING << message << std::endl;
    }
}

/*
 * Prints a basic error message
 * @param bool print: If true, print the message
 * @param string message: The text that the user wants printed
 */
void MSG_Prnt::error_msg(bool print, std::string message){
    if (print) {
        std::cout << ERROR << message << std::endl;
    }
}