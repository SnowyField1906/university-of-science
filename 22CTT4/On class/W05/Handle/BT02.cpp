#include <iostream>

using namespace std;

void subarrays(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 2; j < n; j++) {
            for (int k = i; k <= j; k++)
                cout << a[k] << " ";
            cout << endl;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: "; cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": "; cin >> arr[i];
    }   

    subarrays(arr, n);


    return 0;
}