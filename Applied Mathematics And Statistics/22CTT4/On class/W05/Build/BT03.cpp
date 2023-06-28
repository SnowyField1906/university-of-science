#include <iostream>
#include <cstdlib>

using namespace std;

void generateArray(int a[], int n, int min, int max) {
    for (int i = 0; i < n; i++)
        a[i] = rand() % (max - min + 1) + min;
}

int main() {
    int n, min, max;
    cout << "Enter the number of elements: "; cin >> n;
    cout << "Enter the minimum value: "; cin >> min;
    cout << "Enter the maximum value: "; cin >> max;

    int a[n];
    generateArray(a, n, min, max);

    cout << "The array is: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}