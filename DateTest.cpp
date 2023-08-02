#include <iostream>
#include "Date.h"

int main()
{
    // create a default date and print it
    Date defaultDate;
    std::cout << "Default date: " << defaultDate << std::endl;

    // create a date with the parameterized constructor and print it
    Date date(31, 12, 2021);
    std::cout << "Date: " << date << std::endl;

    // modify the date and print it
    date.setDay(1);
    date.setMonth(1);
    date.setYear(2022);
    std::cout << "Modified date: " << date << std::endl;

    return 0;
}