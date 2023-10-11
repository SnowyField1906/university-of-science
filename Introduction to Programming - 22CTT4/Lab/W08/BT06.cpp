#include <iostream>

using namespace std;

void inputArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\tElement " << i + 1 << ": "; cin >> a[i];
    }
}

void outputArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void ascendingSubarray(int a[], int n, int &start, int &end) {
    int max = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (i == n - 1 || a[i] > a[i + 1]) {
            if (count > max) {
                max = count;
                start = i - max;
                end = i;
            }
            count = 0;
        }
        count += a[i] <= a[i + 1];

    }

}

int main() {
    int n;
    cout << "Enter number of elements: "; cin >> n;
    
    int a[n];
    cout << endl << "Enter elements of array:" << endl;
    inputArray(a, n);
    
    int start, end;
    ascendingSubarray(a, n, start, end);
    
    cout << endl << "The longest ascending subarray is: "; outputArray(a + start, end - start + 1);
    
    return 0;
}