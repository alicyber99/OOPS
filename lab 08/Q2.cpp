#include <iostream>
using namespace std;

class Account;
bool transferFunds(Account& from, Account& to, double amount);
class Account {
private:
    int accountNumber;
    double balance;
public:
    Account(int accNum = 0, double bal = 0.0) {
        accountNumber = accNum;
        balance = bal;
    }
    friend class Manager;
    friend bool transferFunds(Account& from, Account& to, double amount);
};
class Manager {
public:
    void displayAccount(const Account& acc) {
        cout << "Account Number: " << acc.accountNumber << ", Balance: $" << acc.balance << endl;
    }
    void deposit(Account& acc, double amount) {
        if (amount > 0) {
            acc.balance += amount;
            cout << "Deposited $" << amount << " to Account " << acc.accountNumber << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }
    void withdraw(Account& acc, double amount) {
        if (amount > 0 && acc.balance >= amount) {
            acc.balance -= amount;
            cout << "Withdrew $" << amount << " from Account " << acc.accountNumber << endl;
        } else {
            cout << "Invalid or insufficient balance for withdrawal!" << endl;
        }
    }
};
bool transferFunds(Account& from, Account& to, double amount) {
    if (amount > 0 && from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        cout << "Transferred $" << amount << " from Account " << from.accountNumber
             << " to Account " << to.accountNumber << endl;
        return true;
    } else {
        cout << "Transfer failed: Insufficient balance or invalid amount!" << endl;
        return false;
    }
}
int main() {
    Account acc1(103, 700.0);
    Account acc2(1002, 900.0);
    Manager mgr;
    cout << "Initial Account Details:" << endl;
    mgr.displayAccount(acc1);
    mgr.displayAccount(acc2);
    mgr.deposit(acc1, 500.0);
    mgr.withdraw(acc2, 400.0);
    transferFunds(acc1, acc2, 150.0);
    cout << "\nFinal Account Details:" << endl;
    mgr.displayAccount(acc1);
    mgr.displayAccount(acc2);
    return 0;
}
