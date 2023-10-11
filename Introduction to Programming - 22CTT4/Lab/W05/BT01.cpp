#include <iostream>

using namespace std;

int decToBin(int n) {
    int bin = 0;
    for (int i = 1; n > 0; n /= 2, i *= 10)
        bin += (n % 2) * i;
    return bin;
}

int main() {
    int n;
    cout << "Enter a decimal number: "; cin >> n;

    cout << "Binary: " << decToBin(n) << endl;

    return 0;
}