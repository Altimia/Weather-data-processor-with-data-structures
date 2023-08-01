#ifndef TIME_H
#define TIME_H

#include <stdexcept>

class Time
{
private:
    int hour;
    int minute;

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
    int getHour() const { return hour; }
    int getMinute() const { return minute; }
    void setHour(int h)
    {
        // Validate input value
        if (h < 0 || h > 23)
        {
            throw std::invalid_argument("Hour value must be between 0 and 23");
        }
        hour = h;
    }
    void setMinute(int m)
    {
        // Validate input value
        if (m < 0 || m > 59)
        {
            throw std::invalid_argument("Minute value must be between 0 and 59");
        }
        minute = m;
    }
};

#endif // TIME_H
