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

int localExtrema(int a[100][100], int n, int m, int i, int j) {
    if (i == 0 || i == n - 1 || j == 0 || j == m - 1) return 0;
    if (a[i][j] > a[i - 1][j] && a[i][j] > a[i + 1][j] && a[i][j] > a[i][j - 1] && a[i][j] > a[i][j + 1]) return a[i][j];
    if (a[i][j] < a[i - 1][j] && a[i][j] < a[i + 1][j] && a[i][j] < a[i][j - 1] && a[i][j] < a[i][j + 1]) return a[i][j];
    return 0;
}

int numberOfLocalExtremas(int a[100][100], int n, int m) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += localExtrema(a, n, m, i, j);
        }
    }
    return sum;
}


int main() {
    int n, m;
    cout << "Enter number of rows: "; cin >> n;
    cout << "Enter number of columns: "; cin >> m;

    int a[100][100];
    inputMatrix(a, n, m);

    cout << endl << "Your matrix (random): " << endl; outputMatrix(a, n, m);

    cout << endl << "Number of local extremas: " << numberOfLocalExtremas(a, n, m) << endl;

    return 0;
}