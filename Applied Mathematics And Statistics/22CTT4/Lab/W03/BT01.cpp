#include <iostream>

using namespace std;

int main() {
    int n;
    float x, res;

    cout << "Enter n: "; cin >> n;
    cout << "Enter x: "; cin >> x;

    res = 1;

    for (int i = 1; i <= n; i++) {
        res *= (x * x + 1);
    }

    cout << "Result: " << res << endl;
    
    return 0;
}