#include <iostream>
using namespace std;
class Device {
protected:
    int deviceID;
    char deviceName[50];
    bool status;
    char location[50];
public:
    Device(int id, const char* name, const char* loc) {
        deviceID = id;
        status = false;
        strCopy(deviceName, name);
        strCopy(location, loc);
    }
    void strCopy(char* dest, const char* src) {
        while (*src) {
            *dest++ = *src++;
        }
        *dest = '\0';
    }
    virtual void turnOn() { status = true; cout << deviceName << " is now ON.\n"; }
    virtual void turnOff() { status = false; cout << deviceName << " is now OFF.\n"; }
    virtual void getStatus() {
        cout << deviceName << " is " << (status ? "ON" : "OFF") << ".\n";
    }
    virtual void displayInfo() {
        cout << "Device: " << deviceName << " (ID: " << deviceID << ")\n";
    }
    virtual ~Device() {}  
};
class Light : public Device {
private:
    int brightnessLevel;
    char colorMode[20];
public:
    Light(int id, const char* name, const char* loc, int brightness, const char* color)
        : Device(id, name, loc) {
        brightnessLevel = brightness;
        strCopy(colorMode, color);
    }
    void displayInfo() override {
        cout << "Light Info - ID: " << deviceID
             << ", Name: " << deviceName
             << ", Brightness: " << brightnessLevel
             << ", Color Mode: " << colorMode << "\n";
    }
};
class Thermostat : public Device {
private:
    float temperature;
    char mode[10]; 
    float targetTemperature;
public:
    Thermostat(int id, const char* name, const char* loc, float temp, const char* m, float target)
        : Device(id, name, loc) {
        temperature = temp;
        targetTemperature = target;
        strCopy(mode, m);
    }
    void getStatus() override {
        cout << deviceName << " - Mode: " << mode
             << ", Current Temp: " << temperature
             << "°C, Target Temp: " << targetTemperature << "°C\n";
    }
};
class SecurityCamera : public Device {
private:
    int resolution;
    bool recording;
    bool nightVisionEnabled;
public:
    SecurityCamera(int id, const char* name, const char* loc, int res, bool nightVision)
        : Device(id, name, loc) {
        resolution = res;
        recording = false;
        nightVisionEnabled = nightVision;
    }
    void turnOn() override {
        Device::turnOn();
        recording = true;
        cout << deviceName << " started recording.\n";
    }
    void turnOff() override {
        Device::turnOff();
        recording = false;
        cout << deviceName << " stopped recording.\n";
    }
};
class SmartPlug : public Device {
private:
    float powerConsumption;
    int timerSetting;
public:
    SmartPlug(int id, const char* name, const char* loc, float power, int timer)
        : Device(id, name, loc) {
        powerConsumption = power;
        timerSetting = timer;
    }
    void turnOff() override {
        Device::turnOff();
        cout << deviceName << " is OFF. Power consumption: " << powerConsumption << "W\n";
    }
};
int main() {
    Light livingRoomLight(1, "Living Room Light", "Living Room", 80, "Warm White");
    Thermostat homeThermostat(2, "Home Thermostat", "Hallway", 26.5, "cooling", 20.0);
    SecurityCamera frontDoorCam(3, "End Door Camera", "Entrance", 1000, true);
    SmartPlug coffeeMakerPlug(4, "Coffee Maker Plug", "Kitchen", 1200.0, 34);
    Device* devices[] = {&livingRoomLight, &homeThermostat, &frontDoorCam, &coffeeMakerPlug};
    cout << "\n--- Device Information ---\n";
    for (Device* d : devices) {
        d->displayInfo();
        d->turnOn();
        d->getStatus();
        cout << "----------------------------\n";
    }
    cout << "\n--- Turning Off Devices ---\n";
    for (Device* d : devices) {
        d->turnOff();
    }
    return 0;
}
