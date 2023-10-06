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

bool saddlePoint(int a[100][100], int n, int i, int j) {
    int min = a[i][0], minIndex = 0;
    for (int k = 1; k < n; k++) {
        if (a[i][k] < min) {
            min = a[i][k];
            minIndex = k;
        }
    }
    int max = a[0][minIndex];
    for (int k = 1; k < n; k++) {
        if (a[k][minIndex] > max) {
            max = a[k][minIndex];
        }
    }
    return min == max && min == a[i][j];
}

int numberOfSaddlePoints(int a[100][100], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            count += saddlePoint(a, n, i, j);
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

    cout << endl << "Number of saddle points: " << numberOfSaddlePoints(a, n) << endl;

    return 0;
}