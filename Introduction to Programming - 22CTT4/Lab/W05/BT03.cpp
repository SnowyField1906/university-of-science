#include <iostream>
#include <math.h>

using namespace std;

int binToDec(int n) {
    int dec = 0;
    for (int i = 0; n != 0; n /= 10, i++)
        dec += (n % 10) * pow(2, i);
    return dec;
}

string decToHex(int n) {
    string hex = "";
    for (; n > 0; n /= 16) {
        int r = n % 16;
        if (r < 10) hex = to_string(r) + hex;
        else hex = char(r - 10 + 'A') + hex;
    }
    return hex;
}

int main() {
    int n;
    cout << "Enter a binary number: "; cin >> n;

    cout << "Hexadecimal: " << decToHex(binToDec(n)) << endl;

    return 0;
}