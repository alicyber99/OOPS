#include <iostream>
using namespace std;

class Course {
protected:
    string courseCode;
    int credits;
public:
    Course(string code = "", int cred = 0) {
        courseCode = code;
        credits = cred;
    }
    virtual float calculateGrade() = 0; 
    virtual void displayInfo() = 0;     
};
class LectureCourse : public Course {
private:
    float midterm;
    float finalExam;
public:
    LectureCourse(string code, int cred, float mid, float finalEx)
        : Course(code, cred) {
        midterm = mid;
        finalExam = finalEx;
    }
    float calculateGrade() override {
        return (midterm * 0.4f + finalExam * 0.6f); 
    }
    void displayInfo() override {
        cout << "Lecture Course: " << courseCode << endl;
        cout << "Credits: " << credits << endl;
        cout << "Final Grade: " << calculateGrade() << endl;
    }
};
class LabCourse : public Course {
private:
    float labPerformance;
    float labExam;
public:
    LabCourse(string code, int cred, float perf, float labEx)
        : Course(code, cred) {
        labPerformance = perf;
        labExam = labEx;
    }
    float calculateGrade() override {
        return (labPerformance * 0.5f + labExam * 0.5f); 
    }
    void displayInfo() override {
        cout << "Lab Course: " << courseCode << endl;
        cout << "Credits: " << credits << endl;
        cout << "Final Grade: " << calculateGrade() << endl;
    }
};
int main() {
    Course* course1 = new LectureCourse("CS1010", 2, 85, 95);
    Course* course2 = new LabCourse("CS1013", 5, 80, 60);
    course1->displayInfo();
    cout << endl;
    course2->displayInfo();
    delete course1;
    delete course2;
    return 0;
}
