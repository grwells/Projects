/*I61 Ministries License
 * This code may only be used with the written consent of I61 Ministries and partners.
 */

#include "Month.h"

/*
 * Creates a new Month
 * @param int month_of_year: The month of the calendar year this represents, 
 *                              1 == January
 */
Month::Month(int month_of_year){}

/*
 * Creates a new generic month
 */
Month::Month(void){}

/*
 * Adds a week to the month's schedule
 * @param int week_of_month: Number of the week to add to the month
 * @return bool: True if successful, otherwise false...
 */
bool add_Week(int week_of_month);

/*
 * Removes a week from the month
 * @param int week_of_month: The number of the week to remove
 * @return bool: True if successful, otherwise false...
 */
bool remove_Week(int week_of_month);

/*
 * Prints the schedule for the month
 * @return string: The Schedule
 */
std::string Month::print_Month(void){}

/*
 * Saves the month to a specific file
 * @param string output_filename: The file to save the schedule to
 * @return bool: True if successful, otherwise false...
 */
bool save_Month(void);
