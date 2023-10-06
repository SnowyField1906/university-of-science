#include <iostream>

using namespace std;


int main() {
    int n, x, total = 1;
    cout << "Enter n: "; cin >> n;
    cout << "Enter x: "; cin >> x;

    for (int i = 1; i <= n; i++) {
        total *= x * x + 1;
    }

    cout << "Total: " << total << endl;

    return 0;
}