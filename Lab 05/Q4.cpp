#include <iostream>
using namespace std;
class AlarmSystem {
private:
    char* security_Level; 
public:
    AlarmSystem(char* level) {
        int len = 0;
        while (level[len] != '\0') {
            len++;
        }
        security_Level = new char[len + 1]; 
        for (int i = 0; i <= len; i++) {
            security_Level[i] = level[i]; 
        }
    }
    void display_Alarm() {
        cout << "Alarm Security Level: " << security_Level << "\n";
    }
    ~AlarmSystem() {
        delete[] security_Level;
    }
};
class SmartHome {
private:
    char* home_Name;   
    AlarmSystem alarm;
public:
    SmartHome(char* name, char* securityLevel) : alarm(securityLevel) {
        int len = 0;
        while (name[len] != '\0') {
            len++;
        }
        home_Name = new char[len + 1]; 
        for (int i = 0; i <= len; i++) {
            home_Name[i] = name[i]; 
        }
    }
    void display_SmartHome() {
        cout << "Smart Home Name: " << home_Name << "\n";
        alarm.display_Alarm();
    }
    ~SmartHome() {
        delete[] home_Name;
    }
};

int main() {
    SmartHome myHome("My Smart Home", "High");
    myHome.display_SmartHome();
    return 0;
}
