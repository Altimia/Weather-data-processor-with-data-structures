#include <iostream>
#include "DataLoader.h"

void displayMenu();
void handleMenuOption(int option, const Vector<WindLog>& data);
void calculateAverageWindSpeedAndAirTemp(const Vector<WindLog>& data);
void calculateAverageWindSpeedAndAirTempForYear(const Vector<WindLog>& data);
void calculateTotalSolarRadiationForYear(const Vector<WindLog>& data);
void calculateAverageAndWriteToFile(const Vector<WindLog>& data);
void convertUnits(WindLog& log);

int main()
{
    DataLoader loader;
    Vector<WindLog> data = loader.loadData("path/to/your/csv/file.csv");

    int option;
    do
    {
        displayMenu();
        std::cin >> option;
        handleMenuOption(option, data);
    } while (option != 5);

    return 0;
}

void displayMenu()
{
    std::cout << "Menu Options:\n";
    std::cout << "1. Calculate average wind speed and ambient air temperature for a specified month and year.\n";
    std::cout << "2. Calculate average wind speed and ambient air temperature for each month of a specified year.\n";
    std::cout << "3. Calculate total solar radiation in kWh/m^2 for each month of a specified year.\n";
    std::cout << "4. Calculate average wind speed, ambient air temperature, and total solar radiation for each month of a specified year, and write to a file.\n";
    std::cout << "5. Exit the program.\n";
    std::cout << "Enter your choice: ";
}

void handleMenuOption(int option, const Vector<WindLog>& data)
{
    switch (option)
    {
    case 1:
        calculateAverageWindSpeedAndAirTemp(data);
        break;
    case 2:
        calculateAverageWindSpeedAndAirTempForYear(data);
        break;
    case 3:
        calculateTotalSolarRadiationForYear(data);
        break;
    case 4:
        calculateAverageAndWriteToFile(data);
        break;
    case 5:
        std::cout << "Exiting the program.\n";
        break;
    default:
        std::cout << "Invalid option. Please try again.\n";
        break;
    }
}

void calculateAverageWindSpeedAndAirTemp(const Vector<WindLog>& data)
{
    // TODO: Implement this function
}

void calculateAverageWindSpeedAndAirTempForYear(const Vector<WindLog>& data)
{
    // TODO: Implement this function
}

void calculateTotalSolarRadiationForYear(const Vector<WindLog>& data)
{
    // TODO: Implement this function
}

void calculateAverageAndWriteToFile(const Vector<WindLog>& data)
{
    // TODO: Implement this function
}

void convertUnits(WindLog& log)
{
    // TODO: Implement this function
}
