#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inputFile("vehicles.txt");
    
    if (!inputFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    int totalCount = 0;
    int hybridCount = 0;
    int electricCount = 0;
    int autonomousCount = 0;

    while (std::getline(inputFile, line)) {
        if (line.empty() || line[0] == '#') continue;

        totalCount++;
        if (line.find("HybridTruck") == 0) {
            hybridCount++;
        } 
        else if (line.find("ElectricVehicle") == 0) {
            electricCount++;
        } 
        else if (line.find("AutonomousCar") == 0) {
            autonomousCount++;
        }
    }

    cout << "Total records: " << totalCount << endl;
    cout << "HybridTruck: " << hybridCount << " records" << endl;
    cout << "ElectricVehicle: " << electricCount << " records" << endl;
    cout << "AutonomousCar: " << autonomousCount << " records" << endl;

    inputFile.close();
    return 0;
}