#include <iostream>

using namespace std;

int main() {
    int n, a, b;
    cout << "Enter n: "; cin >> n;

    int i = 1;
    while (i * i < n) {
        i++;
    }
    if (i * i == n) cout << "This is a quare number" << endl;
    else cout << "This isn't a square number" << endl;


    cout << "Enter a: "; cin >> a;
    cout << "Enter b: "; cin >> b;
    for (int i = a; i <= b; i++) {
        int j = 1;
        while (j * j < i) {
            j++;
        }
        if (j * j == i) {
            cout << i << " ";
        }
    }

    return 0;
}