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

void deleteNElements(int a[], int &N, int n, int x) {
    for (int i = x; i < N - n; i++) {
        a[i] = a[i + n];
    }
    N -= n;
}

int main() {
    int N;
    cout << "Enter number of elements: "; cin >> N;
    
    int a[N];
    inputArray(a, N);
    cout << endl << "Your array: "; outputArray(a, N);

    int n, x;
    cout << endl << "Enter position of element to delete: "; cin >> x;
    cout << "Enter number of elements to delete: "; cin >> n;

    deleteNElements(a, N, n, x);

    cout << endl << "Your array after deleting: "; outputArray(a, N);

    return 0;
}