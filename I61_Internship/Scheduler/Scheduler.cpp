/*I61 Ministries License
 * This code may only be used with the written consent of I61 Ministries and partners.
 */

#include "Scheduler.h"
 
/*
 * Creates a new instance of Scheduler
 */
Scheduler::Scheduler(void){}

/*
 * Creates a new schedule that uses only one day, continuously looping
 * @param int day_of_week: The pre-configured day to loop
 */
void Scheduler::new_ScheduleDay(int day_of_week){}

/*
 * Creates a new schedule that uses only one week, continuously looping
 */
void Scheduler::new_ScheduleWeek(void){}

/*
 * Creates a new two week schedule that loops continuously
 * @param int first_week_num: The first week to run
 * @param int second_week_num: The second week to run, after this week is finished
 *                          the first_week is run again
 */
void Scheduler::new_Schedule2Week(int first_week_num, int second_week_num){}

/*
 * Creates a new schedule of variable length of weeks to loop
 * @param int num_weeks: How many weeks to have in the loop
 * @param int[] weeks_included: The weeks to use in the schedule, in order
 */
void Scheduler::new_ScheduleCustomWeek(int num_weeks, int[] weeks_included){}

/*
 * Creates a new schedule one month long, or 5 weeks
 * @param int month_of_year: The month of the year this represents
 */
void Scheduler::new_ScheduleMonth(int month_of_year){}

/*
 * Prints all pre-configured schedules
 * @return string: The schedules to print
 */
std::string Scheduler::print_Schedules(void){}

/*
 * Selects the schedule the user wants to run
 * @param string schedule_options: The name of the schedule to run
 */
void Scheduler::select_Schedule(std::string schedule_options){}