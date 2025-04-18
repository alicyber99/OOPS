#include <iostream>
using namespace std;

class MenuItem {
protected:
    string dishName;
    double price;
public:
    MenuItem(string D_name, double price) {
        dishName = D_name;
        this->price = price;
    }
    virtual void showDetails() = 0;
    virtual void prepare() = 0;
};
class Appetizer : public MenuItem {
public:
    Appetizer(string D_name, double price) : MenuItem(D_name, price) {}
    void showDetails() {
        cout << "Appetizer: " << dishName << "\n";
        cout << "Price: " << price << "\n";
    }
    void prepare() {
        cout << "Preparation Steps: Chop, mix, serve cold\n";
    }
};
class MainCourse : public MenuItem {
public:
    MainCourse(string D_name, double price) : MenuItem(D_name, price) {}
    void showDetails() {
        cout << "Main Course: " << dishName << "\n";
        cout << "Price: " << price << "\n";
    }
    void prepare() {
        cout << "Preparation Steps: Marinate, cook, plate and serve\n";
    }
};
int main() {
    MenuItem* item1 = new Appetizer("Spring Rolls", 120);
    MenuItem* item2 = new MainCourse("Grilled Chicken", 1350);
    item1->showDetails();
    item1->prepare();
    cout << "\n";
    item2->showDetails();
    item2->prepare();
    delete item1;
    delete item2;
    return 0;
}
