#include <iostream>

using namespace std;

void inputArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": "; cin >> a[i];
    }
}

bool isUniformContinuit(int a[], int n) {
    bool sign = a[1] - a[0] > 0;
    for (int i = 1; i < n - 1; i++) {
        if ((a[i + 1] - a[i] > 0) != sign) return false;
    }
    return true;
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[j - 1]) swap(a[j], a[j - 1]);
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: "; cin >> n;
    
    int a[n];
    inputArray(a, n);

    if (isUniformContinuit(a, n))cout << "The array is uniformly continuous" << endl;
    else {
        cout << "The array is not uniformly continuous" << endl; bubbleSort(a, n);
        cout << "Sorted array: ";
        for (int i = 0; i < n; i++) cout << a[i] << " ";
    }
 

    return 0;
}