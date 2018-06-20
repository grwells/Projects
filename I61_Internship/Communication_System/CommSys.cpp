#include <CommSys.h>

CommSys::CommSys(bool radioOrFONA){
	//TODO: Configure for radio or FONA modules
	if(RADIO){
		//TODO: set up the radio interface
	}else if(FONA){
		//TODO: set up the FONA interface
		FONA gsm;
	}

}

CommSysCommSys(void){
	//TODO: write default constructor
}

void CommSys::selectCommSys(bool radioOrFONA){}

bool CommSys::sendMessage(std::string message){
	//TODO: write send message for CommSys
	return false;
}

bool CommSys::getMessage(void){
	//TODO: write the get message for CommSys
	return false;
} 