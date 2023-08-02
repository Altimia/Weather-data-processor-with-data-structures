#include "Date.h"

// default constructor
Date::Date()
    : day(1), month(1), year(2000)
{
}

// parameterized constructor that takes three integer arguments: day, month, and year
Date::Date(int d, int m, int y)
    : day(d), month(m), year(y)
{
}

// public member functions to access the day, month, and year member variables
int Date::getDay() const
{
    return day;
}

int Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}

// public member functions to modify the day, month, and year member variables
void Date::setDay(int d)
{
    day = d;
}

void Date::setMonth(int m)
{
    month = m;
}

void Date::setYear(int y)
{
    year = y;
}

// output operator
std::ostream& operator<<(std::ostream& out, const Date& date)
{
    out << date.getDay() << '/' << date.getMonth() << '/' << date.getYear();
    return out;
}

// input operator
std::istream& operator>>(std::istream& in, Date& date)
{
    int d, m, y;
    char sep1, sep2;
    in >> d >> sep1 >> m >> sep2 >> y;
    if (sep1 == '/' && sep2 == '/')
    {
        date.setDay(d);
        date.setMonth(m);
        date.setYear(y);
    }
    else
    {
        in.setstate(std::ios_base::failbit);
    }
    return in;
}