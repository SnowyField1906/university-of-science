// 21120566 - Nguyen Huu Thuan
// Bai 1

#include <iostream>

using namespace std;

void inputMatrix(char a[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        cout << "Enter row " << i + 1 << ": " << endl;
        for (int j = 0; j < m; j++) {
            cout << "\ta[" << i << "][" << j << "] = "; cin >> a[i][j];
        }
    }
}


void outputMatrix(char a[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkTwoSidedMatrix(char a[][100], int n, int m) {
    for (int i1 = 0; i1 < n; i1++) {
        for (int i2 = 0; i2 < n; i2++) {
            if (a[i1][0] == a[i2][m - 1]) return true;
        }
    }

    return false;
}

int main() {
    char a[100][100];
    int n, m;
    cout << "Enter number of rows: "; cin >> n;
    cout << "Enter number of columns: "; cin >> m;

    inputMatrix(a, n, m);
    outputMatrix(a, n, m);
    
    if (checkTwoSidedMatrix(a, n, m)) cout << "Yes";
    else cout << "No";

    return 0;
}
