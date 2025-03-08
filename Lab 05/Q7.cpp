#include <iostream>
using namespace std;

class Product {
public:
    int id;
    char name[50];
    int quantity;
    void setDetails(int pid, char pname[], int pquantity) {
        id = pid;
        int i = 0;
        while (pname[i] != '\0') {
            name[i] = pname[i];
            i++;
        }
        name[i] = '\0';
        quantity = pquantity;
    }
    void display() {
        cout << "ID: " << id << " | Name: " << name << " | Quantity: " << quantity << "\n";
    }
};
void sortProducts(Product products[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int k = 0;
            while (products[j].name[k] != '\0' && products[j + 1].name[k] != '\0' &&
                   products[j].name[k] == products[j + 1].name[k]) {
                k++;
            }
            if (products[j].name[k] > products[j + 1].name[k]) {
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
}
Product* searchById(Product products[], int count, int searchId) {
    for (int i = 0; i < count; i++) {
        if (products[i].id == searchId) {
            return &products[i];
        }
    }
    return NULL;
}
int main() {
    Product products[3];
    products[0].setDetails(101, "Laptop", 5);
    products[1].setDetails(102, "Chair", 15);
    products[2].setDetails(103, "Apple", 50);
    sortProducts(products, 3);
    cout << "Inventory:\n";
    for (int i = 0; i < 3; i++) {
        products[i].display();
    }
    int searchId = 102;
    Product* found = searchById(products, 3, searchId);
    if (found) {
        cout << "\nProduct Found:\n";
        found->display();
    } else {
        cout << "\nProduct not found.\n";
    }
    return 0;
}
