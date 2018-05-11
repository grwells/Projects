#include "DS18B20.h"

/*
 * Run the system setup commands for the sensor using the pi drivers
 */
DS18B20::DS18B20(std::string MAC_address) {
    //INIT DRIVERS
    filename = DS18B20_PATH;
    filename = filename + MAC_address + "/w1_slave";

    //prints.info_msg("Calling setup for DS18B20...");
    std::system("sudo modprobe w1-gpio");
    std::system("sudo modprobe w1-therm");
}

/*
 * Run the system setup commands for the sensor using the pi drivers
 */
DS18B20::DS18B20(void) {
    //INIT DRIVERS
    filename = DS18B20_PATH;
    filename = filename + DS18B20_MAC + "/w1_slave";

    //prints.info_msg("Calling setup for DS18B20...");
    std::system("sudo modprobe w1-gpio");
    std::system("sudo modprobe w1-therm");
}

/*
 * Run the setup for the commands, and use open source libraries
 */
DS18B20::DS18B20(int pinNumber) {
    //DO STUFF THE HARD WAY!!!
    prints.error_msg("Not done yet...");
}

/*
 * Read the sensor value from the system file
 * @return float The sensor reading in degrees C
 */
float DS18B20::read(void) {
    //prints.info_msg("Reading temperature...");
    //Open file
    std::ifstream w1_slave;
    //prints.info_msg("Opening " + filename + "...");
    w1_slave.open(filename.c_str());
    
    //Read first string from file
    std::string line;
    std::getline(w1_slave, line);
    //prints.info_msg("w1_slave line #1: " + line);
    //prints.info_msg("line substring:" + line.substr(line.length() - 3));
    //prints.info_msg("equals: " + line.subtr(line.length() - 3) == "YES");
    
    if(line.substr(line.length() - 3) == "YES"){
        //read temperature
	//prints.info_msg("Proceeding to next line...");
        std::getline(w1_slave, line);
	//prints.info_msg("w1_slave line #2: " + line);
        float temperature = std::stof(line.substr(line.size()-5))/1000;
        return temperature;
    }else{
        prints.error_msg(true, "Error reading from sensor, make sure sensor drivers are enabled...");
        return 0.0;
    }
}

/*
 * Print the sensor value
 * @return string The temperature expressed as a string
 */
std::string DS18B20::printTemp(void) {
    return std::to_string(read());
}
