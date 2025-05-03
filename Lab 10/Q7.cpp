#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("sensor_log.txt");
    
    outFile << "Sensor 1: 25.5 C\n";
    cout << "Position after first write: " << outFile.tellp() << endl;
    
    outFile << "Sensor 2: 98.1 MBH\n";
    cout << "Position after second write: " << outFile.tellp() << endl;
    
    outFile.close();
    return 0;
}