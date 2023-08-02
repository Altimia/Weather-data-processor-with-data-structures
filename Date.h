#include <iostream>

class Date
{
private:
    int day;   // day of the month (1-31)
    int month; // month of the year (1-12)
    int year;  // year (e.g. 2021)

public:
    // default constructor
    Date() : day(1), month(1), year(2000) {}

    // constructor that takes three integer arguments: day, month, and year
    Date(int d, int m, int y);

    // public member functions to access the day, month, and year member variables
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // public member functions to modify the day, month, and year member variables
    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

};
// input and output operators
std::ostream& operator<<(std::ostream& out, const Date& date);
std::istream& operator>>(std::istream& in, Date& date);
