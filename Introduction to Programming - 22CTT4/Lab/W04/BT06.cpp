#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter n: "; cin >> n;

    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    if (sum == n) cout << "This is a complete number" << endl;
    else cout << "This isn't a complete number" << endl;

    return 0;
}