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

bool mirrorPositiveNumber(int x) {
    if(x < 0) return false;
    int y = 0, z = x;
    while (z > 0) {
        y = y * 10 + z % 10;
        z /= 10;
    }
    return (x == y);
}

int subdiagonal(int a[100][100], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += mirrorPositiveNumber(a[i][n - i - 1]);
    }
    return count;
}

int main() {
    int n;
    cout << "Enter edge of the square matrix: "; cin >> n;

    int a[100][100];
    inputMatrix(a, n);

    cout << endl << "Your matrix (random): " << endl; outputMatrix(a, n);

    cout << endl << "Number of mirror positive elements on the subdiagonal: " << subdiagonal(a, n) << endl;

    return 0;
}