#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int M, n;
    float q;

    cout << "Enter deposit: "; cin >> M;
    cout << "Enter number of months: "; cin >> n;
    cout << "Enter interest rate: "; cin >> q;

    cout << "Capitalization of interest: " << M * pow(1 + q, n) << endl;

    return 0;
}