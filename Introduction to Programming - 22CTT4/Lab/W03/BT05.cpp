#include <iostream>

using namespace std;

int main() {
    int km; 
    int price;

    cout << "Enter distance in kilometers: "; cin >> km;

    if (km = 1) {
        price = 15000;
    } else if (km <= 5) {
        price = 15000 + (km - 1) * 13500;
    } else if (km <= 120) {
        price = 15000 + 4 * 13500 + (km - 5) * 11000;
    } else {
        price = 15000 + 4 * 13500 + 115 * 11000 + (km - 120) * 10000;
    }

    cout << "Total price: " << price << endl;

    return 0;
}