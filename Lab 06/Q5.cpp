#include <iostream>
using namespace std;

class Device {
public:
    int deviceID;
    bool status;
    Device(){
        deviceID = 0, status = false; 
    }
    Device(int dID, bool s) {
        deviceID = dID, status = s; 
    }
    void displayDetails() {
        cout << "Device-ID: " << deviceID << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
    }
};
class SmartPhone : public Device {
public:
    float screen_size;
    SmartPhone():Device(){
        screen_size = 0.0; 
    }
    SmartPhone(int dID, bool s, float SS) : Device(dID, s){
        screen_size = SS; 
    }
    void displayDetails() {
        Device::displayDetails();
        cout << "Screen-Size: " << screen_size << " inches" << endl;
    }
};
class SmartWatch : public SmartPhone{
public:
    bool heartRateMonitor;
    SmartWatch() : SmartPhone(){
        heartRateMonitor = false;
    }
    SmartWatch(int dID, bool s, float SS, bool hrm) : SmartPhone(dID, s, SS){
        heartRateMonitor = hrm;
    }
    void displayDetails() {
        SmartPhone::displayDetails();
        cout << "Heart-Rate Monitor: " << (heartRateMonitor ? "Enabled" : "Disabled") << endl;
    }
};

class SmartWearable : public SmartWatch {
public:
    int stepCounter;
    SmartWearable() : SmartWatch() {
        stepCounter = 0;
    }
    SmartWearable(int dID, bool s, float SS, bool hrm, int sP) : SmartWatch(dID, s, SS, hrm){
        stepCounter = sP;
    }
    void displayDetails() {
        SmartWatch::displayDetails();
        cout << "Step Counter: " << stepCounter << endl;
    }
};

int main() {
    SmartWearable sw1;
    cout << "Enter the Device-ID: ";
    cin >> sw1.deviceID;
    int statusInput;
    cout << "Enter the status (1 for true, 0 for false): ";
    cin >> statusInput;
    sw1.status = statusInput; 
    cout << "Enter the Screen-Size: ";
    cin >> sw1.screen_size;
    int hrmInput;
    cout << "Enter the heart-rate monitor status (1 for true, 0 for false): ";
    cin >> hrmInput;
    sw1.heartRateMonitor = hrmInput; 
    cout << "Enter the Step-Counter: ";
    cin >> sw1.stepCounter;
    cout << "\nSmart Wearable Details:\n";
    sw1.displayDetails();
    return 0;
}
