#include <iostream>
using namespace std;

class Employee {
public:
    char* name;
    char* designation;
    Employee(char* empName, char* empDesignation) {
        int name_Length = 0;
        while (empName[name_Length] != '\0') name_Length++;
        name = new char[name_Length + 1];
        for (int i = 0; i <= name_Length; i++) name[i] = empName[i];

        int designation_Length = 0;
        while (empDesignation[designation_Length] != '\0') designation_Length++;
        designation = new char[designation_Length + 1];
        for (int i = 0; i <= designation_Length; i++) designation[i] = empDesignation[i];
    }
    ~Employee() {
        delete[] name;
        delete[] designation;
    }
};

class Project {
public:
    char* title;
    char* deadline;
    Employee** employees;
    int employee_Count;

    Project(char* projTitle, char* projDeadline) {
        int title_Length = 0;
        while (projTitle[title_Length] != '\0') title_Length++;
        title = new char[title_Length + 1];
        for (int i = 0; i <= title_Length; i++) title[i] = projTitle[i];

        int deadline_Length = 0;
        while (projDeadline[deadline_Length] != '\0') deadline_Length++;
        deadline = new char[deadline_Length + 1];
        for (int i = 0; i <= deadline_Length; i++) deadline[i] = projDeadline[i];
        employees = new Employee*[10]; 
        employee_Count = 0;
    }
    void add_Employee(Employee* emp) {
        if (employee_Count < 10) {
            employees[employee_Count] = emp;
            employee_Count++;
        }
    }
    void display_ProjectDetails() {
        cout << "Project Title: " << title << "\n";
        cout << "Deadline: " << deadline << "\n";
        cout << "Assigned Employees:\n";
        for (int i = 0; i < employee_Count; i++) {
            cout << "- " << employees[i]->name << " (" << employees[i]->designation << ")\n";
        }
        cout << "\n";
    }
    ~Project() {
        delete[] title;
        delete[] deadline;
        delete[] employees;
    }
};
int main() {
    Employee emp1("Akbar", "Developer");
    Employee emp2("Arslan", "Designer");
    Project proj1("Website Revamp", "2025-07-29");
    proj1.add_Employee(&emp1);
    proj1.add_Employee(&emp2);
    proj1.display_ProjectDetails();
    return 0;
}
