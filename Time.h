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
    Time();
    Time(int h, int m);
    int getHour() const;
    int getMinute() const;
    void setHour(int h);
    void setMinute(int m);
};

// Overloaded input stream operator for Time class
std::istream& operator>>(std::istream& is, Time& t);

// Overloaded output stream operator for Time class
std::ostream& operator<<(std::ostream& os, const Time& t);

#endif // TIME_H
