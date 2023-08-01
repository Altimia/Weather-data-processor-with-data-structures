class Date
{
private:
    int day;   // day of the month (1-31)
    int month; // month of the year (1-12)
    int year;  // year (e.g. 2021)

public:
    // constructor that takes three integer arguments: day, month, and year
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // public member functions to access the day, month, and year member variables
    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }

    // public member functions to modify the day, month, and year member variables
    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }
};

#endif // DATE_H