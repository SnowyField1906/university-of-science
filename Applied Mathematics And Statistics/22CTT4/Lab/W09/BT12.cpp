#include <iostream>
#include <iomanip>

using namespace std;


void inputMatrix(int a[100][100], int n, int m) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = rand() % 190 + 10; //[10;199]
}

void outputMatrix(int a[100][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}


void sortBoundaryElements(int a[100][100], int n, int m) {
    int boundary[100];
    int k = 0;
    for (int i = 0; i < m; i++) {
        boundary[k++] = a[0][i];
    }
    for (int i = 1; i < n; i++) {
        boundary[k++] = a[i][m - 1];
    }
    for (int i = m - 2; i >= 0; i--) {
        boundary[k++] = a[n - 1][i];
    }
    for (int i = n - 2; i >= 1; i--) {
        boundary[k++] = a[i][0];
    }

    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (boundary[i] > boundary[j]) {
                swap(boundary[i], boundary[j]);
            }
        }
    }

    k = 0;
    for (int i = 0; i < m; i++) {
        a[0][i] = boundary[k++];
    }
    for (int i = 1; i < n; i++) {
        a[i][m - 1] = boundary[k++];
    }
    for (int i = m - 2; i >= 0; i--) {
        a[n - 1][i] = boundary[k++];
    }
    for (int i = n - 2; i >= 1; i--) {
        a[i][0] = boundary[k++];
    }
}


int main() {
    int n, m;
    cout << "Enter number of rows: "; cin >> n;
    cout << "Enter number of columns: "; cin >> m;

    int a[100][100];
    inputMatrix(a, n, m);

    cout << endl << "Your matrix (random): " << endl; outputMatrix(a, n, m);

    cout << endl << "After sorting clock-wise boundary elements: " << endl;
    sortBoundaryElements(a, n, m);
    outputMatrix(a, n, m);

    return 0;
}