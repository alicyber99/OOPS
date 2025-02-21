#include <iostream>
using namespace std;

class Car {
private:
    string brand;
    string model;
    double rentalPrice;
    bool available;
public:
    Car() {
        brand = "Unknown";
        model = "Generic";
        rentalPrice = 0.0;
        available = true;
    }
    void rentCar() {
        if (available) {
            available = false;
            cout << "Car rented successfully!\n";
        } else {
            cout << "Car is already rented.\n";
        }
    }
    void display() {
        cout << "Brand: " << brand << ", Model: " << model << ", Price: $" << rentalPrice << ", Available: "<< (available ? "Yes" : "No") << "\n";
    }
};
int main() {
    Car car1; 
    car1.display();
    car1.rentCar(); 
    car1.display();
    car1.rentCar(); 
    return 0;
}
