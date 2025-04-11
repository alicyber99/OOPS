#include <iostream>
using namespace std;

class Matrix2x2; 
class Matrix {
public:
    void updateElement(Matrix2x2& matrix, int row, int col, int value);
};
class Matrix2x2 {
private:
    int elements[2][2];
public:
    Matrix2x2(int a = 0, int b = 0, int c = 0, int d = 0) {
        elements[0][0] = a;
        elements[0][1] = b;
        elements[1][0] = c;
        elements[1][1] = d;
    }
    Matrix2x2 operator+(Matrix2x2& other) {
        Matrix2x2 result;
        result.elements[0][0] = elements[0][0] + other.elements[0][0];
        result.elements[0][1] = elements[0][1] + other.elements[0][1];
        result.elements[1][0] = elements[1][0] + other.elements[1][0];
        result.elements[1][1] = elements[1][1] + other.elements[1][1];
        return result;
    }
    Matrix2x2 operator-(Matrix2x2& other) {
        Matrix2x2 result;
        result.elements[0][0] = elements[0][0] - other.elements[0][0];
        result.elements[0][1] = elements[0][1] - other.elements[0][1];
        result.elements[1][0] = elements[1][0] - other.elements[1][0];
        result.elements[1][1] = elements[1][1] - other.elements[1][1];
        return result;
    }
    Matrix2x2 operator*(Matrix2x2& other) {
        Matrix2x2 result;
        result.elements[0][0] = elements[0][0] * other.elements[0][0] + elements[0][1] * other.elements[1][0];
        result.elements[0][1] = elements[0][0] * other.elements[0][1] + elements[0][1] * other.elements[1][1];
        result.elements[1][0] = elements[1][0] * other.elements[0][0] + elements[1][1] * other.elements[1][0];
        result.elements[1][1] = elements[1][0] * other.elements[0][1] + elements[1][1] * other.elements[1][1];
        return result;
    }
    friend int determinant(Matrix2x2& matrix);
    friend class Matrix;
    friend ostream& operator<<(ostream& out, Matrix2x2& matrix) {
        out << matrix.elements[0][0] << " " << matrix.elements[0][1] << "\n";
        out << matrix.elements[1][0] << " " << matrix.elements[1][1];
        return out;
    }
};
int determinant(Matrix2x2& matrix) {
    return matrix.elements[0][0] * matrix.elements[1][1] - matrix.elements[0][1] * matrix.elements[1][0];
}
void Matrix::updateElement(Matrix2x2& matrix, int row, int col, int value) {
    if (row >= 0 && row < 2 && col >= 0 && col < 2) {
        matrix.elements[row][col] = value;
    }
}
int main() {
    Matrix2x2 m1(3, 4,5, 6);
    Matrix2x2 m2(8, 9, 4, 3);
    cout << "Matrix 1:\n" << m1 << "\n\n";
    cout << "Matrix 2:\n" << m2 << "\n\n";
    Matrix2x2 sum = m1 + m2;
    Matrix2x2 diff = m1 - m2;
    Matrix2x2 prod = m1 * m2;
    cout << "Sum:\n" << sum << "\n\n";
    cout << "Difference:\n" << diff << "\n\n";
    cout << "Product:\n" << prod << "\n\n";
    cout << "Determinant of Matrix 1: " << determinant(m1) << "\n\n";
    Matrix Mat;
    Mat.updateElement(m1, 0, 1, 9); 
    cout << "Matrix 1 after update:\n" << m1 << "\n";
    return 0;
}
