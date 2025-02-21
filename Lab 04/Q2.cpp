#include <iostream>
using namespace std;

class Car {
private:
    string brand;
    string model;
    double rentalPrice;
    bool available;
public:
    Car(string b,string m, double price) {
        brand = b;
        model = m;
        rentalPrice = price;
        available = true;
    }
    void rentCar(int days) {
        if (!available) {
            cout << "Car is already rented.\n";
            return;
        }
        double totalPrice = rentalPrice * days;
        if (days > 10) {
            totalPrice *= 0.90; 
        } else if (days > 5) {
            totalPrice *= 0.95;
        }
        cout << "Car rented for " << days << " days. Total cost: Rs. " << totalPrice << "\n";
        available = false;
    }
    void display() {
        cout << "Brand: " << brand << ", Model: " << model << ", Price per day: Rs. " << rentalPrice << ", Available: "<< (available ? "Yes" : "No") << "\n";
    }
};
int main() {
    Car car2("Toyota", "Corolla", 50.0);
    car2.display();
    car2.rentCar(7); 
    car2.display();
    car2.rentCar(3);
    return 0;
}
