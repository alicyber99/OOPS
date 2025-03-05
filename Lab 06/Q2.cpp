#include<iostream>

using namespace std;
class Vehicle{
    public:
        string brand;
        int speed;
        Vehicle(){
            brand = " ";
            speed = 0;
        }
        Vehicle(string b, int s){
            brand = b;
            speed = s;
        }
        void displayDetails(){
            cout << "Brand: " << brand << endl;
            cout << "Speed: " << speed << endl;
        }
};

class Car : public Vehicle{
    public:
        int seats;
        Car():Vehicle(){
            seats = 0;
        }
    Car(string b, int s, int st):Vehicle(b,s){
        seats = st;
    }    
    void displayDetails(){
        Vehicle::displayDetails();
        cout << "Number of seats: " << seats << endl;
    }
};

class ElectricCar: public Car{
    public:
        int batteryLife;
        ElectricCar():Car(){
            batteryLife = 0;
        }
        ElectricCar(string b, int s, int st, int bl):Car(b,s,st){
            batteryLife = bl;
        }
        void displayDetails(){
            Car::displayDetails();
            cout << "Battery life: " << batteryLife << endl;
        }
};

int main(){
    ElectricCar ec;
    cout << "Enter Car's Brand: ";
    cin >> ec.brand;
    cout << "Enter Car's Speed: ";
    cin >> ec.speed;
    cout << "Enter Car's Seats: ";
    cin >> ec.seats;
    cout << "Enter Car's Battery Life: ";
    cin >> ec.batteryLife;
    ec.displayDetails();
    return 0;
}