#include <iostream>
#include "WindLog.h"

using namespace std;

int main() {
    // create a WindLog object
    WindLog wl(Date(2022, 10, 1), Time(12, 30), 10.5, 200.0, 25.0);
    wl.setTime(Time(13, 30));
    // test getter methods
    cout << "Date: " << wl.getDate() << endl;
    cout << "Time: " << wl.getTime() << endl;
    cout << "Wind Speed: " << wl.getWindSpeed() << endl;
    cout << "Solar Radiation: " << wl.getSolarRad() << endl;
    cout << "Air Temperature: " << wl.getAirTemp() << endl;

    // test setter methods
    wl.setDate(Date(2022, 10, 2));
    wl.setTime(Time(13, 30, 0));
    wl.setWindSpeed(15.0);
    wl.setSolarRad(300.0);
    wl.setAirTemp(30.0);

    // test getter methods after setting new values
    cout << "Date: " << wl.getDate() << endl;
    cout << "Time: " << wl.getTime() << endl;
    cout << "Wind Speed: " << wl.getWindSpeed() << endl;
    cout << "Solar Radiation: " << wl.getSolarRad() << endl;
    cout << "Air Temperature: " << wl.getAirTemp() << endl;

    // test overloading the << operator
    cout << "WindLog: " << wl << endl;

    // test overloading the >> operator
    WindLog wl2;
    cout << "Enter WindLog data (Date Time WindSpeed SolarRadiation AirTemperature): ";
    cin >> wl2;
    cout << "WindLog entered: " << wl2 << endl;

    return 0;
}