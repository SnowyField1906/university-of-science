#include <iostream>

using namespace std;

void simplify(int &num, int &den) {
    int a = num, b = den;
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    num /= a;
    den /= a;
}

void add(int a1, int b1, int a2, int b2, int &a3, int &b3) {
    a3 = a1 * b2 + a2 * b1;
    b3 = b1 * b2;
    simplify(a3, b3);
}

void sub(int a1, int b1, int a2, int b2, int &a3, int &b3) {
    a3 = a1 * b2 - a2 * b1;
    b3 = b1 * b2;
    simplify(a3, b3);
}

int main() {
    int a1, b1, a2, b2, a3, b3;
    
    cout << "Enter numerator of firskt fraction: "; cin >> a1;
    cout << "Enter denominator of first fraction: "; cin >> b1;

    cout << "Enter numerator of second fraction: "; cin >> a2;
    cout << "Enter denominator of second fraction: "; cin >> b2;

    add(a1, b1, a2, b2, a3, b3);
    cout << "Addition: " << a3 << "/" << b3 << endl;

    sub(a1, b1, a2, b2, a3, b3);
    cout << "Subtraction: " << a3 << "/" << b3 << endl;

    return 0;
}