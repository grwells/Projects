/*I61 Ministries License
 * This code may only be used with the written consent of I61 Ministries and partners.
 */
#include "Batman.h"

/*
 * Constructs a new Battery Manager
 */
Batman::Batman(bool print_debug, bool record_data, bool print_data){
    wiringPiSetup(); //Initialize wiringPi
}

/*
 * Gets the charge level of the battery
 * @param float *netCharge: The current state of the battery
 * @return float: The charge in mA
 */
float Batman::getChargeLevel(float *netCharge, float *maxCharge){
    getCurrent(*data.currentIN, *data.currentOUT, *data.netCurrentFlow);
    return &netCharge/&maxCharge;
}

/*
 * Stores the collected data in a CSV journal file for reference later
 * @param string data: The data to put in the file
 */
void Batman::logData(std::string filename, std::string data){
    ofstream file;
    
    if(file.open(filename)){
        print.success_msg(true, filename " is open");
    }else{print.error_msg(true, filename " could not be opened");}
    
    file << data;
    
    file.close();
    print(true, filename " closed");
}

/*
 * Sends the data to the user using the communication system
 */
void Batman::sendData(void){
    print.info_msg(true, "Message from bits and bytes");
}

/*
 * Measures the net current flowing through the system
 * @return float: The net current, positive if charging, negative if discharging power faster than input
 */
float Batman::getCurrent(float *currentIn, float *currentOut, float *netCurrentFlow){
    &currentIn = input.getCurrent();
    &currentOut = output.getCurrent();
    
    &netCurrentFlow = &currentIn - &currentOut;
    
    print.info_msg(debug, "Current In: " + std::to_string(&currentIn) + "\n     Current Out: " + std::to_string(&currentOut));
    
    return &netCurrentFlow;
}

/*
 * Measures the voltage flowing through the system
 * @return float: The voltage in the system
 */
float Batman::getVoltage(float *voltage){
    &voltage = input.getVoltage();
    
    print.info_msg(debug || verbose, "Voltage Input: " + std::to_string(&voltage));
    
    return &voltage;
}

/*
 * Calculates the current amount of charge in the battery as a percentage 
 * @return float: Percent the battery is charged
 */
float Batman::calcCurrentCharge(float *netCharge, float *time_step){
    &netCharge += (time_step * getCurrent(*data.currentIN, *data.currentOUT, *data.netCurrentFlow));
    return &netCharge;
}

/*
 * Whether or not the battery charge is below a minimum charge level
 * @return boolean: True if the battery charge is low
 */
bool Batman::batteryIsLow(void){
    getCurrent(*data.currentIN, *data.currentOUT, *data.netCurrentFlow);
    return (data.netCharge - data.maxCharge) <= chargeLowerLim;
}

/*
 * Prints the data to an array of values that can be parsed by other programs
 * @return int[]: The values other programs might be interested in
 */
int[] Batman::print_data(void){}