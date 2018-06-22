/*I61 Ministries License
 * This code may only be used with the written consent of I61 Ministries and partners.
 */

#include "Hour.h"

/*
 * Creates an instance of Hour
 * @param int hour_of_day: The hour of the day that the user wants to edit
 */
Hour::Hour(int hour_of_day){
    hour = hour_of_day;
}

/*
 * Add a task to be performed by the system every hour, half hour, or whatever
 * @param string name: Name of the task
 * @param int start_Time: The time the first iteration of the task will be executed
 * @param int frequency: How often the task will be executed
 * @return bool: True if successful, otherwise false...
 */
bool Hour::add_Task(std::string name, int start_Time, int frequency){
    //TODO
    return false;
}

/*
 * Adds a task to be performed by the system (x) times per day
 * @param string name: Name of the task
 * @param int start_Time: The first time the task will be run
 * @param int times_PerDay: How many times the task will be run throughout the day
 * @return bool: True if successful, otherwise false...
 */
bool Hour::add_Task(std::string name, int start_Time, int times_PerDay){
    //TODO
    return false;
}

/*
 * Adds a task to be performed by the system for (x) time
 * @param string name: Name of the task
 * @param int start_Time: The first time the task will be run
 * @param int duration: how long the task should be called continuously...
 * @return bool: True if successful, otherwise false... 
 */
bool Hour::add_Task(std::string name, int start_Time, int duration){
    //TODO
    return false;
}

/*
 * Removes a task from the current selected hour
 * @param string name: The name of the task to be removed
 * @return bool: True if successful, otherwise false...
 */
bool Hour::remove_Task(std::string name){
    //TODO
    return false;
}

/*
 * Prints the tasks scheduled for this hour
 * @return string: The schedule for the hour
 */
std::string Hour::print_Hour(void){
    //TODO
    return "";
}

/*
 * Writes the schedule to a selected file
 * @param string hour: The schedule for the hour
 * @param string output_filename: The file the schedule is to be written to
 * @param bool: True if successful, otherwise false...
 */
bool Hour::save_Hour(std::string hour, std::string output_filename){
    //TODO
    return false;
}