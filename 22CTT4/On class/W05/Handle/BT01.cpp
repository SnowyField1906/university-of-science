#include <iostream>

using namespace std;

void reverseFirstHaftArray(int a[], int n) {
    for (int i = 0; i < n/2; i++)
        swap(a[i], a[n - 1 - i]);
}

int main() {
    int n;
    cout << "Enter the number of elements: "; cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": "; cin >> arr[i];
    }

    reverseFirstHaftArray(arr, n);

    cout << "The new array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}