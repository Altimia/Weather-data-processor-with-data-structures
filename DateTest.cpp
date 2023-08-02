#include <iostream>
#include "Date.h"

int main()
{
    // Test default constructor
    Date d1;
    std::cout << d1 << std::endl; // Output: 1/1/2000

    // Test parameterized constructor
    Date d2(10, 5, 2022);
    std::cout << d2 << std::endl; // Output: 10/5/2022

    // Test getDay(), getMonth(), and getYear()
    std::cout << d2.getDay() << std::endl; // Output: 10
    std::cout << d2.getMonth() << std::endl; // Output: 5
    std::cout << d2.getYear() << std::endl; // Output: 2022

    // Test setDay(), setMonth(), and setYear()
    d2.setDay(15);
    d2.setMonth(12);
    d2.setYear(2023);
    std::cout << d2 << std::endl; // Output: 15/12/2023

    // Test input operator
    Date d3;
    std::cin >> d3;
    std::cout << d3 << std::endl;

    return 0;
}