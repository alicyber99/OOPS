#include <iostream>
using namespace std;

class Car {
private:
    string brand;
    string model;
    double rentalPrice;
    bool available;
public:
    Car(string b, string m, double price) 
        : brand(b), model(m), rentalPrice(price), available(true) {}
    Car(const Car &c) {
        brand = c.brand;
        model = c.model;
        rentalPrice = c.rentalPrice;
        available = c.available;
    }
    ~Car() {
        cout << "Destructor Called: Car " << brand << " " << model << " removed from memory.\n";
    }
    void display() {
        cout << "Brand: " << brand << ", Model: " << model
                  << ", Price: Rs. " << rentalPrice << ", Available: "
                  << (available ? "Yes" : "No") << "\n";
    }
    void updateDetails(string b, string m, double price) {
        brand = b;
        model = m;
        rentalPrice = price;
    }
};
int main() {
    Car car1("Toyota", "Corolla", 40.0);  
    Car car2 = car1; 
    std::cout << "Original Car Details:\n";
    car1.display();
    std::cout << "\nCopied Car Details:\n";
    car2.display();
    car1.updateDetails("Honda", "Civic", 60.0);
    cout << "\nAfter Modifying Original Car:\n";
    car1.display();
    car2.display();
    return 0;  
}
