#include <iostream>

using namespace std;

void inputArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": "; cin >> a[i];
    }
}

bool isMirrorArray(int a[], int n) {
    for (int i = 0; i < n / 2; i++) {
        if (a[i] != a[n - i - 1]) return false;
    }
    return true;
}

bool isAlternatingArray(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] * a[i + 1] > 0) return false;
    }
    return true;
}

bool isPairedArray(int a[], int n) {
    for (int i = 0; i < n - 1; i += 2) {
        if (a[i] != a[i + 1]) return false;
    }
    return true;
}

bool isArithmeticProgression(int a[], int n) {
    int d = a[1] - a[0];
    for (int i = 1; i < n - 1; i++) {
        if (a[i + 1] - a[i] != d) return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Enter number of elements: "; cin >> n;
    
    int a[n];
    inputArray(a, n);

    if (isMirrorArray(a, n)) cout << "The array is a mirror array" << endl;
    else cout << "The array is not a mirror array" << endl;

    if (isAlternatingArray(a, n)) cout << "The array is an alternating array" << endl;
    else cout << "The array is not an alternating array" << endl;

    if (isPairedArray(a, n)) cout << "The array is a paired array" << endl;
    else cout << "The array is not a paired array" << endl;

    if (isArithmeticProgression(a, n)) cout << "The array is an arithmetic progression" << endl;
    else cout << "The array is not an arithmetic progression" << endl;

    return 0;
}