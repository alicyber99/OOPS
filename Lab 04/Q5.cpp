#include <iostream>
using namespace std;

class Car {
private:
    string regNumber;  
    string brand;
    string model;
    double rentalPrice;
    bool available;
    double revenue;
public:
    Car(string reg, string b, string m, double price)
        : regNumber(reg), brand(b), model(m), rentalPrice(price), available(true), revenue(0.0) {}
    void rentCar(int days) {
        if (!available) {
            cout << "Car " << regNumber << " is already rented.\n";
            return;
        }
        double totalPrice = rentalPrice * days;
        revenue += totalPrice; 
        available = false;
        cout << "Car " << regNumber << " rented for " << days << " days. Total cost: $" << totalPrice << "\n";
    }
    void displayDetails() {
        cout << "\nCar ID: " << regNumber << "\nBrand: " << brand<< "\nModel: " << model<< "\nRental Price: $" << rentalPrice << " per day"<< "\nTotal Revenue: $" << revenue<< "\nAvailable: " << (available ? "Yes" : "No") << "\n";
    }
};
int main() {
    Car car1("ABC123", "Toyota", "Camry", 55.0);
    Car car2("XYZ456", "Honda", "Civic", 68.0);
    car1.displayDetails();
    car2.displayDetails();
    car1.rentCar(8);  
    car2.rentCar(4); 
    car1.displayDetails();
    car2.displayDetails();
    return 0;
}
