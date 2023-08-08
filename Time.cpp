#include "Time.h"
#include <sstream>

// Default constructor
Time::Time()
    : hour(0), minute(0)
{
}

// Constructor with parameters
Time::Time(int h, int m)
    : hour(h), minute(m)
{
    // Check if the input values are valid
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59)
    {
        throw std::invalid_argument("Invalid time");
    }
}

// Get the hour value
int Time::getHour() const
{
    return hour;
}

// Get the minute value
int Time::getMinute() const
{
    return minute;
}

// Set the hour value
void Time::setHour(int h)
{
    // Check if the input value is valid
    if (h < 0 || h > 23)
    {
        throw std::invalid_argument("Invalid hour");
    }
    hour = h;
}

// Set the minute value
void Time::setMinute(int m)
{
    // Check if the input value is valid
    if (m < 0 || m > 59)
    {
        throw std::invalid_argument("Invalid minute");
    }
    minute = m;
}

// Overloaded input stream operator
std::istream& operator>>(std::istream& is, Time& t)
{
    int h, m;
    char c;
    is >> h >> c >> m;
    // Check if the input is valid
    if (!is || c != ':')
    {
        is.setstate(std::ios_base::failbit);
        return is;
    }
    t = Time(h, m);
    return is;
}

// fromString function
Time Time::fromString(const std::string& s)
{
    std::istringstream is(s);
    Time t;
    is >> t;
    return t;
}

// Overloaded output stream operator
std::ostream& operator<<(std::ostream& os, const Time& t)
{
    os << t.getHour() << ':' << t.getMinute();
    return os;
}