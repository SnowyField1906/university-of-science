#include <iostream>

using namespace std;

double fixed(double n, int x) {
    double total = 1;
    for (int i = 1; i <= x; i++)
        total *= 10;

    return (int) (n * total) / total;
}

int main() {
    double n;
    int x;

    cout << "Enter a number: "; cin >> n;
    cout << "Enter the number of decimal places: "; cin >> x;

    cout << "Fixed: " << fixed(n, x) << endl;


    return 0;
}