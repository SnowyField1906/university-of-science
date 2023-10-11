#include <iostream>
#include <iomanip>

using namespace std;


// Gia su vi tri dau tien bat dau tu 0


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

void onlyEvenRows(int a[100][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < m; j++) {
            if (a[i][j] % 2 != 0) flag = false;
        }
        if (flag) cout << i << " ";
    }
}

int main() {
    int n, m;
    cout << "Enter number of columns: "; cin >> m;
    cout << "Enter number of rows: "; cin >> n;

    int a[100][100];
    inputMatrix(a, n, m);

    cout << endl << "Your matrix (random): " << endl; outputMatrix(a, n, m);

    cout << endl << "All even rows: " << endl; onlyEvenRows(a, n, m);

    return 0;
}