#include <iostream>
using namespace std;

class Shipment {
protected:
    string trackingNumber;
    double weight;
public:
    Shipment(string tNum = "", double w = 0) {
        trackingNumber = tNum;
        weight = w;
    }
    virtual double estimateDeliveryTime() = 0; 
    virtual void showDetails() = 0;            
};
class AirFreight : public Shipment {
public:
    AirFreight(string tNum, double w) : Shipment(tNum, w) {}
    double estimateDeliveryTime() override {
        return weight / 10.0; 
    }
    void showDetails() override {
        cout << "Air Freight" << endl;
        cout << "Tracking #: " << trackingNumber << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Estimated Delivery Time: " << estimateDeliveryTime() << " hours" << endl;
    }
};
class GroundShipment : public Shipment {
public:
    GroundShipment(string tNum, double w) : Shipment(tNum, w) {}
    double estimateDeliveryTime() override {
        return weight / 5.0; 
    }
    void showDetails() override {
        cout << "Ground Shipment" << endl;
        cout << "Tracking #: " << trackingNumber << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Estimated Delivery Time: " << estimateDeliveryTime() << " hours" << endl;
    }
};
int main() {
    Shipment* shipment1 = new AirFreight("AIR456", 45.5);
    Shipment* shipment2 = new GroundShipment("GR222", 40.5);
    shipment1->showDetails();
    cout << endl;
    shipment2->showDetails();
    delete shipment1;
    delete shipment2;
    return 0;
}
