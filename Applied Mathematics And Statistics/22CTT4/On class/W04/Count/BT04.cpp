#include <iostream>

using namespace std;

int checkMirror(int arr[], int n) {
    bool flag = true;
    for (int i = 0; i < n / 2; i++) {
        if (arr[i] != arr[n - i - 1]) {
            flag = false;
            break;
        }
    }
    return flag;
}

int main() {
    int n;
    cout << "Enter the number of elements: "; cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": "; cin >> arr[i];
    }

    cout << "The array is" << (checkMirror(arr, n) ? " " : " not ") << "a mirror array";

    return 0;
}