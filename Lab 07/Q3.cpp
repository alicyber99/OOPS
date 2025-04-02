#include <iostream>
using namespace std;
class Ticket {
public:
    string ticketID, passengerName, date, destination;
    double price;
    void reserve() { cout << "Ticket reserved for " << passengerName << "\n"; }
    void cancel() { cout << "Ticket canceled for " << passengerName << "\n"; }
    void displayTicketInfo() {
        cout << "Ticket ID: " << ticketID << "\nPassenger: " << passengerName
             << "\nPrice: " << price << "\nDate: " << date << "\nDestination: " << destination << "\n";
    }
};
class FlightTicket : public Ticket {
public:
    string airlineName, flightNumber, seatClass;
    void displayTicketInfo() {
        Ticket::displayTicketInfo();
        cout << "Airline: " << airlineName << "\nFlight Number: " << flightNumber << "\nSeat Class: " << seatClass << "\n";
    }
};
class TrainTicket : public Ticket {
public:
    string trainNumber, coachType, departureTime;
    void reserve() { cout << "Train ticket reserved. Auto-assigning seat for " << passengerName << "\n"; }
};
class BusTicket : public Ticket {
public:
    string busCompany;
    int seatNumber;
    void cancel() { cout << "Bus ticket canceled. Last-minute refund allowed for " << passengerName << "\n"; }
};
class ConcertTicket : public Ticket {
public:
    string artistName, venue, seatType;
    void displayTicketInfo() {
        Ticket::displayTicketInfo();
        cout << "Artist: " << artistName << "\nVenue: " << venue << "\nSeat Type: " << seatType << "\n";
    }
};
int main() {
    FlightTicket flight;
    flight.ticketID = "F123";
    flight.passengerName = "John Doe";
    flight.price = 350.0;
    flight.date = "2025-04-15";
    flight.destination = "NYC";
    flight.airlineName = "AirwaysX";
    flight.flightNumber = "AX123";
    flight.seatClass = "Business";
    flight.displayTicketInfo();
    flight.reserve();
    return 0;
}
