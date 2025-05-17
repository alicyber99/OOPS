#include <iostream>
#include <exception>
using namespace std;

class DatabaseException : public exception {
public:
    const char* what() const noexcept override {
        return "A database error occurred.";
    }
};

class ConnectionFailedException : public DatabaseException {
public:
    const char* what() const noexcept override {
        return "A database error occurred.";
    }
};

class QueryTimeoutException : public DatabaseException {
public:
    const char* what() const noexcept override {
        return "A database error occurred.";
    }
};

template<typename T>
class DatabaseConnector {
public:
    void connect(T dbName) {
        if (dbName == "invalid_db") throw ConnectionFailedException();
        else if (dbName == "slow_db") throw QueryTimeoutException();
        cout << "Connected to database: " << dbName << endl;
    }
};

int main() {
    DatabaseConnector<string> db;
    try {
        cout << "Attempting to connect to invalid_db..." << endl;
        db.connect("invalid_db");
    } catch (ConnectionFailedException& e) {
        cout << "Caught ConnectionFailedException - what(): " << e.what() << endl;
    }

    try {
        cout << "Attempting to connect to slow_db..." << endl;
        db.connect("slow_db");
    } catch (DatabaseException& e) {
        cout << "Caught DatabaseException - what(): " << e.what() << endl;
    }
    return 0;
}
