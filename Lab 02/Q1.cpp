#include <iostream>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    int year;
};

int main() {
    int numBooks;
    cout << "Enter the number of books: ";
    cin >> numBooks;
    cin.ignore(); 
    Book* books = new Book[numBooks];
    for (int i = 0; i < numBooks; i++) {
        cout << "Enter details for book " << i + 1 << ":\n";
        cout << "Title: ";
        getline(cin, books[i].title);
        cout << "Author: ";
        getline(cin, books[i].author);
        cout << "Year: ";
        cin >> books[i].year;
        cin.ignore(); 
    }
    int filterYear;
    cout << "Enter a year to display books published after: ";
    cin >> filterYear;
    cout << "\nBooks published after " << filterYear << ":\n";
    for (int i = 0; i < numBooks; i++) {
        if (books[i].year > filterYear) {
            cout << "Title: " << books[i].title << ", Author: " << books[i].author << ", Year: " << books[i].year << endl;
        }
    }
    delete[] books;
    return 0;
}
