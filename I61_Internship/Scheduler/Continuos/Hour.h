/*I61 Ministries License
 * This code may only be used with the written consent of I61 Ministries and partners.
 */

/* 
 * File:   Hour.h
 * Author: deepg
 *
 * Created on May 5, 2018, 9:04 AM
 */

#ifndef HOUR_H
#define HOUR_H

class Hour{
public:
    Hour(int hour_of_day);
    
    bool add_Task(std::string name, int start_Time, int frequency);
    bool add_Task(std::string name, int start_Time, int times_PerDay);
    bool add_Task(std::string name, int start_Time, int duration);
    
    bool remove_Task(std::string name);
    
    std::string print_Hour(void); //print the schedule to a string
    bool save_Hour(std::string hour); //save the hour schedule to a file
    
private:
    int hour;
}

#endif /* HOUR_H */

