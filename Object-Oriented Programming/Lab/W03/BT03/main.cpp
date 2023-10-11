#include <iostream>
#include <math.h>
#include "DaThuc.cpp"
#include "DonThuc.cpp"

using namespace std;

int main() {
    DaThuc daThuc1;
    cout << "Enter the polynomial 1: " << endl;
    cin >> daThuc1;

    DaThuc daThuc2;
    cout << "Enter the polynomial 2: " << endl;
    cin >> daThuc2;

    cout << endl << "Polynomial 1: " << daThuc1 << endl;
    cout << "Polynomial 2: " << daThuc2 << endl;

    cout << endl << "Sum of the polynomials: " << daThuc1 + daThuc2 << endl;
    cout << "Difference of the polynomials: " << daThuc1 - daThuc2 << endl;
    cout << "Product of the polynomials: " << daThuc1 * daThuc2 << endl;
    cout << "Quotient of the polynomials: " << daThuc1 / daThuc2 << endl;

    return 0;
}