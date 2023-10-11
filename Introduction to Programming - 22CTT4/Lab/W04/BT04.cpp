#include <iostream>

using namespace std;



int main() {
    int n;
    cout << "Enter n: "; cin >> n;

    int reversed = 0;
    int temp = n;
    while (temp > 0) {
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }
    if (reversed == n) cout << "This is a mirror number" << endl;
    else cout << "This isn't a mirror number" << endl;

    bool even = true, odd = true;
    while (n > 0) {
        if (n % 2 == 0) odd = false;
        else even = false;
        n /= 10;
    }
    if (even) cout << "This is a full-of-even number" << endl;
    else if (odd) cout << "This is a full-of-odd number" << endl;
    else cout << "This is a mixed number" << endl;

    return 0;
}