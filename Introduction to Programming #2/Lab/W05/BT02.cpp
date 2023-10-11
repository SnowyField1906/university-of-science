#include <iostream>

using namespace std;

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
    cout << "Enter a decimal number: "; cin >> n;

    cout << "Hexadecimal: " << decToHex(n) << endl;

    return 0;
}