#include <iostream>
using namespace std;

class Library {
private:
    char bookList[10][50];  
    char borrowedBooks[10][50];
    char availableBooks[10][50];
    int bookCount, borrowedCount, availableCount;

public:
    Library() {
        bookCount = 0;
        borrowedCount = 0;
        availableCount = 0;
    }
    void addBook(char book[]) {
        int i = 0;
        while (book[i] != '\0') {
            bookList[bookCount][i] = book[i];
            availableBooks[availableCount][i] = book[i];
            i++;
        }
        bookList[bookCount][i] = '\0';
        availableBooks[availableCount][i] = '\0';
        bookCount++;
        availableCount++;
    }
    void borrowBook(const char book[]) {
        for (int i = 0; i < availableCount; i++) {
            int j = 0;
            while (availableBooks[i][j] == book[j] && book[j] != '\0') j++;
            if (book[j] == '\0' && availableBooks[i][j] == '\0') { 
                int k = 0;
                while (book[k] != '\0') {
                    borrowedBooks[borrowedCount][k] = book[k];
                    k++;
                }
                borrowedBooks[borrowedCount][k] = '\0';
                borrowedCount++;

                for (int m = i; m < availableCount - 1; m++) {
                    for (int n = 0; availableBooks[m][n] != '\0'; n++) {
                        availableBooks[m][n] = availableBooks[m + 1][n];
                    }
                }
                availableCount--;
                cout << book << " borrowed successfully!\n";
                return;
            }
        }
        cout << book << " is not available!\n";
    }
    void returnBook(const char book[]) {
        for (int i = 0; i < borrowedCount; i++) {
            int j = 0;
            while (borrowedBooks[i][j] == book[j] && book[j] != '\0') j++;
            if (book[j] == '\0' && borrowedBooks[i][j] == '\0') { 
                int k = 0;
                while (book[k] != '\0') {
                    availableBooks[availableCount][k] = book[k];
                    k++;
                }
                availableBooks[availableCount][k] = '\0';
                availableCount++;

                for (int m = i; m < borrowedCount - 1; m++) {
                    for (int n = 0; borrowedBooks[m][n] != '\0'; n++) {
                        borrowedBooks[m][n] = borrowedBooks[m + 1][n];
                    }
                }
                borrowedCount--;
                cout << book << " returned successfully!\n";
                return;
            }
        }
        cout << book << " was not borrowed!\n";
    }
    void displayLibrary() {
        cout << "\nLibrary Inventory:\n";
        cout << "Available Books: ";
        for (int i = 0; i < availableCount; i++) {
            cout << availableBooks[i] << ", ";
        }
        cout << "\nBorrowed Books: ";
        for (int i = 0; i < borrowedCount; i++) {
            cout << borrowedBooks[i] << ", ";
        }
        cout << endl;
    }
};
int main() {
    Library hamzaLibrary;
    hamzaLibrary.addBook("Java Programming");
    hamzaLibrary.addBook("Data Structures");
    hamzaLibrary.borrowBook("Java Programming");
    hamzaLibrary.returnBook("Java Programming");
    hamzaLibrary.displayLibrary();
    return 0;
}
