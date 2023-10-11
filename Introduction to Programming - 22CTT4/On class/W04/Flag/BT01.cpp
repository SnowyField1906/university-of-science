#include <iostream>

using namespace std;

bool checkAlternating(int arr[], int n) {
    bool flag = true;
    bool check = arr[0] % 2 == 0;
    for (int i = 0; i < n; i++) {
        check ^= true;
        if (arr[i] % 2 != check) {
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

    cout << "The array is" << (checkAlternating(arr, n) ? " " : " not ") << "alternating odd-even";

    return 0;
}