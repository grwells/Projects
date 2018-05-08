#include <iostream>
#include <string>
#include "../Debug_MessagePrinter/Debug_MessagePrinter.h"

#define HELLO "Hello World"

int main(void){
	std::string hello = HELLO "!";
	std::cout << HELLO << hello <<  std::endl;
	PRINTER.info_msg(true, "Hello World");
	return 0;
}

