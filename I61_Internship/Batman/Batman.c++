/*I61 Ministries License
 * This code may only be used with the written consent of I61 Ministries and partners.
 */
#include "Batman.h"

/*
 * Constructs a new Battery Manager and gathers an unlimited number of lines of data
 * @param bool print_debug: If true, print the debug messages
 * @param bool record_data: If true, record the data to a file
 */
Batman::Batman(bool print_debug, bool record_data){
    wiringPiSetup(); //Initialize wiringPi
    this-> debug = print_debug;
    this-> record = record_data;
}

/*
 * Records a limited number of lines of data
 * @param bool print_debug: If true, print debug messages
 * @param bool record_data: If true, record the data
 * @param int number_of_Lines: The number of lines of data to collect
 */
Batman::Batman(bool print_debug, bool record_data, int number_of_Lines){

    data.time_point = millis(); //Set the time that the program starts...

    wiringPiSetup(); //Initialize wiringPi
    this-> debug = print_debug;
    this-> record = record_data;
    
    int lines_collected = 0;
        
    while(lines_collected < number_of_Lines){
        //collect data
        getCurrent(*data.currentIN, *data.currentOUT, *data.netCurrentFlow);
        lines_collected++;
    }
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
    //TODO: Implement data sending features...
    print.info_msg(true, "Message from bits and bytes");
}

/*
 * Send warning to the user
 * @param std::string message: The message to send to the user
 */
 void Batman::sendWarning(std::string message){
	print.warning_msg(message);
	//TODO: Send message with FONA
 }

/*
 * Measures the net current flowing through the system
 * @return float: The net current, positive if charging, negative if discharging power faster than input
 */
float Batman::getCurrent(float *currentIn, float *currentOut, float *netCurrentFlow){
    //Read and record the current flowing through the wires...
    &currentIn = input.getCurrent_mA();
    &currentOut = output.getCurrent_mA();

    //Record the time data and calculate time since last recording point
    float time_millis = millis(); //Current time since program start
    data.time_step = (time_millis - data.time_point)/1000; //Difference in time(seconds), since the last reading
    data.total_time += data.time_step;
    data.time_point = millis(); // Record the time that the current was measured
   
    //Record the net current flow 
    &netCurrentFlow = &currentIn - &currentOut;
    
    //Print debug statements and notify user if current flow is abnormal, etc.
    //TODO: Implement user warnings... 
    print.info_msg(debug, "Current In: " + std::to_string(&currentIn) + "\n     Current Out: " + std::to_string(&currentOut));
    print.info_msg(debug && (&netCurrentFlow > 0), "Charging battery...");
    print.info_msg(debug && (&netCurrentFlow < 0), "Discharging battery...");

    return &netCurrentFlow;
}

/*
 * Measures the voltage flowing through the system
 * @return float: The voltage in the system
 */
float Batman::getVoltage(float *voltage){
    &voltage = input.getVoltage_mV();
    
    print.info_msg(debug || verbose, "Voltage Input: " + std::to_string(&voltage));

    //TODO: Implement user warnings...
    print.warning_msg(debug && (&voltage < 1000), "Voltage is below expected level...");
    
    return &voltage;
}

/*
 * Calculates the current amount of charge in the battery as a percentage of total
 * @param float* netCharge: The amount of charge in the battery
 * @param float* time_step: How long since the last data collection point
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
int[] Batman::print_data(void){
    /*
     * 1. Voltage
     * 2. Net Charge
     * 3. Current in
     * 4. Current out
     * 5. Time stamp
     */
    float[4] data{data.voltage, data.netCharge, data.currentIN, data.currentOUT};
    return data;
}
