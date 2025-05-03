#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    ifstream inputFile("vehicles.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        if (line.empty() || line[0] == '#') continue;

        istringstream iss(line);
        string type, id, name, yearStr, extradata, cert;
        
        getline(iss, type, ',');
        getline(iss, id, ',');
        getline(iss, name, ',');
        getline(iss, yearStr, ',');
        getline(iss, extradata, ',');
        getline(iss, cert);

        int year = 0;
        try {
            year = stoi(yearStr);
        } catch (...) {
            cerr << "Invalid year in record: " << line << endl;
        }
        cout << "\nType: " << type
                  << "\nID: " << id
                  << "\nName: " << name
                  << "\nYear: " << year
                  << "\nExtra: " << extradata
                  << "\nCert: " << cert << endl;
    }
    inputFile.close();
    return 0;
}