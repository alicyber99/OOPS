#include <iostream>
using namespace std;

struct Student {
    string name;
    int rollNumber;
    int marks[3];
};

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    Student* students = new Student[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Roll Number: ";
        cin >> students[i].rollNumber;
        cout << "Enter 3 subject marks: ";
        for (int j = 0; j < 3; j++) {
            cin >> students[i].marks[j];
        }
    }
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += students[i].marks[j];
        }
        float avg = sum / 3.0;
        cout << students[i].name << " (Roll No: " << students[i].rollNumber << ") - Average Marks: " << avg << endl;
    }
    delete[] students;
    return 0;
}
