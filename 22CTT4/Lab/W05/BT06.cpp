#include <iostream>

using namespace std;

long doubleFactorial(int n) {
    long result = 1;
    for (int i = 2 - n % 2; i <= n; i += 2)
        result *= i;
    return result;
}


int main() {
    int n;
    cout << "Enter a number: "; cin >> n;

    cout << "Double factorial: " << doubleFactorial(n) << endl;

    return 0;
}