#include <iostream>

#define BIT 8

using namespace std;

void decimalToTwoComplement(int n, int a[]) {
    int sign = 1;
    if (n < 0) {
        sign = -1;
        n = -n - 2;
    }
    for (int i = BIT - 1; i >= 0; i--) {
        a[i] = n % 2;
        n /= 2;
    }
    if (sign == -1) {
        for (int i = 0; i < BIT; i++) a[i] = !a[i];
        for (int i = BIT - 1; i >= 0; i--) {
            if (a[i]) {
                a[i] = 0;
                break;
            }
            else a[i] = 1;
        }
    }
}

int main() {
    int n;
    cout << "Enter a decimal number: "; cin >> n;
    int a[8];
    decimalToTwoComplement(n, a);
    cout << "Two's complement: ";
    for (int i = 0; i < BIT; i++) {
        if (a[i] == 0 || a[i] == 1) cout << a[i];
    }

    return 0;
}