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
  WindLog();
  WindLog(Date d, Time t, double ws, double sr, double at);
  Date getDate() const;
  Time getTime() const;
  double getWindSpeed() const;
  double getSolarRad() const;
  double getAirTemp() const;
  void setDate(Date d);
  void setTime(Time t);
  void setWindSpeed(double ws);
  void setSolarRad(double sr);
  void setAirTemp(double at);
};

std::ostream& operator<<(std::ostream& os, const WindLog& wl);
std::istream& operator>>(std::istream& is, WindLog& wl);

#endif // WINDLOG_H
