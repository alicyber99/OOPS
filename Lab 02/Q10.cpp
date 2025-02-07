#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    cout << "Enter dimensions of the 3D array: ";
    cin >> x >> y >> z;
    int*** arr = new int**[x];
    for (int i = 0; i < x; i++) {
        arr[i] = new int*[y];
        for (int j = 0; j < y; j++) {
            arr[i][j] = new int[z];
        }
    }
    cout << "Enter values:\n";
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            for (int k = 0; k < z; k++)
                cin >> arr[i][j][k];
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++)
            delete[] arr[i][j];
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
