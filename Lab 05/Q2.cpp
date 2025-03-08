#include <iostream>
using namespace std;

class Student {
private:
    int id;       
    char* name;   
    int* scores;  
    int num_Scores; 
public:
    Student(int student_Id, char* student_Name, int student_Scores[], int score_Count) 
        : id(student_Id), num_Scores(score_Count) {
        int name_Length = 0;
        while (student_Name[name_Length] != '\0') {
            name_Length++;
        }
        name = new char[name_Length + 1]; 
        for (int i = 0; i <= name_Length; i++) {
            name[i] = student_Name[i];
        }
        scores = new int[num_Scores];
        for (int i = 0; i < num_Scores; i++) {
            scores[i] = student_Scores[i];
        }
    }
    Student(Student& other) {
        id = other.id;
        num_Scores = other.num_Scores;
        int name_Length = 0;
        while (other.name[name_Length] != '\0') {
            name_Length++;
        }
        name = new char[name_Length + 1]; 
        for (int i = 0; i <= name_Length; i++) {
            name[i] = other.name[i];
        }
        scores = new int[num_Scores];
        for (int i = 0; i < num_Scores; i++) {
            scores[i] = other.scores[i];
        }
    }
    void display() {
        cout << "Student ID: " << id << "\n";
        cout << "Name: " << name << "\n";
        cout << "Scores: ";
        for (int i = 0; i < num_Scores; i++) {
            cout << scores[i] << " ";
        }
        cout << "\n";
    }
    ~Student() {
        delete[] name;
        delete[] scores;
    }
};

int main() {
    int exam_Scores[] = {24, 89, 66}; 
    char student_Name[] = "Noor"; 
    Student student1(132, student_Name, exam_Scores, 5); 
    cout << "Original Student:\n";
    student1.display();
    Student student_Copy = student1;
    cout << "\nCopied Student:\n";
    student_Copy.display();
    return 0;
}
