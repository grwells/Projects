#include "Aquaman.h"

/*
 * Initializes Aquaman
 */
Aquaman::Aquaman(bool print_debug, bool print_verbose) {
    
    //Setup wiringPi and set pin modes
    wiringPiSetup();
    
    //Set debug and verbose modes
    debug = print_debug;
    verbose = print_verbose;

    //Open CSV and write header
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
}

/*
 * Collects water level and temperature and stores it in a file
 */
void Aquaman::collectData(void) {
    //Read DS18B20
    temperature = tempSensor.read();

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
    // TODO: send the data via radio or SMS to user
}

/*
 * Measures the water level in the storage tank
 * @return float The water level in inches
 */
float Aquaman::getWaterLevel(void) {
    // TODO: add checking and failsafe
    return primary.distance(IMPERIAL);
}

/*
 * Measures the temperature of the water in the tank
 * @return float The temperature of the water in degrees Farenheit
 */
float Aquaman::getWaterTemp(void) {
    return tempSensor.read();
}

/*
 * Pumps some number of gallons into the tank
 * @param gallons The number of gallons to be pumped into the tank
 */
void Aquaman::pumpGallons(int gallons){
    pump.turnOn();
    
    // TODO: run until gallons are pumped or water level meets requirement
    
    pump.turnOff();
}

/*
 * Releases some number of gallons from the tank
 * @param gallons The number of gallons to be released from the tank
 */
void Aquaman::dumpGallons(int gallons) {
    release_valve.turnOn();
    
    // TODO: run until gallons are released or water level meets requirement
    
    release_valve.turnOff();
}

/*
 * Pumps water into the tank until the tank is full
 */
void Aquaman::fillTank(void) {
    release_valve.turnOff();
    pump.turnOn();
    
    // TODO: pump until tank is full...
    
    pump.turnOff();
}
