#include <iostream>

using namespace std;

void inputArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": "; cin >> a[i];
    }
}

bool hasPositive(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) return true;
    }
    return false;
}

bool allPositive(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) return false;
    }
    return true;
}

void convertToNegative(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) a[i] = -a[i];
    }
}

int main() {
    int n;
    cout << "Enter number of elements: "; cin >> n;
    
    int a[n];
    inputArray(a, n);

    if(hasPositive(a, n)) {
        cout << "Array has positive elements" << endl;
    } else {
        cout << "Array has no positive elements" << endl;
    }

    if(allPositive(a, n)) {
        cout << "Array has all positive elements" << endl;
    } else {
        cout << "Array has at least one negative element" << endl;
    }

    convertToNegative(a, n);

    cout << "Array after converting all positive elements to negative:" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}