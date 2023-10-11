#include <iostream>

using namespace std;

// Em lam tu tuan truoc nhung quen nop a
// Gio em moi phat hien nen cho em nop lai nha thay
// Em cam on a

void inputArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": "; cin >> a[i];
    }
}

int sumOfPositive(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) sum += a[i];
    }
    return sum;
}

int sumOfDivisibleBy3(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 3 == 0) sum += a[i];
    }
    return sum;
}

bool firstOddDigit(int x) {
    if (x < 0) x = -x;
    while (x > 0) {
        if (x % 2 != 0) return true;
        x /= 10;
    }
    return false;
}

int sumOfFirstOddDigit(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (firstOddDigit(a[i])) sum += a[i];
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter number of elements: "; cin >> n;
    
    int a[n];
    inputArray(a, n);

    cout << "Sum of positive elements: " << sumOfPositive(a, n) << endl;

    cout << "Sum of elements divisible by 3: " << sumOfDivisibleBy3(a, n) << endl;

    cout << "Sum of elements with first odd digit: " << sumOfFirstOddDigit(a, n) << endl;
    
    return 0;
}