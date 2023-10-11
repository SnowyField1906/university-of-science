#include <iostream>

using namespace std;


int main() {
    int n, k;
    cout << "Enter n: "; cin >> n;
    cout << "Enter k: "; cin >> k;
    
    int c = 1;
    for (int i = 1; i <= k; i++) {
        c *= (n - i + 1);
        c /= i;
    }

    cout << "C(" << n << ", " << k << ") = " << c << endl;

    return 0;
}