#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

Date::Date()
{
    month = day = year = 0;
}

Date::Date(int _month, int _day, int _year)
{
    month = _month;
    day = _day;
    year = _year;
}

void Date::setDate(int _month, int _day, int _year)
{
    month = _month;
    day = _day;
    year = _year;
}

string Date::toString()
{
    string date = "";
    date += to_string(month) + "/" + to_string(day) + "/" + to_string(year);

    return date;
}