#include <iostream>

using namespace std;
class InventoryManager;
class Car {
private:
    string model;
    double price;
public:
    Car(string m = "", double p = 0.0) {
        model = m;
        price = p;
    }
    friend class InventoryManager;
    friend void comparePrice(const Car& car1, const Car& car2);
};
class InventoryManager {
public:
    void updatePrice(Car& car, double newPrice) {
        car.price = newPrice;
    }
    void displayCar(const Car& car) {
        cout << "Model: " << car.model << ", Price: $" << car.price << endl;
    }
};
void comparePrice(const Car& car1, const Car& car2) {
    if (car1.price > car2.price) {
        cout << car1.model << " is more expensive." << endl;
    } else if (car2.price > car1.price) {
        cout << car2.model << " is more expensive." << endl;
    } else {
        cout << "Both cars are priced equally." << endl;
    }
}
int main() {
    Car car1("Sedan", 27000.0);
    Car car2("SUV", 39000.0);
    InventoryManager manager;
    cout << "Initial Car Details:" << endl;
    manager.displayCar(car1);
    manager.displayCar(car2);
    manager.updatePrice(car1, 43000.0);
    cout << "\nUpdated Car Details:" << endl;
    manager.displayCar(car1);
    manager.displayCar(car2);
    cout << "\nComparing Prices:" << endl;
    comparePrice(car1, car2);
    return 0;
}
