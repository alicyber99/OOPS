#include <iostream>
using namespace std;

struct Product {
    int productID;
    string name;
    int quantity;
    double price;
};
int main() {
    int n;
    cout << "Enter the number of products: ";
    cin >> n;
    Product* products = new Product[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter details for product " << i + 1 << ":\n";
        cout << "Product ID: ";
        cin >> products[i].productID;
        cout << "Name: ";
        cin >> products[i].name;
        cout << "Quantity: ";
        cin >> products[i].quantity;
        cout << "Price: ";
        cin >> products[i].price;
    }
    double totalValue = 0;
    for (int i = 0; i < n; i++) {
        totalValue += products[i].quantity * products[i].price;
    }
    cout << "Total Inventory Value: $" << totalValue << endl;
    delete[] products;
    return 0;
}
