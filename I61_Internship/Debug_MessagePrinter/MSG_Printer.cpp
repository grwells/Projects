/*I61 Ministries License
 * This code may only be used with the written consent of I61 Ministries and partners.
 */

#include "MSG_Printer.h"

/*
 * Print a simple message in the default terminal color
 * @param string message: The user's message to be printed
 */
void MSG_Printer::msg(std::string message){
    std::cout << message << std::endl;
}

/*
 * Print a fancier message in a color of the user's choice
 * @param string message: The message to be printed for the user
 * @param string color: The ASCII color for the text...
 */
void MSG_Printer::msg(std::string message, std::string color){
    std::cout << color << message << RESET << std::endl;
}

/*
 * Prints a basic informational message
 * @param bool print: If true, print the message
 * @param string message: The text that the user wants printed
 */
void MSG_Printer::info_msg(bool print, std::string message){
    if(print){std::cout << INFO << message << std::endl;}
}

/*
 * Prints a basic informational message with the line number
 * @param bool print: If true, print the message
 * @param int lineNum: The line that the error is thrown on
 * @param string message: The error message to throw
 */
void MSG_Printer::info_msg(bool print, int lineNum, std::string message){
    if(print){std::cout << INFO << "at line #" << lineNum << ": " << message << std::endl;}
}

/*
 * Prints a basic success message
 * @param bool print: If true, print the message
 * @param string message: The text that the user wants printed
 */
void MSG_Printer::success_msg(bool print, std::string message){
    if (print) {
        std::cout << SUCCESS << message << std::endl;
    }
}

/*
 * Prints a basic informational message with the line number
 * @param bool print: If true, print the message
 * @param int lineNum: The line that the error is thrown on
 * @param string message: The error message to throw
 */
void MSG_Printer::success_msg(bool print, int lineNum, std::string message){
    if(print){std::cout << SUCCESS << "at line #" << lineNum << ": " << message << std::endl;}
}

/*
 * Prints a basic warning message
 * @param bool print: If true, print the message
 * @param string message: The text that the user wants printed
 */
void MSG_Printer::warning_msg(bool print, std::string message){
    if (print) {
        std::cout << WARNING << message << std::endl;
    }
}

/*
 * Prints a basic informational message with the line number
 * @param bool print: If true, print the message
 * @param int lineNum: The line that the error is thrown on
 * @param string message: The error message to throw
 */
void MSG_Printer::warning_msg(bool print, int lineNum, std::string message){
    if(print){std::cout << WARNING << "at line #" << lineNum << ": " << message << std::endl;}
}

/*
 * Prints a basic error message
 * @param bool print: If true, print the message
 * @param string message: The text that the user wants printed
 */
void MSG_Printer::error_msg(bool print, std::string message){
    if (print) {
        std::cout << ERROR << message << std::endl;
    }
}

/*
 * Prints a basic informational message with the line number
 * @param bool print: If true, print the message
 * @param int lineNum: The line that the error is thrown on
 * @param string message: The error message to throw
 */
void MSG_Printer::error_msg(bool print, int lineNum, std::string message){
    if(print){std::cout << ERROR << "at line #" << lineNum << ": " << message << std::endl;}
}
