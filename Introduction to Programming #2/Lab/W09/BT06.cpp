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

int squareNumber(int x) {
    for(int i = 1; i*i <= x; i++) {
        if(i*i == x) return x;
    }
    return 0;
}

int aboveMainDiagonal(int a[100][100], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            sum += squareNumber(a[i][j]);
        }
    }
    return sum;
}

int belowSubdiagonal(int a[100][100], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            sum += squareNumber(a[i][j]);
        }
    }
    return sum;
}


int main() {
    int n;
    cout << "Enter edge of the square matrix: "; cin >> n;

    int a[100][100];
    inputMatrix(a, n);

    cout << endl << "Your matrix (random): " << endl; outputMatrix(a, n);

    cout << endl << "Sum of perfect square elements above the main diagonal: " << aboveMainDiagonal(a, n) << endl;
    cout << endl << "Sum of perfect square elements below the subdiagonal: " << belowSubdiagonal(a, n) << endl;

    return 0;
}