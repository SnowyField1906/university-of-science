#include <iostream>
#include <math.h>
#define BIT 16

using namespace std;

void inputBinaryNumber(int a[]) {
    for (int i = 0; i < BIT; i++) cin >> a[i];
}

int twoComplementToSignedDecimal(int a[]) {
    int sum = 0, sign = 1;
    if (a[0]) {
        sign = -1;
        for (int i = 0; i < BIT; i++) a[i] = !a[i];
        for (int i = BIT - 1; i >= 0; i--) {
            if (a[i]) {
                a[i] = 0;
                break;
            }
            else a[i] = 1;
        }
    }
    for (int i = 0; i < BIT; i++) sum += a[i] * pow(2, BIT - i - 1);
    return sum * sign;
}



int main() {
    int a[BIT];
    cout << "Enter two's complement binary number: "; inputBinaryNumber(a);
    cout << "Decimal: " << twoComplementToSignedDecimal(a);

    return 0;
}