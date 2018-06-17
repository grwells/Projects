/*I61 Ministries License
 * This code may only be used with the written consent of I61 Ministries and partners.
 */

#include "Day.h"

/*
 * Creates a new instance of Day
 * @param int day_of_week: The day of the week, ie, Monday is day 01
 */
Day::Day(int day_of_week){
    day = day_of_week;
}

/*
 * Edits an hour of the day
 * @param int hour_of_day: The hour of the day according to military time or 24
 *                          hour clock.
 * @return bool: True if successful, otherwise false...
 */
bool Day::edit_Hour(int hour_of_day){}

/*
 * Wipes the selected hour clean.
 * @param int hour_of_day: The hour of the day according to military time or 24
 *                          hour clock.
 * @return bool: True if successful, otherwise false...
 */
bool Day::clear_Hour(int hour_of_day);

/*
 * Prints the schedule for the day, hour by hour
 * @return string: The schedule, hour by hour
 */
std::string Day::print_Day(void){}

/*
 * Saves the schedule for the day to a file
 * @param string day: The schedule for the day
 * @param string output_filename: The file to record the schedule in
 * @return bool: True if successful, otherwise false...
 */
bool Day::save_Day(std::string day, std::string output_filename);