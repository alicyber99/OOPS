#include <iostream>
#include <fstream>
#include <string>
#include <sstream>  
using namespace std;

int main() {
    ifstream inputFile("vehicles.txt");
    
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file 'vehicles.txt'" << endl;
        return 1;
    }
    
    string line;
    while (std::getline(inputFile, line)) {
        if (line.empty() || line[0] == '#') {
            continue; 
        }
        istringstream iss(line);
        
        string type, id, name, year, extradata, certification;
        
        getline(iss, type, ',');
        getline(iss, id, ',');
        getline(iss, name, ',');
        getline(iss, year, ',');
        getline(iss, extradata, ',');
        getline(iss, certification);  
        cout << "----------------------------\n";
        cout << "Type: " << type << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Year: " << year << endl;
        cout << "Extra Data: " << extradata << endl;
        cout << "Certification: " << certification << endl;
    }
    inputFile.close();
    return 0;
}