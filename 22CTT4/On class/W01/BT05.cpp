#include <iostream>

using namespace std;

int main() {
    float Celsius;
    cout << "Input Celsius: ";
    cin >> Celsius;
    cout << "Fahrenheit: " << Celsius * 1.8 + 32 << endl;

    return 0;
}