#include <iostream>
#include "Vector.h"
#include "WindLog.h"
#include <fstream>
#include <sstream>

void displayMenu();
void handleMenuOption(int option, const Vector<WindLog>& data);
void calculateAverageWindSpeedAndAirTemp(const Vector<WindLog>& data);
void calculateAverageWindSpeedAndAirTempForYear(const Vector<WindLog>& data);
void calculateTotalSolarRadiationForYear(const Vector<WindLog>& data);
void calculateAverageAndWriteToFile(const Vector<WindLog>& data);
void convertUnits(WindLog& log);


Vector<WindLog> loadData(const std::string& filePath)
{
    Vector<WindLog> data;
    std::ifstream inFile(filePath);
    std::string line;
    while (std::getline(inFile, line))
    {
        std::istringstream ss(line);
        std::string field;
        std::getline(ss, field, ',');
        Date date = Date::fromString(field);
        std::getline(ss, field, ',');
        Time time = Time::fromString(field);
        std::getline(ss, field, ',');
        double windSpeed = std::stod(field);
        std::getline(ss, field, ',');
        double solarRad = std::stod(field);
        std::getline(ss, field, ',');
        double airTemp = std::stod(field);
        WindLog log(date, time, windSpeed, solarRad, airTemp);
        data.PushBack(log);
    }
    return data;
}

int main()
{
    // DataLoader removed
    Vector<WindLog> data;

    std::ifstream inFile("met_index.txt");
    std::string fileName;
    while (std::getline(inFile, fileName))
    {
        Vector<WindLog> fileData = loadData("Data/" + fileName);
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
    int year;
    std::cout << "Enter year: ";
    std::cin >> year;

    double totalWindSpeed[12] = {0.0};
    double totalAirTemp[12] = {0.0};
    int count[12] = {0};

    for (int i = 0; i < data.Size(); i++)
    {
        if (data[i].getDate().getYear() == year)
        {
            int month = data[i].getDate().getMonth();
            totalWindSpeed[month - 1] += data[i].getWindSpeed();
            totalAirTemp[month - 1] += data[i].getAirTemp();
            count[month - 1]++;
        }
    }

    for (int i = 0; i < 12; i++)
    {
        if (count[i] > 0)
        {
            double averageWindSpeed = totalWindSpeed[i] / count[i];
            double averageAirTemp = totalAirTemp[i] / count[i];

            std::cout << "Average wind speed for " << i + 1 << "/" << year << ": " << averageWindSpeed << "\n";
            std::cout << "Average air temperature for " << i + 1 << "/" << year << ": " << averageAirTemp << "\n";
        }
        else
        {
            std::cout << "No data for " << i + 1 << "/" << year << ".\n";
        }
    }
}

void calculateTotalSolarRadiationForYear(const Vector<WindLog>& data)
{
    int year;
    std::cout << "Enter year: ";
    std::cin >> year;

    double totalSolarRad[12] = {0.0};
    int count[12] = {0};

    for (int i = 0; i < data.Size(); i++)
    {
        if (data[i].getDate().getYear() == year && data[i].getSolarRad() >= 100)
        {
            int month = data[i].getDate().getMonth();
            totalSolarRad[month - 1] += data[i].getSolarRad();
            count[month - 1]++;
        }
    }

    for (int i = 0; i < 12; i++)
    {
        if (count[i] > 0)
        {
            std::cout << "Total solar radiation for " << i + 1 << "/" << year << ": " << totalSolarRad[i] << " kWh/m^2\n";
        }
        else
        {
            std::cout << "No data for " << i + 1 << "/" << year << ".\n";
        }
    }
}

void calculateAverageAndWriteToFile(const Vector<WindLog>& data)
{
    int year;
    std::cout << "Enter year: ";
    std::cin >> year;

    double totalWindSpeed[12] = {0.0};
    double totalAirTemp[12] = {0.0};
    double totalSolarRad[12] = {0.0};
    int count[12] = {0};

    for (int i = 0; i < data.Size(); i++)
    {
        if (data[i].getDate().getYear() == year)
        {
            int month = data[i].getDate().getMonth();
            totalWindSpeed[month - 1] += data[i].getWindSpeed();
            totalAirTemp[month - 1] += data[i].getAirTemp();
            if (data[i].getSolarRad() >= 100)
            {
                totalSolarRad[month - 1] += data[i].getSolarRad();
            }
            count[month - 1]++;
        }
    }

    std::ofstream outFile("averages.txt");

    for (int i = 0; i < 12; i++)
    {
        if (count[i] > 0)
        {
            double averageWindSpeed = totalWindSpeed[i] / count[i];
            double averageAirTemp = totalAirTemp[i] / count[i];
            double averageSolarRad = totalSolarRad[i] / count[i];

            outFile << "Average wind speed for " << i + 1 << "/" << year << ": " << averageWindSpeed << "\n";
            outFile << "Average air temperature for " << i + 1 << "/" << year << ": " << averageAirTemp << "\n";
            outFile << "Average solar radiation for " << i + 1 << "/" << year << ": " << averageSolarRad << " kWh/m^2\n";
        }
        else
        {
            outFile << "No data for " << i + 1 << "/" << year << ".\n";
        }
    }

    outFile.close();
}

void convertUnits(WindLog& log)
{
    double windSpeedKmh = log.getWindSpeed() * 3.6;
    log.setWindSpeed(windSpeedKmh);

    double solarRadKwh = log.getSolarRad() / 1000;
    log.setSolarRad(solarRadKwh);
}
