#include <iostream>
#include "Time.h"

int main() {
    // Test default constructor
    Time t1;
    std::cout << "Default time: " << t1 << std::endl;

    // Test constructor with parameters
    Time t2(12, 30);
    std::cout << "Time with parameters: " << t2 << std::endl;

    // Test invalid hour value
    try {
        Time t3(25, 0);
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid hour value: " << e.what() << std::endl;
    }

    // Test invalid minute value
    try {
        Time t4(12, 60);
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid minute value: " << e.what() << std::endl;
    }

    // Test setHour() method
    t1.setHour(8);
    std::cout << "Time after setHour(): " << t1 << std::endl;

    // Test setMinute() method
    t1.setMinute(45);
    std::cout << "Time after setMinute(): " << t1 << std::endl;

    // Test input stream operator
    Time t5;
    std::cout << "Enter a time (hh:mm): ";
    std::cin >> t5;
    std::cout << "You entered: " << t5 << std::endl;

    return 0;
}