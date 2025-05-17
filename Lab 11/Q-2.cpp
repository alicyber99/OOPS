#include <iostream>
#include <exception>
using namespace std;

class QueueOverflowException : public exception {
public:
    const char* what() const noexcept override {
        return "std::exception";
    }
};
class QueueUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "std::exception";
    }
};
template<typename T>
class Queue {
    T data[5];
    int front, rear, count;
public:
    Queue() : front(0), rear(0), count(0) {}
    void enqueue(T val) {
        if (count == 5) throw QueueOverflowException();
        data[rear] = val;
        rear = (rear + 1) % 5;
        ++count;
    }
    T dequeue() {
        if (count == 0) throw QueueUnderflowException();
        T val = data[front];
        front = (front + 1) % 5;
        --count;
        return val;
    }
};
int main() {
    Queue<int> q;
    try {
        for (int i = 0; i < 6; ++i) q.enqueue(i);
    } catch (QueueOverflowException& e) {
        cout << "Caught QueueOverflowException - what(): " << e.what() << endl;
    }

    try {
        for (int i = 0; i < 6; ++i) q.dequeue();
    } catch (QueueUnderflowException& e) {
        cout << "Caught QueueUnderflowException - what(): " << e.what() << endl;
    }
    return 0;
}
