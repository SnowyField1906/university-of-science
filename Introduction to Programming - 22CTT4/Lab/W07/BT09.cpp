#include <iostream>

using namespace std;

void inputArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": "; cin >> a[i];
    }
}

void uniqueAInB(int a[], int b[], int n, int m) {
    for (int i = 0; i < n; i++) {
        bool isFound = false;
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                isFound = true;
                break;
            }
        }
        if (!isFound) cout << a[i] << " ";
    }
}

int mergeWithoutDuplicate(int a[], int b[], int c[], int n, int m) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) c[k++] = a[i++];
        else if (a[i] > b[j]) c[k++] = b[j++];
        else {
            c[k++] = a[i++];
            j++;
        }
    }
    while (i < n) c[k++] = a[i++];
    while (j < m) c[k++] = b[j++];
    return k;
}

int main() {
    int n, m;
    cout << "Enter number of elements in array 1: "; cin >> n;
    cout << "Enter number of elements in array 2: "; cin >> m;
    
    int a[n], b[m], c[n + m];
    cout << "Enter array 1: " << endl; inputArray(a, n);
    cout << "Enter array 2: " << endl; inputArray(b, m);

    cout << "Elements in array 1 but not in array 2: ";
    uniqueAInB(a, b, n, m);
    cout << endl;

    cout << "Merged array: ";
    int k = mergeWithoutDuplicate(a, b, c, n, m);
    for (int i = 0; i < k; i++) cout << c[i] << " ";
    cout << endl;

    return 0;
}