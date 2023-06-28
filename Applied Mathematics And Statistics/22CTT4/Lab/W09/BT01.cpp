#include <iostream>
#include <iomanip>

using namespace std;

void inputMatrix(int a[100][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = rand() % 190 + 10; //[10;199]
        }
    }
}

void outputMatrix(int a[100][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int minimumPositiveElement(int a[100][100], int n, int m) {
    int min = a[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] > 0 && a[i][j] < min) min = a[i][j];
        }
    }
    return min;
}

int main() {
    int n, m;
    cout << "Enter number of columns: "; cin >> m;
    cout << "Enter number of rows: "; cin >> n;

    int a[100][100];
    inputMatrix(a, n, m);

    cout << endl << "Your matrix (random): " << endl; outputMatrix(a, n, m);

    cout << endl << "Minimum positive element: " << minimumPositiveElement(a, n, m) << endl;

    return 0;
}