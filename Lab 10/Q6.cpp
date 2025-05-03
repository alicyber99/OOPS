#include <iostream>
#include <fstream>
#include <cstring> 
using namespace std;

const int NAME_SIZE = 50;

struct InventoryItem {
    int itemID;
    char itemName[NAME_SIZE]; 
};
int main() {
    InventoryItem itemToWrite;
    itemToWrite.itemID = 123;
    strncpy(itemToWrite.itemName, "Sample Item", NAME_SIZE - 1);
    itemToWrite.itemName[NAME_SIZE - 1] = '\0'; 
    ofstream outFile("inventory.dat", ios::binary);
    if (!outFile) {
        cerr << "Error creating file!" << endl;
        return 1;
    }

    outFile.write(reinterpret_cast<char*>(&itemToWrite), sizeof(InventoryItem));
    outFile.close();
    InventoryItem itemToRead;
    ifstream inFile("inventory.dat", ios::binary);
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    inFile.read(reinterpret_cast<char*>(&itemToRead), sizeof(InventoryItem));
    inFile.close();

    cout << "Loaded Item - ID: " << itemToRead.itemID 
              << ", Name: " << itemToRead.itemName << endl;

    return 0;
}