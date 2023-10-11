#include <iostream>

using namespace std;


int main() {
    int a, b;
    cout << "Enter numerator: "; cin >> a;
    cout << "Enter denominator: "; cin >> b;

    int gcd = 1;
    for (int i = 1; i <= a && i <= b; i++) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }
    
    cout << "Simplest form of " << a << "/" << b << ": " << a / gcd << "/" << b / gcd << endl;


    return 0;
}