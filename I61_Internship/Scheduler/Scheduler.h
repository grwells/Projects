/*I61 Ministries License
 * This code may only be used with the written consent of I61 Ministries and partners.
 */

/* 
 * File:   Scheduler.h
 * Author: deepg
 *
 * Created on May 1, 2018, 9:27 PM
 */

#ifndef SCHEDULER_H
#define SCHEDULER_H

class Day{
public:
    Day(int day_of_week);
    
    bool add_Task(std::string name, int start_Time, int frequency);
    bool add_Task(std::string name, int start_Time, int times_PerDay);
    bool add_Task(std::string name, int start_Time, int duration);
    
    bool remove_Task(std::string name);
    
    std::string print_Schedule(void);
    bool save_Day(void);
};

class Week : public Day{
public:
    Week(int week_of_month);
    
    bool add_Day(int day_of_week);
    bool remove_Day(int day_of_week);
    bool remove_Day(std::string day_of_week);
    
    std::string print_Week(void);
    bool save_Week(void);
};

class Month : public Week{
public:
    Month(int month_of_year);
    Month(void);
    
    bool add_Week(int week_of_month);
    bool remove_Week(int week_of_month);
    
    std::string print_Month(void);
    bool save_Month(void);
};

class Scheduler{
public:
    Scheduler(void);
    
    void new_ScheduleDay(int day_of_week); //Creates a one day schedule that runs in loops
    void new_ScheduleWeek(void); //Creates a one week schedule that runs in loops
    void new_Schedule2Week(int first_week_num, int second_week_num); //Creates a two week schedule that runs in loops
    void new_ScheduleCustomWeek(int num_weeks, int[] weeks_included); //Creates a looping schedule from pre-existing weeks
    void new_ScheduleMonth(int month_of_year); //Creates a one month schedule that runs in a loop
    
    std::string print_Schedules(void);
    void select_Schedule(std::string schedule_options); //Prints available schedules and allows user to pick one    
};


#endif /* SCHEDULER_H */

