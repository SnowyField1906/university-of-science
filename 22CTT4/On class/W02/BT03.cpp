#include <iostream>

using namespace std;

int main() {
    float km;
    cout << "Enter the distance in kilometers: "; cin >> km;

    float bill;

    if (km <= 2)
        bill = km * 15000;
    else if (km <= 6)
        bill = 15000 * 2 + (km - 2) * 12000;
    else if (km > 6)
        bill = 15000 * 2 + 4 * 12000 + (km - 6) * 10000;
    
    if (bill > 100000)
        bill = bill * 0.9;

    cout << "The bill is " << bill << " VND" << endl;

    return 0;
}