#include <iostream>
using namespace std;

class Wallet{
private:
    char Name[50];  
    double Balance;
    char transaction_History[10][30];  
    int transaction_Count;

public:
    Wallet(char name[], double balance) {
        int i = 0;
        while (name[i] != '\0') {
            Name[i] = name[i];
            i++;
        }
        Name[i] = '\0';  
        Balance = balance;
        transaction_Count = 0;
    }
    void addMoney(double amount) {
        Balance += amount;
        if (transaction_Count < 10) {
            sprintf(transaction_History[transaction_Count], "Added %.2f", amount); 
            transaction_Count++;
        }
    }
    void spendMoney(double amount) {
        if (amount > Balance) {
            cout << "Insufficient balance!\n";
        } else {
            Balance -= amount;
            if (transaction_Count < 10) {
                sprintf(transaction_History[transaction_Count], "Spent %.2f", amount);
                transaction_Count++;
            }
        }
    }
    void displayTransactions() {
        cout << "Transaction History for " << Name << ":\n";
        for (int i = 0; i < transaction_Count; i++) {
            cout << transaction_History[i] << endl;
        }
        cout << "Current Balance: " << Balance << endl;
    }
};
int main() {
    Wallet saadWallet("Saad", 1000.00);
    saadWallet.addMoney(500.00);
    saadWallet.spendMoney(300.00);
    saadWallet.displayTransactions();
    return 0;
}
