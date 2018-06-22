#include "Batman.h"

int main(int argc, char[]* argv){
	bool record_data = false;
	bool print_debugMsgs = false;
	bool limit_lines = false;
	int num_lines = 0;

	for(int i = 0; i < argc; i++){
		if(argv[i] == 'd'){ 
			print_debugMsgs = true;
		}else if(argv[i] == 'r'){
			record_data = true;
		}else if(argv[i] == 'l'){
			num_lines = argv[i+1];
		}else{
			Debug_MessagePrinter p;
			p.error_msg(true, "INVALID ARGUMENT");

			string help = "\nr 		Record program data to file" + 
							"\nd 		Print debug messages to console" + 
							"\nl(#number of lines to record) 		Limit the number of lines of data collected";
			p.info_msg(true, "Possible Arguments: " + )
		}

		//TODO: Finish main
		if(record_data){Batman bat(print_debugMsgs, record_data, false);}
		else if()
	}
}