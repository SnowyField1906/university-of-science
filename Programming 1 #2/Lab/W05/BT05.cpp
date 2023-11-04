#include <iostream>

using namespace std;

int digitInNumber(int n, int k) {
    int digit = 0;
    for (int i = 1; n > 0; i++, n /= 10) {
        if (i == k) digit = n % 10;
    }
    return digit;
}

int main() {
    int n, k;
    cout << "Enter a number: "; cin >> n;
    cout << "Enter an ordinal number: "; cin >> k;

    cout << "The digit at " << k << " in " << n << " is " << digitInNumber(n, k) << endl;


    return 0;
}