#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cout << "Enter a: "; cin >> a;
    cout << "Enter b: "; cin >> b;
    cout << "Enter c: "; cin >> c;

    a = a + b + c;
    b = a - b - c;
    c = a - b - c;
    a = a - b - c;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    return 0;
}