#include <iostream>
#include <fstream>
using namespace std;

int main() {
    
    ofstream create("large_log.txt");
    create << "Line 1\nLine 2\nLine 3\n";
    create.close();

    ifstream in("large_log.txt", ios::binary);
    if (!in) {
        cerr << "File error" << endl;
        return 1;
    }

    char buf[11];
    in.read(buf, 10);
    buf[10] = 0;
    cout << "Read: " << buf << endl;
    cout << "Pos: " << in.tellg() << endl;
    in.getline(buf, sizeof(buf));
    cout << "Line: " << buf << endl;
    cout << "New Pos: " << in.tellg() << endl;
    in.close();
    return 0;
}