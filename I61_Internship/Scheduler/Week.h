/*I61 Ministries License
 * This code may only be used with the written consent of I61 Ministries and partners.
 */

/* 
 * File:   Week.h
 * Author: deepg
 *
 * Created on May 5, 2018, 9:03 AM
 */

#ifndef WEEK_H
#define WEEK_H

class Week : public Day{
public:
    Week(int week_of_month);
    
    bool edit_Day(int day_of_week);
    bool clear_Day(int day_of_week);
        
    std::string print_Week(void);
    bool save_Week(void);
    
private:
    int week;
};

#endif /* WEEK_H */

