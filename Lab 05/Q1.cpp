#include <iostream>
#include <cstring> 
using namespace std;

class Apartment {
private:
    int id;
    string address;
    char* ownerName;  

public:
    Apartment(int aptID, string addr, char* owner) {
        id = aptID;
        address = addr;
        ownerName = new char[strlen(owner) + 1]; 
        strcpy(ownerName, owner); 
    }
    Apartment(Apartment &apt) {
        id = apt.id;
        address = apt.address;
        ownerName = apt.ownerName; 
    }
    void displayDetails() {
        cout << "Apartment ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Owner: " << ownerName << endl;
        cout << "----------------------------" << endl;
    }
    ~Apartment() {
        delete[] ownerName;
    }
};
int main() {
    char owner1[] = "John Doe";
    Apartment apt1(101, "123 Main Street", owner1);
    cout << "Original Apartment Details:\n";
    apt1.displayDetails();
    Apartment apt2 = apt1; 
    cout << "Copied Apartment Details (New Agent):\n";
    apt2.displayDetails();
    return 0;
}
