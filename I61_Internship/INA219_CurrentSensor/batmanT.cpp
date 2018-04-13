/*
 * This class will monitor the drainage of a battery based on current output and voltage. It will also monitor the charging of a battery.
 * @author: Garrett Wells
 * @version: 2.0
*/

//Environment----------------------
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>
//---------------------------------

//Open Source----------------------
#include "../Tolako5V_CurrentSensor/Tolako5V.h"
#include "INA219.h"
//---------------------------------

#define CSV "journal_file.csv"
#define CSV_HEADER "Voltage(mV), Current In(mA), Current Out(mA), Total Charge(mA), Time Delta(seconds)"
#define TOLAKO_PIN 5

//Command Line Triggers------------
#define DEBUG_ON true
#define VERBOSE_ON true
#define LINELIMIT_ON true

//Debug Mode Messages--------------
#define FILE_OPEN "[info]: file open..."
#define FILE_CLOSED "[info]: file closed..."

#define ERROR "[\e[1;31mERROR\e[0;30m]:"
#define SUCCESS "[\e[1;32mSUCCESS\e[0;30m]:"
#define WARNING "[\e[1;33mwarning\e[0;30m]:"
#define INFO "[\e[1;33minfo\e[0;30m]:"

using namespace std::chrono;

class BatmanT
{
private:
	//File Variables
	std::string filename;
	std::ofstream file_in;
	std::string data;                          //data to be written to the file

	//Data Variables
	float charge;    //total charge in the battery
	float currentIn; //current that is flowing into the battery
	float currentOut;//current flowing out of the battery
	float voltage;  //the voltage supplied to the battery

	//Time Variables
	float deltaT; //time between collections
	float timeT;  //total time test has been running
	high_resolution_clock::time_point startingPoint;
	high_resolution_clock::time_point endPoint;

	//Program Variables and Sensors
	bool keepCollecting;
	INA219 ina219;
	Tolako5V tolako;     //Initialize the Tolako sensor on the default pin

public:
	//Functions
	BatmanT(bool debugMode, bool verboseMode, bool limitLineMode, int numberOfLines);
	void logData(std::string data);
	float getCurrent();
	float getVoltage();
	float calcCurrentCharge();

	//Variables
	bool debug;
	bool verbose;
	bool limitLines;
	int numLines = 1;
};

BatmanT::BatmanT(bool debugMode, bool verboseMode, bool limitLineMode, int numberOfLines)
{
	//Initialize command line based arguments
	debug = debugMode;
	verbose = verboseMode;
	limitLines = limitLineMode;
	if(limitLines){numLines = numberOfLines;}

	filename = CSV;

	// OPEN FILE...
	file_in.open(filename.c_str());

	//make sure file is open
	if(debug){
		if (file_in.is_open()) {
			std::cout << SUCCESS << " " + filename + " is open" << std::endl;
		}else{
			std::cout << ERROR << " " + filename + " is still closed" << std::endl;
			std::cout << "Proceed?(y/n): ";
			std::string proceed;
			std::cin >> proceed;
			std::transform(proceed.begin(), proceed.end(), proceed.begin(), ::tolower);

			if(proceed.compare("y") || proceed.compare("yes")){
				std::cout << INFO << " Continuing without saving..." << std::endl;
			}else {return;}
	 }
	}

	//WRITE CSV HEADER...
	std::string header = CSV_HEADER;
	file_in << header;

	//print debug
	if(debug && verbose){
		std::cout << INFO << " printed header, check file now" << std::endl;
		std::cout << "Header: " << CSV << std::endl;
	}else if(debug){
		std::cout << INFO << " printed header..." << std::endl;
	}


	// START SENSORS...
	if(verbose){
		std::cout << INFO << " calling sensor setup..." << std::endl;
		std::cout << INFO << " setting Tolako5V sensor to read from pin" << std::endl;
	}

	//start Tolako5V
	tolako.setPin(TOLAKO_PIN);
	// start INA219
	if (ina219.setup()) { keepCollecting = true; }
	else if(debug){ std::cout << ERROR << " INA219 sensor setup failed, check I2C address" << std::endl; }

	int collectedLines = 0;
	//LOG DATA...
	while (keepCollecting)
	{
		//Record start time...
		startingPoint = high_resolution_clock::now();
		if(verbose || debug){
			duration<double> timeLapse = duration_cast<duration<double>>(startingPoint);
			std::cout << INFO << " starting point for time measurement: " << timeLapse.count() << std::endl;
		}

		//Wait 10sec...
		std::this_thread::sleep_for(seconds(5));
		if(verbose || debug){std::cout << INFO << " slept for 5 seconds... resuming data collection" << std::endl;}

		//Save data...
		if(verbose || debug){
			std::cout << INFO << " saving data..." << std::endl;
			logData(data);
			collectedLines++;
		}

		//Program stop...
		if(collectedLines == numLines){
			keepCollecting = false;

			//print debug
			if(debug || verbose){
				std::cout << INFO << " stopping data collection" << std::endl;
				std::cout << "Line # Limit: " + numLines << std::endl;
				std::cout << "# Collected Lines: " + collectedLines << std::endl;
			}else if(debug){
				std::cout << INFO << " stopping data collection" << std::endl;
			}
		}

	}

	if(debug){
		std::cout << WARNING << " closing file " << CSV << std::endl;
	}
	file_in.close();

}

void BatmanT::logData(std::string data)
{
	//WRITE DATA TO FILE FROM STRING
	if (file_in.is_open())
	{
		//Get data------------------------------------------------------------------------------------
		currentIn = getCurrent();
		if(verbose){std::cout << INFO << " Current In: " << currentIn << std::endl;}
		else if(debug){std::cout << INFO << " measured current input..." << std::endl;}

		voltage = getVoltage();
		if(verbose){std::cout << INFO << " Voltage: " << voltage << std::endl;}
		else if(debug){std::cout << INFO << " measured voltage..." << std::endl;}


		//Calculate elapsed time------------------------------------------------------------------------
		duration<double> timeLapse = duration_cast<duration<double>>(high_resolution_clock::now() - startingPoint); //record first time point
		deltaT = timeLapse.count();
		timeT += deltaT;
		if(verbose){
			std::cout << INFO << " recorded time elapsed" << "\nTime Elapsed: " << deltaT << "\nTotal Time: " << timeT << std::endl;
		}else if(debug){std::cout << INFO << " recorded time elapsed..." << std::endl;}

		//Calculate accumulated charge-------------------------------------------------------------------
		charge = calcCurrentCharge();

		//Build data string------------------------------------------------------------------------------
		//contains currentIn, currentOut, voltage, charge accumulated, and time delta since last collection point
		std::string data = "\n" + std::to_string(voltage) + "," + std::to_string(currentIn) + ","  + std::to_string(currentOut) + "," +
												std::to_string(charge) + "," + std::to_string(deltaT);
		file_in << data;

		//Print debug------------------------------------------------------------------------------------
		if(verbose){
			std::cout << INFO << " Current Net Charge: " << charge << std::endl;
			std::cout << WARNING << " Writing data: " << data << std::endl;
			std::cout << SUCCESS << " data written to file..." << std::endl;

		}else if(debug){
			std::cout << INFO << " Calculated net charge..." << std::endl;
			std::cout << WARNING << " writing data..." << std::endl;
			std::cout << SUCCESS << " data written to file" << std::endl;

		}


	}else{
		//print error message
		if(verbose){std::cout << ERROR << " file " + filename + " not open" << std::endl;}
		else if(debug){std::cout << ERROR << "file not open..." << std::endl;}

		file_in.open(filename.c_str(), std::ofstream::out | std::ofstream::app);

		//try to open file again
		if(verbose){
			std::cout << INFO << " trying to open file again..." << std::endl;
			std::cout << INFO << " trying again..." << std::endl;

		}else if(debug){std::cout << INFO << " re-opening file..." << std::endl;}

		logData(data); //goes to loop if file can not be opened
	}
}

float BatmanT::getCurrent()
{
	//READ CURRENT FROM SENSOR
	if(debug || verbose){
		std::cout << INFO << " reading current..." << std::endl;
	}
	return ina219.getCurrent() + tolako.readCurrent();
}

float BatmanT::getVoltage()
{
	//READ VOLTAGE FROM SENSOR
	if(debug || verbose){
		std::cout << INFO << " reading voltage..." << std::endl;
	}
	return ina219.getVoltage();
}

float BatmanT::calcCurrentCharge()
{
	//CALCULATE THE AMOUNT THE CHARGE OF THE BATTERY HAS CHANGED OVER DELTAT
	if(debug || verbose){
		std::cout << INFO << " calculating charge..." << std::endl;
	}
	return charge + (deltaT * currentIn);
}

/*
 * Run battery manager.
 * @param int argc - The number of command line arguments passed in by the user, at least 1
 * @param char argv[] - The arguments passed in by the user, an array of strings where the
 			first string is the argument used to call the Program
 * @return int - 1 if successful, 0 if not
*/
int main(int argc, char *argv[] /*bool debugMode = false, bool verboseMode = false, bool lineLimit = false, int num = 1*/)
{
	//Verify proper number of arguments were passed...
	if(argc > 7){
		std::cout << "Usage: " << argv[0] << " <ARG>" << std::endl;
		return 0;
	}

	bool debug = false;
	bool verbose = false;
	bool limitLines = false;
	int numLines = 1;

	//Process command line arguments
	for(int i = 0; i < argc; i++){
		std::string arg = argv[i];
		if(arg == "-v"){
			verbose = VERBOSE_ON;
		}else if(arg == "-d"){
			debug = DEBUG_ON;
		}else if(arg == "-l"){
			limitLines = LINELIMIT_ON;
			numLines = argv[i+1];
		}else if(arg == "-h" || arg == "--help"){
			/*TODO
			* write help commands
			*/
		}
	}

	//Call the battery manager
	BatmanT bat(debug, verbose, limitLines, numLines);

	//Exit program
	return 1;
}
