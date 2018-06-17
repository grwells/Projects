/*I61 Ministries License
 * This code may only be used with the written consent of I61 Ministries and partners.
 */

#include "Week.h"

/*
 * Creates a new instance of week
 * @param int week_of_month: The week of the month, 1, 2, etc, to edit
 */
Week::Week(int week_of_month){}

/*
 * Edits the schedule for a day of the week
 * @param int day_of_week: The day of the week to edit, 1 == Monday, 7 == Sunday
 * @param bool add_or_remove_Task: If true, add task, if false remove task
 * @param string task_name: The task to be added or removed
 * @return bool: True if successful, otherwise false...
 */
bool Week::edit_Day(int day_of_week, bool add_or_remove_Task, std::string task_name){}

/*
 * Clears all tasks from the schedule for the day
 * @return bool: True if successful, otherwise false...
 */
bool Week::clear_Day(int day_of_week){}

/*
 * Prints the week schedule.
 * @return string: The schedule
 */
std::string Week::print_Week(void){}

/*
 * Saves the week to a file
 * @param string week: The schedule for the week
 * @param string output_filename: The file to print the schedule to
 * @return bool: True if successful, otherwise false...
 */
bool Week::save_Week(std::string week, std::string output_filename){}