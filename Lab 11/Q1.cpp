#include <iostream>
#include <exception>
using namespace std;

class DimensionMismatchException : public exception {
public:
    const char* what() const noexcept override {
        return "DimensionMismatchException - Matrices must have same dimensions";
    }
};
template<typename T>
class Matrix {
    T data[2][2]; 
public:
    Matrix() {}
    Matrix(T a[2][2]) {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                data[i][j] = a[i][j];
    }
    Matrix<T> operator+(Matrix<T>& other) {
        Matrix<T> result;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                result.data[i][j] = this->data[i][j] + other.data[i][j];
        return result;
    }
};
int main() {
    try {
        int a[2][2] = {{1, 2}, {3, 4}};
        int b[2][2] = {{5, 6}, {7, 8}};
        Matrix<int> m1(a), m2(b);
        Matrix<int> m3 = m1 + m2;
        cout << "Matrix added successfully.\n";
    } catch (DimensionMismatchException& e) {
        cout << e.what() << endl;
    }
    return 0;
}
