#include <iostream>

using namespace std;

int main() {
    int days;
    char type;
    long price;

    cout << "Enter number of days: "; cin >> days;
    cout << "Enter type of room (A/B/C): "; cin >> type;

    if (days < 0) {
        cout << "Invalid number of days" << endl;
    } else if (type != 'A' && type != 'B' && type != 'C') {
        cout << "Invalid type of room" << endl;
    } else {
        if (days < 12) {
            if (type == 'A') {
                price = days * 400000;
            } else if (type == 'B') {
                price = days * 300000;
            } else {
                price = days * 250000;
            }
        } else {
            if (type == 'A') {
                price = days * 400000 * 0.9;
            } else if (type == 'B') {
                price = days * 300000 * 0.92;
            } else {
                price = days * 250000 * 0.92;
            }
        }

        cout << "Total price: " << price * days << endl;
    }

    return 0;
}