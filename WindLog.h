#ifndef WINDLOG_H
#define WINDLOG_H

#include "Date.h"
#include "Time.h"

class WindLog
{
private:
  Date date;
  Time time;
  double windSpeed;
  double solarRad;
  double airTemp;

public:
  WindLog(Date d, Time t, double ws, double sr, double at) : date(d), time(t), windSpeed(ws), solarRad(sr), airTemp(at) {}
  Date getDate() { return date; }
  Time getTime() { return time; }
  double getWindSpeed() { return windSpeed; }
  double getSolarRad() { return solarRad; }
  double getAirTemp() { return airTemp; }
  void setDate(Date d) { date = d; }
  void setTime(Time t) { time = t; }
  void setWindSpeed(double ws) { windSpeed = ws; }
  void setSolarRad(double sr) { solarRad = sr; }
  void setAirTemp(double at) { airTemp = at; }
};

std::ostream& operator<<(std::ostream& os, const WindLog& wl);
std::istream& operator>>(std::istream& is, WindLog& wl);

#endif // WINDLOG_H