#include "Hygrometer.h"
#include "../Debug_MessagePrinter/MSG_Printer.h"

int main(void){
	MSG_Printer print;

	print.info_msg("Starting test...");
	print.info_msg("Initializing Hygrometer...");
	Hygrometer hillary(2);
	if(hillary.soil_isDry()){
		print.info_msg("Soil is dry, add water...");
	}else{
		print.info_msg("Soil is fine, continue on...");
	}

	print.info_msg("Finishing test...");
	return 0;
}
