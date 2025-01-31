#include <iostream>
using namespace std;

int main() {
    const int cities = 4;
    const int days = 28;
    const int weeks = 4;
    int AQI[cities][days];
    
    string cityNames[cities] = {"Lahore", "Delhi", "Karachi", "Dhaka"};
    int average[cities];
    int weeklyAvg[cities][weeks];
    int minAQI[cities], maxAQI[cities], criticalDays[cities];
    int most_improvement_city = 0;
    int max_improvement = 0;
    for(int i = 0; i < cities; i++){
        cout << "Enter the AQI values for " << cityNames[i] << endl;
        for (int j = 0; j < 28; j++){
        cout << "Day " << j + 1 << ": ";
        cin >> AQI[i][j];
        }
    }
    for (int i = 0; i < cities; i++) {
        int sum = 0;
        minAQI[i] = AQI[i][0];
        maxAQI[i] = AQI[i][0];
        criticalDays[i] = 0;

        for (int j = 0; j < days; j++) {
            sum += AQI[i][j];
            if (AQI[i][j] < minAQI[i]) minAQI[i] = AQI[i][j];
            if (AQI[i][j] > maxAQI[i]) maxAQI[i] = AQI[i][j];
            if (AQI[i][j] > 150) criticalDays[i]++;
            if (j % 7 == 6) {
                weeklyAvg[i][j / 7] = sum / 7;
                sum = 0;
            }
        }
        
        average[i] = sum / days;
        int improvement = weeklyAvg[i][0] - weeklyAvg[i][weeks - 1];
        if (improvement > max_improvement) {
            max_improvement = improvement;
            most_improvement_city = i;
        }
    }

    for (int i = 0; i < cities; i++) {
        cout << "Average AQI for " << cityNames[i] << " is " << average[i] << endl;
        cout << "Weekly averages: ";
        for (int w = 0; w < weeks; w++) {
            cout << weeklyAvg[i][w] << " ";
        }
        cout << endl;
        cout << "Critical pollution days (> 150 AQI): " << criticalDays[i] << endl;
        cout << "Highest AQI: " << maxAQI[i] << ", Lowest AQI: " << minAQI[i] << endl;
        cout << "---------------------------------" << endl;
    }
    
    cout << "City with the most improved air quality: " << cityNames[most_improvement_city] << " with " << max_improvement << " decrease in AQI." << endl;
    return 0;
}