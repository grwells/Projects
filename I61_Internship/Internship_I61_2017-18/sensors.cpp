/*
	@author: Garrett Wells for I61
	@version: 1.0 
	@date: 12/3/2017

	This class will contain the code for getting the data from each sensor.
	

*/

#include <INA219.h>
//-------------------------------------------------

struct Data
{
	/*
		feedback[0] = current (mA)
		feedback[1] = voltage (mV)
	*/
	float feedback[2];
};

class Sensors()
{
	private:
		Data feedback;
		INA219 ina219;
		int sensors_on[1] = {true};
	public:
		Sensors(); // Initialize sensors on specified pins, print error message if sensor is not present.			
}

/*
	Initialize sensors using specified pins, identify which sensors are not working.
*/
float Sensors::Sensors()
{
	// DO STUFF
	for(int i = 0; i < 4; i++)
	{
		switch(i)
		{
			case 0 && (sensors_on[i] == true):
				// start temperature
				break;

			case 1:
				//start pressure
				break;
			
			case 2:
				//start humidity
				break;
			
			case 3:
				//start current
				ina219.setup();
				break;
		}
	}
}
