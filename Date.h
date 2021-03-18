#ifndef _DATE_
#define _DATE_

#include <iostream>
#include <string>

using namespace std;

class Date
{
private:
    int month, day, year;

public:
    Date();
    Date(int _month, int _day, int _year);

    void setDate(int _month, int _day, int _year);
    string toString();
    int getMonth()
    {
        return month;
    }
    int getDay()
    {
        return day;
    }
    int getYear()
    {
        return year;
    }
};

#endif