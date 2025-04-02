#include <iostream>

using namespace std;
class Product {
protected:
    int productID;
    char productName[50];
    float price;
    int stockQuantity;
public:
    Product(int id, const char* name, float p, int stock) {
        productID = id;
        price = p;
        stockQuantity = stock;
        strCopy(productName, name);
    }
    void strCopy(char* dest, const char* src) {
        while (*src) {
            *dest++ = *src++;
        }
        *dest = '\0';
    }
    virtual void applyDiscount() { price *= 0.90; }
    virtual float calculateTotalPrice(int quantity) { return price * quantity; }
    virtual void displayProductInfo() {
        cout << "Product: " << productName << " (ID: " << productID
             << "), Price: $" << price << ", Stock: " << stockQuantity << "\n";
    }
    Product operator+(const Product& other) {
        return Product(0, "Bulk Purchase", price + other.price, 0);
    }
    friend ostream& operator<<(ostream& os, const Product& p) {
        os << "Product: " << p.productName << ", Price: $" << p.price
           << ", Stock: " << p.stockQuantity;
        return os;
    }
    virtual ~Product() {}
};
class Electronics : public Product {
private:
    int warrantyPeriod;
    char brand[30];
public:
    Electronics(int id, const char* name, float p, int stock, int warranty, const char* br)
        : Product(id, name, p, stock) {
        warrantyPeriod = warranty;
        strCopy(brand, br);
    }
    void displayProductInfo() override {
        cout << "Electronics - " << productName << " (Brand: " << brand
             << ", Warranty: " << warrantyPeriod << " years, Price: $" << price << ")\n";
    }
};
class Clothing : public Product {
private:
    char size[10];
    char color[20];
    char fabricMaterial[30];
public:
    Clothing(int id, const char* name, float p, int stock, const char* sz, const char* col, const char* fabric)
        : Product(id, name, p, stock) {
        strCopy(size, sz);
        strCopy(color, col);
        strCopy(fabricMaterial, fabric);
    }
    void applyDiscount() override { price *= 0.80; } 
    void displayProductInfo() override {
        cout << "Clothing - " << productName << " (Size: " << size
             << ", Color: " << color << ", Fabric: " << fabricMaterial
             << ", Price after discount: $" << price << ")\n";
    }
};
class FoodItem : public Product {
private:
    char expirationDate[20];
    int calories;
public:
    FoodItem(int id, const char* name, float p, int stock, const char* expDate, int cal)
        : Product(id, name, p, stock) {
        strCopy(expirationDate, expDate);
        calories = cal;
    }
    float calculateTotalPrice(int quantity) override {
        return (quantity >= 5) ? price * quantity * 0.90 : price * quantity; 
    }
    void displayProductInfo() override {
        cout << "FoodItem - " << productName << " (Exp: " << expirationDate
             << ", Calories: " << calories << ", Price: $" << price << ")\n";
    }
};
class Book : public Product {
private:
    char author[50];
    char genre[30];
public:
    Book(int id, const char* name, float p, int stock, const char* auth, const char* gen)
        : Product(id, name, p, stock) {
        strCopy(author, auth);
        strCopy(genre, gen);
    }
    void displayProductInfo() override {
        cout << "Book - " << productName << " (Author: " << author
             << ", Genre: " << genre << ", Price: $" << price << ")\n";
    }
};
int main() {
    Electronics laptop(101, "Dell Laptop", 1200.0, 10, 2, "Dell");
    Clothing tshirt(202, "Cotton T-Shirt", 25.0, 50, "M", "Blue", "Cotton");
    FoodItem bread(303, "Whole Wheat Bread", 5.0, 30, "2024-07-10", 120);
    Book novel(404, "The Great Gatsby", 15.0, 20, "F. Scott Fitzgerald", "Fiction");
    Product* products[] = {&laptop, &tshirt, &bread, &novel};
    cout << "\n--- Product Details ---\n";
    for (Product* p : products) {
        p->displayProductInfo();
        cout << "----------------------------\n";
    }
    cout << "\n--- Applying Discount on Clothing ---\n";
    tshirt.applyDiscount();
    tshirt.displayProductInfo();
    cout << "\n--- Buying 6 Bread Loaves (Bulk Discount Applied) ---\n";
    cout << "Total Price: $" << bread.calculateTotalPrice(6) << "\n";
    cout << "\n--- Operator Overloading Test ---\n";
    Product bulkPurchase = laptop + tshirt;
    cout << "Bulk Purchase Price: $" << bulkPurchase.calculateTotalPrice(1) << "\n";
    cout << "\n--- Displaying Product Using << Overloaded Operator ---\n";
    cout << novel << "\n";
    return 0;
}
