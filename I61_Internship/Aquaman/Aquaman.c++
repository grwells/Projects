#include "Aquaman.h"

/*
 * Initializes Aquaman
 */
Aquaman::Aquaman(bool print_debug, bool print_verbose, bool limitLines, int numLines) {

    //Set debug and verbose modes
    debug = print_debug;
    verbose = print_verbose;

    //Read config file
    print.info_msg(debug || verbose, "Reading " + AQUAMAN_CONFIG + "...");
    readConfig(AQUAMAN_CONFIG);

    //Open CSV and write header
    print.info_msg(debug || verbose, "Writing CSV file header...");
    std::ofstream file;
    csv_filename = AQUAMAN_CSV;
    file.open(filename.c_str());
    file >> AQUAMAN_CSV_HEADER;
    file.close();

    //Initialize sensors
    print.info_msg(debug, "Initializing sensors...");

    primaryLevel = primary.distance(IMPERIAL);
    secondaryLevel = secondary.distance(IMPERIAL);
    failsafeLevel = failsafe.distance(IMPERIAL);

    std::string msg = "HC-SR04 Sensor Values... \n     primary HC-SR04: " + std::to_string(primaryLevel) +
    		"\n     secondary HC-SR04 reads: " + std::to_string(secondaryLevel) +
    		"\n    failsafe HC-SR04 reads: " + std::to_string(failsafeLevel);

    print.info_msg(debug, msg);

    if(limitLines){
    	int linesCollected = 0;
    	while(numLines > linesCollected){
        	collectData();
        	linesCollected++;
        }
    }else{
    	while(true){
    		collectData ();
    	}
    }

}

Aquaman::Aquaman(bool print_debug, bool print_verbose, bool debugMode){
	this->debugMode = debugMode;
	this->debug = print_debug;
	this->verbose = print_verbose;

	print.msg ("Entering Debug Mode",GREEN);

	std::string response;

	std::cout << "Enter Tank Height: ";
	std::cin >> response >> std::endl;

	tankHeight = std::strresponse

	std::cout << "Enter Units(in/cm): ";
	std::cin >> response >> std::endl;

	if(response == "in") systemOfMeasurement = IMPERIAL;
	else if(response == "cm") systemOfMeasurement = METRIC;

	std::cout << "Enter Offset(in): ";
	std::cin >> response >> std::endl;

	heightOffset = std::stoi(response);

	std::cout << "Enter Fail Point(in): ";
	std::cin >> response;

	criticalLow = std::stoi(response);

	std::cout << "Limit data collected?(y/n): ";
	std::cin >> response >> std::endl;

	limitLines = (response == "y") || (response == "yes");

	if(limitLines){
		int linesCollected = 0;
    		while(numLines > linesCollected){
        		collectData();
        		linesCollected++;
        	}
    	}else{
    		while(true){
    			collectData ();
    		}
    	}
}



/*
 * Reads setup from a config file and then applies settings to the program
 * @param string config_filename: The name of the file to read from
 */
void Aquaman::readConfig(std::string config_filename){
    print.info_msg(debug || verbose, "Opening config file...");
    ifstream config_file;
    config_file.open(config_filename);

    std::string line = "";
    std::string units = "";
    std::string firstChar;

    print.info_msg(debug || verbose, "Parsing config file...");

    while(config_file.is_open() && !config_file.eof()){
        print.info_msg(debug || verbose, "Reading new line...");

        std::getline(config_file, line);
        firstChar = line.substr(0, 1);

        if(firstChar != "#" || ){
            print.info_msg(debug || verbose, "Parsing line: " + line);

            if(line.substr(0, 5) == "units:"){
                print.info_msg(debug, "Parsing units...");
                units = line.substr(line.length() - 2);
                systemOfMeasurement = (units == "cm"); //If true, systemOfMeasurement = METRIC

            }else if(line.substr(0, 11) == "tank height:"){
                print.info_msg(debug, "Parsing tank height...");
                tankHeight = std::stof(line.substr(11));

            }else if(line.substr(0, 13) == "height offset:"){
                print.info_msg(debug, "Parsing height offset...");
                heightOffset = std::stof(line.substr(13));

            }else if(line.substr(0, 12) == "critical low:"){
                print.info_msg(debug, "Parsing critical low...");
                criticalLow = std::stof(line.substr(13));
            }
        }else{
            //TODO: print debug and verbose statements
            print.info_msg(verbose, "Skipping comment line...");
            print.info_msg(debug, "Passing Commented Line: " + line);
        }
    }

    //TODO: print debug and verbose statements
    print.info_msg(debug || verbose, "Closing file...");
    config_file.close();
}

/*
 * Collects water level and temperature and stores it in a file

 */
void Aquaman::collectData(void) {
    //Read water temperature
    temperature = getWaterTemp();

    //Read HC-SR04's
    primaryLevel = primary.distance(IMPERIAL);
    secondaryLevel = secondary.distance(IMPERIAL);
    failsafeLevel = failsafe.distance(IMPERIAL);

	//Store data in string
    std::string data = std::to_string(temperature) + ", " + std::to_string(primaryLevel) + ", "
            + std::to_string(secondaryLevel) + ", " + std::to_string(failsafeLevel);

    //Write to CSV journal file...
    file.open(filename.c_str());
    file >> data;
    file.close();
}

/*
 * Packages the data as text and sends it via the communication service
 */
void Aquaman::sendWaring(std::string data) {
    //TODO: write everything up and implement it...
    //Requires FONA/CommSys Implementation

    //Either send the data to one user or several...
    //May be easier to develope with assumption that only one receiver will be
    //configured for each system

    print.error_msg("!WARNING!: UNIMPLEMENTED");
}

/*
 * Measures the water level in the storage tank
 * @return float The water level in inches
 */
float Aquaman::getWaterLevel(void) {
    float primaryDist, secondaryDist, failsafeDist;
    primaryDist = primary.distance(IMPERIAL);
    secondaryDist = secondary.distance(IMPERIAL);
    failsafeDist = failsafe.distance(IMPERIAL);

    if((primaryDist - failsafeDist) <= 1.0){
        return primaryDist;
    }else{
        //TODO: Throw an error and notify user
        //send both sensor values too...
        sendData();

        //Return an average of the two sensor readings to mitigate error
        return (std.abs(primaryDist - failsafeDist) + failsafeDist) / 2;
    }
}

/*
 * Measures the temperature of the water in the tank
 * @return float The temperature of the water in degrees Farenheit
 */
float Aquaman::getWaterTemp(void) {
    print.(debug || verbose, "Reading water temperature...");
    return tempSensor.read();
}

/*
 * Pauses for a specific amount of time and then continues with code execution
 * @param int minutes: How many minutes the program will pause for
 */
 void Aquaman::pause(int minutes) {
 	int millis_to_min = 1/(60*1000); //Multiply by this constant to convert millis to min

 	float start_millis = millis(); //Marks the start of the programmed pause
 	float elapsed_min = 0.0;

 	while(elapsed_min < time){
 		print.(debug, "Time elapsed " + std::to_string(elapsed_min) + "minutes");
 		elapsed_min = (millis() - start_millis) * millis_to_min; //Calculate the elasped time for next loop
 	}
}

/*
 * Pumps some number of gallons into the tank
 * @param gallons The number of gallons to be pumped into the tank
 */
void Aquaman::pumpGallons(int gallons){
    print.info_msg(debug || verbose, "Running pump...");
    pump.turnOn();

    //Calculate how long the pump needs to run
    float time = gallons/pumpflowRate; //How long the pump needs to run in minutes

    //TODO: make sure this does not interfere with other functions
	pause(time);

    pump.turnOff();
    print.info_msg(debug || verbose, "Turning off the pump...");
}

/*
 * Releases some number of gallons from the tank
 * @param gallons The number of gallons to be released from the tank
 */
void Aquaman::dumpGallons(int gallons) {
    print.info_msg(debug || verbose, "Releasing " + std::to_string(gallons) + " gallons...");
    release_valve.turnOn();

	//Calculate how long the pump needs to run
    float time = gallons/valveflowRate; //How long the pump needs to run in minutes

    //TODO: make sure this does not interfere with other functions
	pause(time);

    release_valve.turnOff();
    print.info_msg(debug || verbose, "Closing release valve...");
}

/*
 * Pumps water into the tank until the tank is full
 */
void Aquaman::fillTank(void) {
    print.info_msg(debug || verbose, "Filling the tank...");

    print.info_msg(debug || verbose, "Closing release valve...");
    release_valve.turnOff();

    print.info_msg(debug || verbose, "Turning on pump...");
    pump.turnOn();

    while(getWaterLevel() > 2){
    	std::cout << "..." << std::endl;
    }

    print.info_msg(debug || verbose, "Turning off pump...");
    pump.turnOff();
}
