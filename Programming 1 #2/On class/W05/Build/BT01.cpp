#include <iostream>

using namespace std;

void headTailArray(int a[], int b[], int n) {
    int count = 0;
    for (int i = 0; i <= n/2; i++) {
        b[count++] = a[i];
        if(i != n/2) b[count++] = a[n - 1 - i];
    }
}
int main() {
    int n;
    cout << "Enter the number of elements: "; cin >> n;

    int a[n], b[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": "; cin >> arr[i];
    }

    headTailArray(a, b, n);

    cout << "The new array is: ";
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }

    return 0;
}