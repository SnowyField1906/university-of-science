#include <iostream>
#include <iomanip>

using namespace std;

void inputArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": "; cin >> a[i];
    }
}

void outputArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int frequency(int a[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) count++;
    }
    return count;
}

void removeDuplicate(int a[], int b[], int n, int &m) {
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[i] == a[j]) break;
            if (j == 0) b[m++] = a[i];
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: "; cin >> n;
    
    int a[n];
    inputArray(a, n);
    cout << endl << "Your array: "; outputArray(a, n);

    int b[n], m = 1;
    b[0] = a[0];
    removeDuplicate(a, b, n, m);
    
    cout << endl << setw(10) << "Element" << " | " << "Frequency" << endl;

    for (int i = 0; i < m; i++) {
        cout << setw(10) << b[i] << " | " << frequency(a, n, b[i]) << endl;
    }
    return 0;
}