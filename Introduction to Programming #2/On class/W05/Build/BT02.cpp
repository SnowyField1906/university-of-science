#include <iostream>
#include <cstdlib>

using namespace std;

void generateArray(int a[], int n) {
    for (int i = 0; i < n; i++) a[i] = rand() % 10;
}

int main() {
    int n;
    cout << "Enter the number of elements: "; cin >> n;

    int a[n];
    generateArray(a, n);

    cout << "The array is: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}