#include <iostream>
#include <math.h>

using namespace std;

int main() {
    float a, b, c, delta, x1, x2;

    cout << "Enter the first coefficient: "; cin >> a;
    cout << "Enter the second coefficient: "; cin >> b;
    cout << "Enter the third coefficient: "; cin >> c;

    delta = b * b - 4 * a * c;

    if (delta < 0)
        cout << "No solution" << endl;
    else if (delta == 0) {
        x1 = -b / (2 * a);
        cout << "The solution is " << x1 << endl;
    } else {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        cout << "The solutions are " << x1 << " and " << x2 << endl;
    }

    return 0;
}