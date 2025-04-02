#include <iostream>
using namespace std;

// Base class: Person
class Person {
public:
    string name;
    int age;
    string contactNumber;

    void displayInfo() {
        cout << "Name: " << name << "\nAge: " << age << "\nContact: " << contactNumber << "\n";
    }
};

// Derived class: Patient
class Patient : public Person {
public:
    string patientID;
    string medicalHistory;
    string doctorAssigned;

    void displayInfo() {
        Person::displayInfo();
        cout << "Patient ID: " << patientID << "\nMedical History: " << medicalHistory << "\nDoctor Assigned: " << doctorAssigned << "\n";
    }
};

// Derived class: Doctor
class Doctor : public Person {
public:
    string specialization;
    double consultationFee;
    string patientsList;

    void displayInfo() {
        Person::displayInfo();
        cout << "Specialization: " << specialization << "\nConsultation Fee: " << consultationFee << "\nPatients List: " << patientsList << "\n";
    }
};

// Derived class: Nurse
class Nurse : public Person {
public:
    string assignedWard;
    string shiftTimings;

    void displayInfo() {
        Person::displayInfo();
        cout << "Assigned Ward: " << assignedWard << "\nShift Timings: " << shiftTimings << "\n";
    }
};

// Derived class: Administrator
class Administrator : public Person {
public:
    string department;
    double salary;

    void updateInfo() {
        cout << "Administrator Info Updated: " << name << " from " << department << " department." << "\n";
    }
};

int main() {
    Patient patient;
    patient.name = "Akbar";
    patient.age = 37;
    patient.contactNumber = "0293829843";
    patient.patientID = "p9012";
    patient.medicalHistory = "Diabetes";
    patient.doctorAssigned = "Dr. Noor";
    patient.displayInfo();

    Doctor doctor;
    doctor.name = "Dr. Noor";
    doctor.age = 24;
    doctor.contactNumber = "86382744";
    doctor.specialization = "Cardiology";
    doctor.consultationFee = 90.0;
    doctor.patientsList = "Arslan, Ali";
    doctor.displayInfo();
    return 0;
}
