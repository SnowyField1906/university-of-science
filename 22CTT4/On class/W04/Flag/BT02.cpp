#include <iostream>

using namespace std;

bool checkMinima(int arr[], int n) {
    bool flag = false;
    for (int i = 1; i < n - 1; i++) {
        if(arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
            flag = true;
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

    cout << "The array" << (checkMinima(arr, n) ? " has " : " doesn't have ") << "minima";

    return 0;
}