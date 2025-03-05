#include<iostream>
using namespace std;

class Person{
   public:
       string name;
       int age;
    Person(){
        name = " ";
        age = 0;
    }
    Person(string n, int a){
        name = n;
        age = a;
    } 
    void displayDetails(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};
class Teacher:public Person{
    public:
       string subject;
    Teacher(){
        subject = " ";
    }
    Teacher(string n,int a,string s):Person(n,a){
        subject = s;
    }
    void displayDetails(){
        Person::displayDetails();
        cout << "Subject: " << subject << endl;
    }
};
class Researchar:public Teacher{
    public:
        string research_Area;
    Researchar(){
        research_Area = " ";
    }    
    Researchar(string n,int a,string s,string rA):Teacher(n,a,s){
        research_Area = rA;
    }
    void displayDetails(){
        Teacher::displayDetails();
        cout <<"Research-Area: " << research_Area << endl;
    }
};
class Professor:public Researchar{
    public:
        int publication;
    Professor(){
        publication = 0;
    }    
    Professor(string n,int a,string s,string rA,int p):Researchar(n,a,s,rA){
        publication = p;
    }
    void displayDetails(){
        Researchar::displayDetails();
        cout << "Publication-Year: " << publication << endl;
    }
};

int main(){
    Professor p1;
    cout << "Enter your name: ";
    cin >> p1.name;
    cout << "Enter your age: ";
    cin >> p1.age;
    cout << "Enter your subject: ";
    cin >> p1.subject;
    cout << "Enter the Researcher-Area: ";
    cin >> p1.research_Area;
    cout << "Enter the Publication-Year: ";
    cin >> p1.publication;
    p1.displayDetails();
    return 0;
}