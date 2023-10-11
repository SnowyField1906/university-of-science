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

int frequency(int a[100][100], int n, int m, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == x) count++;
        }
    }
    return count;
}

int mostFrequentNumber(int a[100][100], int n, int m) {
    int max = 0, maxNumber = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (frequency(a, n, m, a[i][j]) > max) {
                max = frequency(a, n, m, a[i][j]);
                maxNumber = a[i][j];
            }
        }
    }
    return maxNumber;
}


int main() {
    int n, m;
    cout << "Enter number of rows: "; cin >> n;
    cout << "Enter number of columns: "; cin >> m;

    int a[100][100];
    inputMatrix(a, n, m);

    cout << endl << "Your matrix (random): " << endl; outputMatrix(a, n, m);

    cout << endl << "Most frequent number: " << mostFrequentNumber(a, n, m) << endl;

    return 0;
}