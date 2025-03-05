#include<iostream>
using namespace std;

class Employee
{
    public:
       string name;
       float salary;

       Employee(){
            name = " ";
            salary = 0.0;
       }
       Employee(string n, float s)
       {
           name = n;
           salary = s;
       }
       void displayDetails(){
              cout<<"Name: "<<name<<endl;
              cout<<"Salary: "<<salary<<endl;
       }
};    
class Manager: public Employee{
    public:
        float bonus;
        Manager():Employee(){
            bonus = 0.0;
        }
        Manager(string n, float s, float b):Employee(n,s){
            bonus = b;
        }
    void displayDetails(){
        Employee::displayDetails();
        cout << "Bonus: " << bonus << endl;
    }
};
int main(){
    Manager m1;
    cout << "Enter Manager's Name: ";  
    cin >> m1.name;
    cout << "Enter Salary: ";
    cin >> m1.salary;
    cout << "Enter Bonus: ";
    cin >> m1.bonus;
    m1.displayDetails();
    return 0;
}
