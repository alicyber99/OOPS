#include <iostream>
using namespace std;

class Doctor {
public:
    char* name;
    char* specialization;
    int experience;
    Doctor(char* docName, char* docSpecialization, int docExperience) {
        int i = 0;
        while (docName[i] != '\0') i++;
        name = new char[i + 1];
        for (int j = 0; j <= i; j++) name[j] = docName[j];
        i = 0;
        while (docSpecialization[i] != '\0') i++;
        specialization = new char[i + 1];
        for (int j = 0; j <= i; j++) specialization[j] = docSpecialization[j];
        experience = docExperience;
    }
    void display() {
        std::cout << name << " | " << specialization << " | " << experience << " years\n";
    }
    ~Doctor() {
        delete[] name;
        delete[] specialization;
    }
};
class Hospital {
public:
    char* name;
    Doctor* doctors[5]; 
    int count;
    Hospital(char* hospName) {
        int i = 0;
        while (hospName[i] != '\0') i++;
        name = new char[i + 1];
        for (int j = 0; j <= i; j++) name[j] = hospName[j];
        count = 0;
    }
    void add_Doctor(Doctor* doc) {
        if (count < 5) doctors[count++] = doc;
    }
    void display() {
        cout << "Hospital: " << name << "\nDoctors:\n";
        for (int i = 0; i < count; i++) {
            doctors[i]->display();
        }
    }
    ~Hospital() {
        delete[] name;
    }
};
int main() {
    Doctor d1("AKbar", "Cardiology", 9);
    Doctor d2("Arslan", "Neurology", 9);
    Hospital h("Dow Hospital");
    h.add_Doctor(&d1);
    h.add_Doctor(&d2);
    h.display();
    return 0;
}
