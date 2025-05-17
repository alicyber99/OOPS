#include <iostream>
#include <exception>
using namespace std;

class NegativeStockException : public exception {
public:
    const char* what() const noexcept override {
        return "std::exception";
    }
};

class OverCapacityException : public exception {
public:
    const char* what() const noexcept override {
        return "std::exception";
    }
};

template<typename T>
class InventoryItem {
    T stock;
    T capacity;
public:
    InventoryItem(T maxCapacity) : stock(0), capacity(maxCapacity) {}

    void setStock(T value) {
        if (value < 0)
            throw NegativeStockException();
        if (value > capacity)
            throw OverCapacityException();
        stock = value;
    }
};

int main() {
    InventoryItem<int> item(100);
    try {
        cout << "Attempting to set stock to -5..." << endl;
        item.setStock(-5);
    } catch (NegativeStockException& e) {
        cout << "Caught NegativeStockException - what(): " << e.what() << endl;
    }

    try {
        cout << "Attempting to set stock to 120 (max 100)..." << endl;
        item.setStock(120);
    } catch (OverCapacityException& e) {
        cout << "Caught OverCapacityException - what(): " << e.what() << endl;
    }

    return 0;
}
