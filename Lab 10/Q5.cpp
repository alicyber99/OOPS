#include <iostream>
#include <cstring>  
#include <cstdlib>   
using namespace std;

void parseHybridTruck(const char* extradata) {
    char buffer[100];
    int cargo, battery;
    
    const char* cargoStart = strstr(extradata, "Cargo:");
    if (cargoStart) {
        cargoStart += 6; 
        const char* pipePos = strchr(cargoStart, '|');
        if (pipePos) {
            int cargoLen = pipePos - cargoStart;
            strncpy(buffer, cargoStart, cargoLen);
            buffer[cargoLen] = '\0';
            cargo = atoi(buffer);
            const char* batteryStart = strstr(pipePos, "Battery:");
            if (batteryStart) {
                batteryStart += 8; 
                battery = atoi(batteryStart);
                
                cout << "Cargo: " << cargo << ", Battery: " << battery << endl;
                return;
            }
        }
    }
    cerr << "Error: Invalid HybridTruck format" <<  endl;
}

int main() {
    const char* example1 = "Cargo:5000|Battery:75";
    const char* example2 = "Cargo:3000|Battery:50";
    
    cout << "Parsing first example: ";
    parseHybridTruck(example1);
    
    cout << "Parsing second example: ";
    parseHybridTruck(example2);
    
    return 0;
}