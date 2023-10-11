/*
    MSSV:   21120566
    Ho ten: Nguyen Huu Thuan
    Nhom:   22CTT4
*/

#include <iostream>

using namespace std;

int sumOfDigit(int a) {
    int sum = 0;
    while (a > 0) {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}

void countDivisor(int a, int n) {
    while (a > 0) {
        if (n % (a % 10) == 0) cout<< a % 10 << " ";
        a /= 10;
    }
}

double power(int x, int n) {
    double result = 1;
    for (double i = 0; i < n; i++) {
        result *= x;
    }
    return result;
}

double factorial(int n) {
    double result = 1;
    for (double i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}


double f(int x, int n) {
    double sum = 1;
    for (int i = 1; i <= n; i++) {
        sum += power(-1, i) * power(x, 2*i) / factorial(2*i);
    }

    return sum;
}

int main() {
    int n, a, x;

    cout << "Enter a: "; cin >> a;

    n = sumOfDigit(a);
    cout << "Sum of all digits in " <<  a << ": " << n << endl;

    cout << "Number of digits in " << a << " is divisor of " << n << ": ";
    countDivisor(a, n);
    cout << endl;

    cout << "Enter x: "; cin >> x;

    cout << "f(" << x << ") = " << f(x, n) << endl;

    return 0;
}