#include "DS18B20.h"

/*
 * Run the system setup commands for the sensor using the pi drivers
 */
DS18B20::DS18B20(std::string MAC_address) {
    //INIT DRIVERS
    filename = DS18B20_PATH MAC_address;
    std::system("sudo modprobe w1-gpio");
    std::system("sudo modprobe w1-therm");
}

/*
 * Run the setup for the commands, and use open source libraries
 */
DS18B20::DS18B20(int pinNumber) {
    //DO STUFF THE HARD WAY!!!
    std::cout << "[ERROR]: not implemented yet..." << std::endl;
}

/*
 * Read the sensor value from the system file
 * @return float The sensor reading in degrees C
 */
float DS18B20::read(void) {
    //Open file
    std::ifstream w1_slave;
    w1_slave.open(filename.c_str());
    
    //Read first string from file
    std::string line;
    std::getline(w1_slave, line);
    
    if(line.ends_with("YES")){
        //read temperature
        std::getline(w1_slave, line);
        float temperature = std::stoi(line.substr(line.size()-5);
        return temperature;
    }else{
        MSG_Printer print;
        print.error_msg(true, "Error reading from sensor, make sure sensor drivers are enabled...");
        return 0.0;
    }
}

/*
 * Print the sensor value
 * @return string The temperature expressed as a string
 */
std::string DS18B20::print(void) {
    return std::to_string(read());
}
