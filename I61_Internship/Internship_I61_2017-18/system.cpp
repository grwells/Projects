#include <iostream>
#include <fstream>
#include <string>
#include <sensors.h>
#include <batman.h>
/*
	Also...
	*power mode protocols to prioritize various functions or processes
	*warning message protocols and functions
*/

#define CONFIG_FILENAME "systemconfig.txt"

private bool batman_IS_healthy = true;
private bool load_sensors = false; // Do not use sensor package with this system by default
private bool power_mode_low = true; // Run at low power by default

class System 
{
	public:
		System(); // Initializes the system, and then proceeds to monitor its behavior and run protocols
		bool initPowerSourceManagement(); // Call Batman, returns true if successful
		bool initSensors(); // Bring sensors online, returns true if successful
		bool loadConfig(std::string configFile); // Load user preferences, returns true if successful

		void run(void); // begin collecting data and performing other tasks
		
	
};

System::System()
{
	loadConfig(CONFIG_FILENAME);
	batman_IS_healthy = initPowerSourceManagement();
	if(load_sensors)
	{
		sensors_loaded = initSensors();
	}			
}

bool System::initPowerSourceManagement()
{
	// DO STUFF
	Batman batman;
	bool health = batman.isHealthy();
	std::cout <<"Batman is running[" << health << "]" << std::endl;
			
	return health;
}

bool System::initSensors()
{
	//DO STUFF
	Sensors eyes;
	return false;
}

bool System::loadConfig(std::string configFile)
{
	// Open the file and read the config data, apply the config settings, let'er rip!
	
	ifstream config (configFile);

	if(config.is_open())
	{
		string line;
		int i = 0;
		string instructions [20];
		while(getline (config, line))
		{
			instructions[i] = line;
			i++;
		}
	}

	// Set variables to values stored in array
	// DO STUFF!! 
	
	return false;
}

void System::run()
{
	while(batman_IS_healthy){
		//DO STUFF
	}
}

int main(){
	std::cout << "Initializing System..." << std::endl;
	return 0;
}
