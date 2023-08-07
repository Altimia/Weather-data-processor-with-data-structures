#include <iostream>
#include "DataLoader.h"

void displayMenu();
void handleMenuOption(int option, const Vector<WindLog>& data);
void calculateAverageWindSpeedAndAirTemp(const Vector<WindLog>& data);
void calculateAverageWindSpeedAndAirTempForYear(const Vector<WindLog>& data);
void calculateTotalSolarRadiationForYear(const Vector<WindLog>& data);
void calculateAverageAndWriteToFile(const Vector<WindLog>& data);
void convertUnits(WindLog& log);

#include <fstream>

int main()
{
    DataLoader loader;
    Vector<WindLog> data;

    std::ifstream inFile("met_index.txt");
    std::string fileName;
    while (std::getline(inFile, fileName))
    {
        Vector<WindLog> fileData = loader.loadData("Data/" + fileName);
        for (int i = 0; i < fileData.Size(); i++)
        {
            data.PushBack(fileData[i]);
        }
    }

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
    int month, year;
    std::cout << "Enter month (1-12): ";
    std::cin >> month;
    std::cout << "Enter year: ";
    std::cin >> year;

    double totalWindSpeed = 0.0;
    double totalAirTemp = 0.0;
    int count = 0;

    for (int i = 0; i < data.Size(); i++)
    {
        if (data[i].getDate().getMonth() == month && data[i].getDate().getYear() == year)
        {
            totalWindSpeed += data[i].getWindSpeed();
            totalAirTemp += data[i].getAirTemp();
            count++;
        }
    }

    if (count > 0)
    {
        double averageWindSpeed = totalWindSpeed / count;
        double averageAirTemp = totalAirTemp / count;

        std::cout << "Average wind speed for " << month << "/" << year << ": " << averageWindSpeed << "\n";
        std::cout << "Average air temperature for " << month << "/" << year << ": " << averageAirTemp << "\n";
    }
    else
    {
        std::cout << "No data for " << month << "/" << year << ".\n";
    }
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
