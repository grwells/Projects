/*
	This class will monitor the drainage of a battery based on current output and voltage. It will also monitor the charging of a battery.
*/
#include <string.h>
#include <fstream>
#include <chrono>
#include <thread>
#include "INA219.h"

using namespace std::chrono;

class BatmanT
{
	private:
                //File Variables
		std::string filename = "journal_file.csv"; //csv data collection file 
		std::ofstream file_in;
		std::string data;                          //data to be written to the file
                
                //Data Variables
		float charge;   //total charge in the battery
		float currentI; //current that is flowing into the battery 
		float voltage;  //the voltage supplied to the battery
                
                //Time Variables
		float deltaT; //time between collections
		float timeT;  //total time test has been running
                high_resolution_clock::time_point startingPoint;
                high_resolution_clock::time_point endPoint;
                
                //Program Variables and Sensors
		bool keepCollecting;
		INA219 ina219;

	public:
		BatmanT();
		void logData(std::string data);
		float getCurrent();
		float getVoltage();
		float calcCurrentCharge();
};

BatmanT::BatmanT()
{
	// OPEN FILE...
	file_in.open (filename.c_str());

        //make sure file is open
	if(file_in.is_open()){std::cout << "[SUCCESS]: file " + filename + " open" << std::endl;}
	else{std::cout << "[ERROR]: file " + filename + " closed" << std::endl;}

        //write csv header
	std::string header = "Current(mA), Voltage(mV), Total Charge(mA), Time(delta)";
	file_in << header;
	std::cout << "printed header, check file now" << std::endl;

	// START SENSOR...
	std::cout << "Calling sensor setup" << std::endl;
	if(ina219.setup()){keepCollecting = true;}
	else{std::cout << "[ERROR]: sensor setup failed" << std::endl;}

	//LOG DATA...
	while(keepCollecting)
	{
                //record start time...
                startingPoint = high_resolution_clock::now();
            
		//wait 10sec...
		std::this_thread::sleep_for(seconds(5));

		//collect data...
		logData(data);
		
		//Program stop...take out some time soon	
        	keepCollecting = false;
				
	}
	std::cout << "[WARNING]: closing file" << std::endl;
	file_in.close();
	
}

void BatmanT::logData(std::string data)
{
	//WRITE DATA TO FILE FROM STRING
	if(file_in.is_open())
	{
		//get data 
		currentI = getCurrent();
		voltage = getVoltage();	
                
                //calculate elapsed time
                duration<double> timeLapse = duration_cast<duration<double>>(high_resolution_clock::now() - startingPoint); //record first time point
                deltaT = timeLapse.count();
                timeT += deltaT;
                
                //calculate accumulated charge
                charge = calcCurrentCharge();
                
		std::cout << "[WARNING]: writing data" << std::endl;
		file_in << "\n" + std::to_string(currentI) + "," + std::to_string(voltage) + "," + std::to_string(charge) + "," + std::to_string(deltaT); 
		std::cout << "[SUCCESS]: data written to file" << std::endl;
                
	}else 
	{	
                //print error message
		std::cout << "[ERROR] file " + filename + " not open" << std::endl;
		file_in.open(filename.c_str(), std::ofstream::out | std::ofstream::app);
                
                //try to open file again
		std::cout << "trying to open file again..." << std::endl;
		logData(data); //goes to loop if file can not be opened
	}
}

float BatmanT::getCurrent()
{	
	//READ CURRENT FROM SENSOR
	return ina219.getCurrent();
}

float BatmanT::getVoltage()
{
	//READ VOLTAGE FROM SENSOR
	return ina219.getVoltage();
}

float BatmanT::calcCurrentCharge()
{
	//CALCULATE THE AMOUNT THE CHARGE OF THE BATTERY HAS CHANGED OVER DELTAT
	return charge + (deltaT * currentI); 
}

int main()
{
	// CALL THE BATMAN!!!
	BatmanT bat;
	
	return 1;
}

