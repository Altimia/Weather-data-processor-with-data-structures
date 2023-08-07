#include <iostream>
#include "WindLog.h"

using namespace std;

// WindLog constructor with initialization list
WindLog::WindLog(Date d, Time t, double ws, double sr, double at)
    : date(d), time(t), windSpeed(ws), solarRad(sr), airTemp(at) {}

// Getter methods
Date WindLog::getDate()
{
    return date;
}

Time WindLog::getTime()
{
    return time;
}

double WindLog::getWindSpeed()
{
    return windSpeed;
}

double WindLog::getSolarRad()
{
    return solarRad;
}

double WindLog::getAirTemp()
{
    return airTemp;
}

// Setter methods
void WindLog::setDate(Date d)
{
    date = d;
}

void WindLog::setTime(Time t)
{
    time = t;
}

void WindLog::setWindSpeed(double ws)
{
    windSpeed = ws;
}

void WindLog::setSolarRad(double sr)
{
    solarRad = sr;
}

void WindLog::setAirTemp(double at)
{
    airTemp = at;
}

// overloading the << operator
std::ostream &operator<<(std::ostream &os, const WindLog &wl)
{
    os << wl.getDate() << " " << wl.getTime() << " " << wl.getWindSpeed() << " " << wl.getSolarRad() << " " << wl.getAirTemp();
    return os;
}

std::istream &operator>>(std::istream &is, WindLog &wl)
{
    Date d;
    Time t;
    double ws, sr, at;
    is >> d >> t >> ws >> sr >> at;
    wl.setDate(d);
    wl.setTime(t);
    wl.setWindSpeed(ws);
    wl.setSolarRad(sr);
    wl.setAirTemp(at);
    return is;
}