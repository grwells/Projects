/*I61 Ministries License
 * This code may only be used with the written consent of I61 Ministries and partners.
 */

/* 
 * File:   Day.h
 * Author: deepg
 *
 * Created on May 5, 2018, 9:02 AM
 */

#ifndef DAY_H
#define DAY_H

class Day{    
public:
    Day(int day_of_week);
    
    bool edit_Hour(int hour_of_day);
    bool clear_Hour(int hour_of_day);
    
    std::string print_Day(void); //print schedule for the day
    bool save_Day(std::string day); //save the day schedule to a file
    
private:
    int day;
};

#endif /* DAY_H */

