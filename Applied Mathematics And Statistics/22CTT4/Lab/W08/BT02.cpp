#include <iostream>

using namespace std;


// Gia su vi tri dau tien la 0


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

void deleteElement(int a[], int &n, int k) {
    for (int i = k; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;
}

int main() {
    int n;
    cout << "Enter number of elements: "; cin >> n;
    
    int a[n];
    inputArray(a, n);
    cout << endl << "Your array: "; outputArray(a, n);
    
    int k;
    cout << endl << "Enter position of element to delete: "; cin >> k;
    deleteElement(a, n, k);
    
    cout << endl << "Your array after deleting: "; outputArray(a, n);
    return 0;
}