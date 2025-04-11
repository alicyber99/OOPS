#include <iostream>
using namespace std;

class Vector2D {
private:
    int x, y;
public:
    Vector2D(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
    Vector2D operator+(const Vector2D& other) {
        return Vector2D(x + other.x, y + other.y);
    }
    Vector2D operator-(const Vector2D& other) {
        return Vector2D(x - other.x, y - other.y);
    }
    Vector2D operator*(int scalar) {
        return Vector2D(x * scalar, y * scalar);
    }
    friend int dotProduct(const Vector2D& a, const Vector2D& b);
    friend ostream& operator<<(ostream& out, const Vector2D& v);
};
int dotProduct(const Vector2D& a, const Vector2D& b) {
    return a.x * b.x + a.y * b.y;
}
ostream& operator<<(ostream& out, const Vector2D& v) {
    out << "(" << v.x << ", " << v.y << ")";
    return out;
}
int main() {
    Vector2D v1(2, 7);
    Vector2D v2(3, 5);
    Vector2D sum = v1 + v2;
    Vector2D diff = v1 - v2;
    Vector2D scaled = v1 * 3;
    int dot = dotProduct(v1, v2);
    cout << "Vector 1: " << v1 << endl;
    cout << "Vector 2: " << v2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Scaled Vector1 (v1 * 3): " << scaled << endl;
    cout << "Dot Product: " << dot << endl;
    return 0;
}
