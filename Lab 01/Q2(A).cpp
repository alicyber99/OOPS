#include<iostream>

using namespace std;
int main(){
    const int cities = 4;
    const int days = 7;
    string cityNames[cities] = {"Lahore", "Karachi", "Dehli", "Dhaka"};
    int j = 0;
    int AQI[cities][days];
    for(int i = 0; i < cities; i++){
        cout << "Enter the AQI values for " << cityNames[i] << endl;
        for ( j = 0; j < 7; j++){
        cout << "Day " << j + 1 << ": ";
        cin >> AQI[i][j];
        }
    }

    int average[cities];
    for (int i = 0; i < cities; i++) {
        int sum = 0;
        for (int j = 0; j < days; j++) {
            sum += AQI[i][j];
        }
        average[i] = sum / days;
        cout << "Average AQI for " << cityNames[i] << " is " << average[i] << endl;
    }
    
    for (int i = 0; i < cities; i++) {
        cout << "AQI Levels for " << cityNames[i] << ":\n";
           for (int j = 0; j < days; j++) {
            cout << "Day " << j + 1 << ": ";
            for (int k = 0; k < AQI[i][j] / 50; k++) {
                cout << "*";
            }
            cout << " (" << AQI[i][j] << ")\n";
        }
    }

    cout << "\nCritical Pollution Days (AQI > 150):\n";
    for (int i = 0; i < cities; i++) {
        cout << cityNames[i] << ": ";
        for (int j = 0; j < days; j++) {
            if (AQI[i][j] > 150) {
                cout << "Day " << j + 1 << " ";
            }
        }
        cout << "\n";
    }
}