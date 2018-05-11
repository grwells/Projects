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

    std::string msg = "HC-SR04 Sensor Values... \n     primary HC-SR04: " + std::to_string(primaryLevel) + "\n     secondary HC-SR04 reads: " +
            std::to_string(secondaryLevel) + "\n    failsafe HC-SR04 reads: " + std::to_string(failsafeLevel);
    
    print.info_msg(debug, msg);
    
    int linesCollected = 0;
    
    while(!limitLines && (numLines > linesCollected)){
        collectData();
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
    //Read DS18B20
    temperature = getWaterTemp();

    //Read HC-SR04's
    primaryLevel = primary.distance(IMPERIAL);
    secondaryLevel = secondary.distance(IMPERIAL);
    failsafeLevel = failsafe.distance(IMPERIAL);

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
void Aquaman::sendData(void) {
    //TODO: write everything up and implement it...
    print.error_msg(true, "UNIMPLEMENTED");
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
 * Pumps some number of gallons into the tank
 * @param gallons The number of gallons to be pumped into the tank
 */
void Aquaman::pumpGallons(int gallons){
    print.info_msg(debug || verbose, "Running pump...");
    pump.turnOn();
    
    // TODO: run until gallons are pumped or water level meets requirement
    
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
    
    // TODO: run until gallons are released or water level meets requirement
    
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
    
    //TODO: pump until tank is full
    
    print.info_msg(debug || verbose, "Turning off pump...");
    pump.turnOff();
}
