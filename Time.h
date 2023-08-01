#ifndef TIME_H
#define TIME_H

#include <stdexcept>
#include <iostream>

class Time
{
private:
    int hour; // hour of the time
    int minute; // minute of the time

public:
    Time(int h, int m) : hour(h), minute(m)
    {
        // Validate input values
        if (h < 0 || h > 23)
        {
            throw std::invalid_argument("Hour value must be between 0 and 23");
        }
        if (m < 0 || m > 59)
        {
            throw std::invalid_argument("Minute value must be between 0 and 59");
        }
    }
    int getHour() const { return hour; } // returns the hour of the time
    int getMinute() const { return minute; } // returns the minute of the time
    void setHour(int h)
    {
        // Validate input value
        if (h < 0 || h > 23)
        {
            throw std::invalid_argument("Hour value must be between 0 and 23");
        }
        hour = h; // set the hour of the time
    }
    void setMinute(int m)
    {
        // Validate input value
        if (m < 0 || m > 59)
        {
            throw std::invalid_argument("Minute value must be between 0 and 59");
        }
        minute = m; // set the minute of the time
    }
};

// Overloaded input stream operator for Time class
std::istream& operator>>(std::istream& is, Time& t)
{
    int h, m;
    char colon;
    is >> h >> colon >> m;
    t = Time(h, m); // set the hour and minute of the time
    return is;
}

// Overloaded output stream operator for Time class
std::ostream& operator<<(std::ostream& os, const Time& t)
{
    os << t.getHour() << ':' << t.getMinute(); // output the hour and minute of the time
    return os;
}

#endif // TIME_H
