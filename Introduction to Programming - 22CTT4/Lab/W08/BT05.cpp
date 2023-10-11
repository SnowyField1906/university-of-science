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

void removeDuplicate(int a[], int b[], int &n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                for (int k = i; k < n - 1; k++) {
                    a[k] = a[k + 1];
                }
                n--;
                i--;
                break;
            }
        }
    }
}

void removeDuplicateInTwoArrays(int a[], int b[], int &n, int &m) {
    int temp[n];
    int p = n;
    for(int i = 0; i < n; i++) {
        temp[i] = a[i];
    }

    removeDuplicate(a, b, n, m);
    removeDuplicate(b, temp, m, p);
}

int main() {
    int n, m;

    cout << "Array A:" << endl;
    cout << "\tEnter number of elements: "; cin >> n;

    int a[n];
    inputArray(a, n);

    cout << endl << "Array B:" << endl;
    cout << "\tEnter number of elements: "; cin >> m;
    
    int b[m];
    inputArray(b, m);

    cout << endl << "Array A: "; outputArray(a, n);
    cout << endl << "Array B: "; outputArray(b, m);
    

    removeDuplicateInTwoArrays(a, b, n, m);

    cout << endl << "Array A after deleting: "; outputArray(a, n);
    cout << endl << "Array B after deleting: "; outputArray(b, m);

    return 0;
}