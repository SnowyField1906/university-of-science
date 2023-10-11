#include <iostream>
#include <iomanip>

using namespace std;


void inputMatrix(int a[100][100], int n) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = rand() % 190 + 10; //[10;199]
}

void outputMatrix(int a[100][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}


void ascendingSubdiagonal(int a[100][100], int n) {
    int subdiagonal[n];
    for (int i = n - 1; i >= 0; i--) {
        subdiagonal[i] = a[i][n - 1 - i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (subdiagonal[i] < subdiagonal[j]) {
                swap(subdiagonal[i], subdiagonal[j]);
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        a[i][n - 1 - i] = subdiagonal[i];
    }
}

void descendingSubdiagonal(int a[100][100], int n) {
    int subdiagonal[n];
    for (int i = n - 1; i >= 0; i--) {
        subdiagonal[i] = a[i][n - 1 - i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (subdiagonal[i] > subdiagonal[j]) {
                swap(subdiagonal[i], subdiagonal[j]);
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        a[i][n - 1 - i] = subdiagonal[i];
    }
}

int main() {
    int n;
    cout << "Enter edge of the square matrix: "; cin >> n;

    int a[100][100];
    inputMatrix(a, n);

    cout << endl << "Your matrix (random): " << endl; outputMatrix(a, n);

    cout << endl << "After sorting ascending subdiagonal (from bottom): " << endl;
    ascendingSubdiagonal(a, n);
    outputMatrix(a, n);

    cout << endl << "After sorting descending subdiagonal (from bottom): " << endl;
    descendingSubdiagonal(a, n);
    outputMatrix(a, n);

    return 0;
}