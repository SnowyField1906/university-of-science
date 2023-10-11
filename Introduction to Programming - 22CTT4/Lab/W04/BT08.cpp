#include <iostream>

using namespace std;

int main() {
    double n;
    int x;
    cout << "Enter number: "; cin >> n;
    cout << "Enter number of decimal places: "; cin >> x;

    double total = 1;
    for (int i = 1; i <= x; i++) {
        total *= 10;
    }

    cout << "Number after fixed " << (int) (n * total) / total << endl;


    return 0;
}