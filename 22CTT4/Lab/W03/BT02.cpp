#include <iostream>
#include <math.h>
using namespace std;

int main() {
    float a, b, c, x1, x2, delta;

    cout << "Enter a: "; cin >> a;
    cout << "Enter b: "; cin >> b;
    cout << "Enter c: "; cin >> c;

    delta = b * b - 4 * a * c;

    if (delta < 0) {
        cout << "No solution" << endl;
    } else if (delta == 0) {
        x1 = -b / (2 * a);
        cout << "x = " << x1 << endl;
    } else {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }

    return 0;
}