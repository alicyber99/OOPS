#include <iostream>
using namespace std;

struct Employee {
    string name;
    double hoursWorked;
    double hourlyRate;
};
int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;
    Employee* employees = new Employee[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter details for employee " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> employees[i].name;
        cout << "Hours Worked: ";
        cin >> employees[i].hoursWorked;
        cout << "Hourly Rate: ";
        cin >> employees[i].hourlyRate;
    }
    cout << "\nEmployee Salaries:\n";
    for (int i = 0; i < n; i++) {
        double totalSalary = employees[i].hoursWorked * employees[i].hourlyRate;
        cout << employees[i].name << " - Total Salary: $" << totalSalary << endl;
    }
    delete[] employees;
    return 0;
}
