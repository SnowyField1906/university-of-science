#include <iostream>

using namespace std;

void inputArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": "; cin >> a[i];
    }
}

bool isAscending(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) return false;
    }
    return true;
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[j - 1]) swap(a[j], a[j - 1]);
        }
    }
}

void merge(int a[], int b[], int c[], int n) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < n) {
        if (a[i] < b[j]) c[k++] = a[i++];
        else c[k++] = b[j++];
    }
    while (i < n) c[k++] = a[i++];
    while (j < n) c[k++] = b[j++];
}

int main() {
    int n;
    cout << "Enter number of elements: "; cin >> n;
    
    int a[n], b[n], c[2 * n];
    cout << "Enter array 1: " << endl; inputArray(a, n);
    cout << "Enter array 2: " << endl; inputArray(b, n);

    if (isAscending(a, n)) {
        cout << "Array 1 is ascending" << endl;
    }
    else {
        cout << "Array 1 is not ascending" << endl;
        bubbleSort(a, n);
        cout << "Sorted array 1: ";
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }

    if (isAscending(b, n)) {
        cout << "Array 2 is ascending" << endl;
    }
    else {
        cout << "Array 2 is not ascending" << endl;
        bubbleSort(b, n);
        cout << "Sorted array 2: ";
        for (int i = 0; i < n; i++) cout << b[i] << " ";
        cout << endl;
    }

    merge(a, b, c, n);
    cout << "Merged array: ";
    for (int i = 0; i < 2 * n; i++) cout << c[i] << " ";

    return 0;
}