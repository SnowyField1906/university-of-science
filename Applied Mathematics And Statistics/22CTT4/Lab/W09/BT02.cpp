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

int minimumBoundaryElement(int a[100][100], int n, int m) {
    int min = a[0][0];
    for (int i = 0; i < n; i++) {
        if(a[i][0] < min) min = a[i][0];
        if(a[i][m - 1] < min) min = a[i][m - 1];
    }
    for (int j = 1; j < m - 1; j++) {
        if(a[0][j] < min) min = a[0][j];
        if(a[n - 1][j] < min) min = a[n - 1][j];
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

    cout << endl << "Minimum boundary element: " << minimumBoundaryElement(a, n, m) << endl;

    return 0;
}