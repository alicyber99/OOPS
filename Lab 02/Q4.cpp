#include <iostream>
using namespace std;

void swapStrings(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}
void bubbleSort(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { 
                swapStrings(arr[j], arr[j + 1]);
            }
        }
    }
}
int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    string* strArray = new string[n];
    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> strArray[i];
    }
    bubbleSort(strArray, n);
    cout << "\nSorted Strings:\n";
    for (int i = 0; i < n; i++) {
        cout << strArray[i] << endl;
    }
    delete[] strArray;
    return 0;
}
