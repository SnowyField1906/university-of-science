#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    cout << "Enter the first number: "; cin >> a;
    cout << "Enter the second number: "; cin >> b;
    cout << "Enter the third number: "; cin >> c;
    cout << "Enter the fourth number: "; cin >> d;

    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;

    cout << "The largest number is " << max << endl;

    return 0;
}