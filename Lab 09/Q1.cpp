#include <iostream>
using namespace std;

class Patient {
protected:
    string name;
    string id;
public:
    Patient(string name, string id) {
        this->name = name;
        this->id = id;
    }
    virtual void displayTreatment() = 0;
    virtual int calculateCost() = 0;
};
class InPatient : public Patient {
public:
    InPatient(string name, string id) : Patient(name, id) {}
    void displayTreatment() {
        cout << "InPatient Treatment for " << name << " (ID: " << id << ")\n";
        cout << "Treatment: Admitted to ward, surgery, medication\n";
    }
    int calculateCost() {
        int roomCost = 1000;
        int surgeryCost = 10000;
        int medicationCost = 1000;
        int total = roomCost + surgeryCost + medicationCost;
        cout << "Total Cost for InPatient: " << total << "\n";
        return total;
    }
};
class OutPatient : public Patient {
public:
    OutPatient(string name, string id) : Patient(name, id) {}
    void displayTreatment() {
        cout << "OutPatient Treatment for " << name << " ID: " << id << "\n";
        cout << "Treatment:  medication\n";
    }
    int calculateCost() {
        int consultationCost = 1500;
        int medicationCost = 1000;
        int total = consultationCost + medicationCost;
        cout << "Total Cost for OutPatient: " << total << "\n";
        return total;
    }
};
int main() {
    Patient* p1 = new InPatient("Arslan", "IP013");
    Patient* p2 = new OutPatient("Nimra", "OP123");
    p1->displayTreatment();
    p1->calculateCost();
    cout << "\n";
    p2->displayTreatment();
    p2->calculateCost();
    delete p1;
    delete p2;
    return 0;
}
