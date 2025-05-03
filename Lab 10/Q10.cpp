#include <iostream>
#include <fstream>

using namespace std;
int main() {
    ofstream create("data_records.txt");
    create << "Record 1\nRecord 2\nRecord 3\nRecord 4\n";
    create.close();

    ifstream in("data_records.txt");
    if (!in) {
        cerr << "File error" << endl;
        return 1;
    }

    const int offset = 18; 
    
    in.seekg(offset, ios::beg);

    char record[20];
    in.getline(record, sizeof(record));
    
    cout << "Third record: " << record << endl;
    cout << "Current position: " << in.tellg() << endl;
    in.close();
    return 0;
}