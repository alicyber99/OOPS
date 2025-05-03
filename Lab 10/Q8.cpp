#include <iostream>
#include <fstream>
using namespace std;

const int BLOCK_SIZE = 5; 
int main() {
    {
        ofstream outFile("config.txt");
        outFile << "AAAAABBBBBCCCCC";
        outFile.close();
    }

    fstream file("config.txt", ios::in | ios::out);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    file.seekp(BLOCK_SIZE, ios::beg);

    file.write("XXXXX", BLOCK_SIZE);
    file.seekg(0, ios::beg); 
    char content[16]; 
    file.read(content, sizeof(content) - 1);
    content[file.gcount()] = '\0'; 

    cout << "Updated content: " << content << endl;
    file.close();
    return 0;
}