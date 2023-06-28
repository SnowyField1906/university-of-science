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

int mirrorPositiveNumber(int x) {
    if(x < 0) return 0;
    int y = 0, z = x;
    while (z > 0) {
        y = y * 10 + z % 10;
        z /= 10;
    }
    if(x == y) return x;
    return 0;
}

int mainDiagonal(int a[100][100], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += mirrorPositiveNumber(a[i][i]);
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter edge of the square matrix: "; cin >> n;

    int a[100][100];
    inputMatrix(a, n);

    cout << endl << "Your matrix (random): " << endl; outputMatrix(a, n);

    cout << endl << "Sum of mirror positive elements on the main diagonal: " << mainDiagonal(a, n) << endl;

    return 0;
}