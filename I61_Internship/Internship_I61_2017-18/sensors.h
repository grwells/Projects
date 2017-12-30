class Sensors
{
	public:
		Sensors(); // Initialize sensors on specified pins, print error message if sensor is not present.
		storeInStruct(struct container); // Gets data from each sensor and stores it in a struct.
		float getTemp();
		float getPressure();
		float getHumidity();
};

/*Stores the latest data collected from the sensors*/
struct Data
{
	/*
		environmentData[0] = temperature
		environmentData[1] = pressure
		environmentData[2] = humidity	
	*/
	float environmentData [3];	
};
