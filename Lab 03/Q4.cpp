#include <iostream>
using namespace std;

class Car {
private:
    char brand[30];
    char model[30];
    double fuelCapacity;
    double currentFuelLevel;
public:
    Car(char b[], char m[], double capacity) {
        int i = 0;
        while (b[i] != '\0') {
            brand[i] = b[i];
            i++;
        }
        brand[i] = '\0';
        i = 0;
        while (m[i] != '\0') {
            model[i] = m[i];
            i++;
        }
        model[i] = '\0';
        fuelCapacity = capacity;
        currentFuelLevel = capacity;  
    }
    void drive(double fuelUsed) {
        if (fuelUsed > currentFuelLevel) {
            cout << "Not enough fuel to drive!\n";
        } else {
            currentFuelLevel -= fuelUsed;
            cout << "Drove the car, fuel used: " << fuelUsed << " liters\n";
        }
    }
    void refuel(double fuelAdded) {
        if (currentFuelLevel + fuelAdded > fuelCapacity) {
            cout << "Fuel tank is full!\n";
            currentFuelLevel = fuelCapacity;
        } else {
            currentFuelLevel += fuelAdded;
            cout << "Refueled " << fuelAdded << " liters.\n";
        }
    }
    void checkFuelStatus() {
        cout << "Current fuel level: " << currentFuelLevel << " liters.\n";
        if (currentFuelLevel < (0.2 * fuelCapacity)) {
            cout << "Warning: Low fuel! Please refuel soon.\n";
        }
    }
};

int main() {
    char brand[] = "Civics";
    char model[] = "Mercedes";
    Car zoyaCar(brand, model, 50.0);
    zoyaCar.drive(15);
    zoyaCar.checkFuelStatus();
    zoyaCar.refuel(6);
    zoyaCar.checkFuelStatus();
    return 0;
}
