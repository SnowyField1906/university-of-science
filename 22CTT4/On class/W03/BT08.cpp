#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter n: "; cin >> n;

    for(int i = 1; i <= n; i++) {
        if(i * i == n) {
            cout << "Square number" << endl;
            return 0;
        }
    }

    cout << "Not a square number" << endl;


    return 0;
}
