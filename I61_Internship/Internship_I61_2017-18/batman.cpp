/*
	This class will monitor the condition of a connected battery.
*/

#include <fstream>
#include <string>

#define BATTERY_PROFILE "/home/pi/Cpp_Texts/Internship_I61_2017-18"

// ------------------------------------------------------------------------------------
/* 
	This will hold the data for the battery, such as when it is considered charged, depleted,
and even how efficient the battery is.
*/
//-------------------------------------------------------------------------------------
struct BatteryProfile
{
	// Static Battery Characteristics ---------------------------------------------
	int minCharge; // Lowest the charge of the battery can go to before requiring recharging
	int maxCharge; // The charge that represents 100% charge for the battery
	float efficiency; // Adjustment factor for the rate of discharge when idling
	
	// Charge Variables Since System Started --------------------------------------
	int initial_State; // the charge of the battery at the beginning of the day
	int current_State; // The current charge of the battery
	int final_State; // The charge of the battery at the end of the cycle
	
	// Time Flow Variables --------------------------------------------------------
	int delta_time; // Amount of time since the last measurement
	int total_time; // How long the battery manager has been running
};


// -------------------------------------------------------------------------------------
/*
	This class will perform all the necessary operations to monitor the battery, reading
from the sensors, calculating life expectancy, time required to charge and configuring the 
current battery's profile.
*/
// -------------------------------------------------------------------------------------
class Batman
{
	BatteryProfile album; // The data for the battery	

	public:
		Batman(); // initializes battery management system 
		float getCharge(float currentIn, float currentOut); // Calculates the amount of charge in the battery
		float lifeExpectancy(); // Calculates how many days the battery is expected to last on the current usage profile
		float timeToCharge(); // Returns how many days to full charge
		float percentageCharge(); // Percentage of full charge
		bool isHealthy(); // Returns true if the battery is above minCharge

		void warningMessage(); // Alerts user when battery falls below min charge
		void profile(); // Run a test cycle to determine the characterization of the battery
		void loadProfile(string profile); // Load the profile of the battery: max charge, last known charge level, stores in a BatteryProfile 
		void configBoundaries(int minCharge, int initialState); // Battery characteristics can be input if known
		
		
};

Batman::Batman()
{
	loadProfile();
	final_State = 0;	
}

float Batman::getCharge(float currentIn, float currentOut)
{
	rate_of_Discharge = (initial_State - current_State)/total_time; // This should use the total delta time of the program
	current_State = current_State - (rate_of_Discharge * delta_time);
	
	// The amps in the battery
	return current_State;
}

float Batman::lifeExpectancy()
{       
        // Should return how long the battery is expected to last from the current state
	float life = current_State / rate_of_Discharge;
	
	// Should return hours left of life
	return life;
}

bool Batman::isHealthy()
{
	return initial_State >= minCharge;
}

float Batman::timeToCharge()
{
	// DO STUFF
	return 1.0;
}

float Batman::percentageCharge()
{
	//DO STUFF
	return 1.0;
}

void Batman::warningMessage()
{
	std::cout << "WARNING: system failing" << std::endl;
}

void Batman::loadProfile(string filename)
{
	// Open the file and read the profile
	ifstream profile (filename);
	string var[10]; // Will contain 8 variables when full
	int i = 0;
	
	if(profile.is_open())
	{
		string line;
		while(getline (profile, line))
		{
			var[i] = line
			i++;	
		}		
	}	
}

void Batman::profile()
{
	// DO STUFF
}
void Batman::configBoundaries(int minCharge, int initialState)
{
	//DO STUFF
}
