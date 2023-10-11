#include <iostream>

using namespace std;


int main() {
    int a, b;
    cout << "Enter a: "; cin >> a;
    cout << "Enter b: "; cin >> b;

    int max = a > b ? a : b;
    int min = a < b ? a : b;
    int lcm = max;
    while (lcm % min != 0) {
        lcm += max;
    }
    
    cout << "Least common multiple: " << lcm << endl;

    return 0;
}