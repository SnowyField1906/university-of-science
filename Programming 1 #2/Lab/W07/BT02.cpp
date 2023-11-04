#include <iostream>

using namespace std;

void inputArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": "; cin >> a[i];
    }
}

bool isSquareNumber(int x) {
    for (int i = 1; i <= x; i++) {
        if (i * i == x) return true;
    }
    return false;
}

bool isPerfectNumber(int x) {
    int sum = 0;
    for (int i = 1; i <= x / 2; i++) {
        if (x % i == 0) sum += i;
    }
    return sum == x;
}

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / 2; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

bool isMirrorNumber(int x) {
    int y = 0, z = x;
    while (z > 0) {
        y = y * 10 + z % 10;
        z /= 10;
    }
    return x == y;
}

int sumOfSquareNumbers(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (isSquareNumber(a[i])) sum += a[i];
    }
    return sum;
}

int sumOfPerfectNumbers(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (isPerfectNumber(a[i])) sum += a[i];
    }
    return sum;
}

int sumOfPrimeNumbers(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(a[i])) sum += a[i];
    }
    return sum;
}

int sumOfMirrorNumbers(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (isMirrorNumber(a[i])) sum += a[i];
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter number of elements: "; cin >> n;
    
    int a[n];
    inputArray(a, n);

    cout << "Sum of square numbers: " << sumOfSquareNumbers(a, n) << endl;

    cout << "Sum of perfect numbers: " << sumOfPerfectNumbers(a, n) << endl;

    cout << "Sum of prime numbers: " << sumOfPrimeNumbers(a, n) << endl;

    cout << "Sum of positive mirror numbers: " << sumOfMirrorNumbers(a, n) << endl;
    
    return 0;
}