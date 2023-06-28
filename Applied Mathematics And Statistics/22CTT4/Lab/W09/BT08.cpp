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

bool queenPoint(int a[100][100], int n, int i, int j) {
    for (int k = 0; k < n; k++) {
        if (a[i][k] > a[i][j] || a[k][j] > a[i][j]) {
            return false;
        }
    }
    int i1 = i, j1 = j, i2 = i, j2 = j;
    while (i1 > 0 && j1 > 0) {
        i1--; j1--;
        if (a[i1][j1] > a[i][j]) return false;
    }
    while (i2 < n - 1 && j2 < n - 1) {
        i2++; j2++;
        if (a[i2][j2] > a[i][j]) return false;
    }
    return true;
}

int numberOfQueenPoints(int a[100][100], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            count += queenPoint(a, n, i, j);
        }
    }
    return count;
}


int main() {
    int n;
    cout << "Enter edge of the square matrix: "; cin >> n;

    int a[100][100];
    inputMatrix(a, n);

    cout << endl << "Your matrix (random): " << endl; outputMatrix(a, n);

    cout << endl << "Number of queen points: " << numberOfQueenPoints(a, n) << endl;

    return 0;
}