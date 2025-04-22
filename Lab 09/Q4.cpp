#include <iostream>
using namespace std;

class WeatherSensor {
public:
    virtual void readData() = 0;       
    virtual void displayReport() = 0;  
};
class Thermometer : public WeatherSensor {
private:
    float temperature;
public:
    void readData() override {
        temperature = 22;  
    }
    void displayReport() override {
        cout << "Thermometer Reading: " << temperature << " °C" << endl;
    }
};
class Barometer : public WeatherSensor {
private:
    float pressure;
public:
    void readData() override {
        pressure = 1021;
    }
    void displayReport() override {
        cout << "Barometer Reading: " << pressure << " hPa" << endl;
    }
};
int main() {
    WeatherSensor* sensor1 = new Thermometer();
    WeatherSensor* sensor2 = new Barometer();
    sensor1->readData();
    sensor1->displayReport();
    cout << endl;
    sensor2->readData();
    sensor2->displayReport();
    delete sensor1;
    delete sensor2;
    return 0;
}
