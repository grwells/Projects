/*I61 Ministries License
 * This code may only be used with the written consent of I61 Ministries and partners.
 */

/* 
 * File:   Month.h
 * Author: deepg
 *
 * Created on May 5, 2018, 9:04 AM
 */

#ifndef MONTH_H
#define MONTH_H

class Month : public Week{
public:
    Month(int month_of_year);
    Month(void);
    
    bool add_Week(int week_of_month);
    bool remove_Week(int week_of_month);
    
    std::string print_Month(void);
    bool save_Month(void);
    
private:
    int month;
};

#endif /* MONTH_H */

