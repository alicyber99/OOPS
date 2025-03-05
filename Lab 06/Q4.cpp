#include<iostream>

using namespace std;
class Account{
    public:
        int account_number;
        float balance;
        Account(){
            account_number = 0;
            balance = 0.0;
        }
        Account(int a, float b){
            account_number = a;
            balance = b;
        }
        void displayDetails(){
            cout << "Account-Number: " << account_number << endl;
            cout << "Balance: " << balance << endl;
        }
};

class SavingAccount : public Account{
    public:
        float interest_Rate;
        SavingAccount():Account(){
            interest_Rate = 0.0;
        }
    SavingAccount(int a, float b, float iR):Account(a,b){
        interest_Rate = iR;
    }    
    void displayDetails(){
        Account::displayDetails();
        cout << "Interest-Rate: " << interest_Rate << endl;
    }
};

class CheckingAccount: public Account{
    public:
        float overdraft_Limit;
        CheckingAccount():Account(){
            overdraft_Limit = 0.0;
        }
        CheckingAccount(int a, float b,float oL):Account(a,b){
            overdraft_Limit = oL;
        }
        void displayDetails(){
            Account::displayDetails();
            cout << "Overdraft-Limit: " << overdraft_Limit << endl;
        }
};

int main(){
    SavingAccount sA1;
    CheckingAccount cA1;
    cout << "Saving Account\n";
    cout << "Enter Account-Number: ";
    cin >> sA1.account_number;
    cout << "Enter the balance: ";
    cin >> sA1.balance;
    cout << "Enter the interest-Rate: ";
    cin >> sA1.interest_Rate;
    cout << "\nChecking Account\n";
    cout << "Enter Account-Number: ";
    cin >> cA1.account_number;
    cout << "Enter the balance: ";
    cin >> cA1.balance;
    cout << "Enter the Overdraft-Limit: ";
    cin >> cA1.overdraft_Limit;
    cout << "\nSaving Account Details:\n";
    sA1.displayDetails();
    cout << "\nChecking Account Details:\n";
    cA1.displayDetails();
    return 0;
}