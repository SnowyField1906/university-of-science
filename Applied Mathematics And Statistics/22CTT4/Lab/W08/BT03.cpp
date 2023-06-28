#include <iostream>

using namespace std;

void inputArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\tElement " << i + 1 << ": "; cin >> a[i];
    }
}

void outputArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void sumArray(int a[], int b[], int c[], int n) {
    for (int i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
    }
}

int main() {
    int n;
    cout << "Enter number of elements: "; cin >> n;
    
    int a[n], b[n], c[n];
    cout << endl << "Enter elements of array A:" << endl;
    inputArray(a, n);
    cout << endl << "Enter elements of array B:" << endl;
    inputArray(b, n);

    cout << endl << "Array A: "; outputArray(a, n);
    cout << endl << "Array B: "; outputArray(b, n);
    
    sumArray(a, b, c, n);
    
    cout << endl << "After merging: "; outputArray(c, n);
    return 0;
}