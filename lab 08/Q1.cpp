#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;
public:
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }
    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imag - other.imag);
    }
    Complex operator*(const Complex& other) {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }
    Complex operator/(const Complex& other) {
        double denominator = other.real * other.real + other.imag * other.imag;
        double r = (real * other.real + imag * other.imag) / denominator;
        double i = (imag * other.real - real * other.imag) / denominator;
        return Complex(r, i);
    }
    friend double magnitude(const Complex& c);
    friend ostream& operator<<(ostream& out, const Complex& c);
};
double manualSqrt(double x) {
    if (x < 0) return -1;  
    double guess = x / 2.0;
    double epsilon = 0.00001; 
    while ((guess * guess - x) > epsilon || (x - guess * guess) > epsilon) {
        guess = (guess + x / guess) / 2.0;
    }
    return guess;
}
double magnitude(const Complex& c) {
    return manualSqrt(c.real * c.real + c.imag * c.imag);
}
ostream& operator<<(ostream& out, const Complex& c) {
    out << "(" << c.real << (c.imag >= 0 ? " + " : " - ") << (c.imag >= 0 ? c.imag : -c.imag) << "i)";
    return out;
}
int main() {
    Complex c1(2, 8);
    Complex c2(3, -5);
    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex product = c1 * c2;
    Complex quotient = c1 / c2;
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "Sum = " << sum << endl;
    cout << "Difference = " << diff << endl;
    cout << "Product = " << product << endl;
    cout << "Quotient = " << quotient << endl;
    cout << "Magnitude of c1 = " << magnitude(c1) << endl;
    return 0;
}
