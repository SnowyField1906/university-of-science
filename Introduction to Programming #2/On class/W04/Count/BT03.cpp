#include <iostream>

using namespace std;

int countUnique(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        count++;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                count--;
                break;
            }
        }
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

    cout << "The array has " << countUnique(arr, n) << " unique elements";

    return 0;
}