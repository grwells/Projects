/*I61 Ministries License
 * This code may only be used with the written consent of I61 Ministries and partners.
 */
#include "Batman.h"

/*
 * Constructs a new Battery Manager
 */
Batman::Batman(bool print_debug, bool record_data, bool print_data){}

/*
 * Gets the charge level of the battery
 * @return float: The charge in mA
 */
float Batman::getChargeLevel(void){}

/*
 * Stores the collected data in a CSV journal file for reference later
 * @param string data: The data to put in the file
 */
void Batman::logData(std::string data){}

/*
 * Sends the data to the user using the communication system
 */
void Batman::sendData(void){}

/*
 * Measures the net current flowing through the system
 * @return float: The net current, positive if charging, negative if discharging power faster than input
 */
float Batman::getCurrent(void){}

/*
 * Measures the voltage flowing through the system
 * @return float: The voltage in the system
 */
float Batman::getVoltage(void){}

/*
 * Calculates the current amount of charge in the battery as a percentage 
 * @return float: Percent the battery is charged
 */
float Batman::calcCurrentCharge(void){}

/*
 * Whether or not the battery charge is below a minimum charge level
 * @return boolean: True if the battery charge is low
 */
bool Batman::batteryIsLow(void){}

/*
 * Prints the data to an array of values that can be parsed by other programs
 * @return int[]: The values other programs might be interested in
 */
int[] Batman::print_data(void){}