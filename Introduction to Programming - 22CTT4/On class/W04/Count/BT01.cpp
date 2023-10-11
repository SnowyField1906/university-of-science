#include <iostream>

using namespace std;

int countAppear(int arr[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += arr[i] == x;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter the number of elements: "; cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": "; cin >> arr[i];
    }

    int x;
    cout << "Enter the number to count: "; cin >> x;

    cout << "The number " << x << " appears " << countAppear(arr, n, x) << " times";

    return 0;
}