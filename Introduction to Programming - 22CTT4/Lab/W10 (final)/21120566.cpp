/*
 * Ho va ten: Nguyen Huu Thuan
 * MSSV     : 21120566
 * Nhom     : 3 - 22CTT4C
 */

#include <iostream>
#define MAX 10

using namespace std;

struct Fraction {
    int num;
    int den;
};

void inputMatrix(Fraction a[MAX][MAX], int &m, int &n) {
    cout << "Nhap so dong: "; cin >> m;
    cout << "Nhap so cot: "; cin >> n;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            Fraction frac;
            frac.num = rand() % 190 + 10;
            frac.den = rand() % 190 + 10;
            a[i][j] = frac;
        }
    }
}

void outputMatrix(Fraction a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j].num << "/" << a[i][j].den << "  ";
        }
        cout << endl;
    }
}

void outputArray(Fraction b[MAX], int k) {
    for (int i = 0; i < k; i++)
        cout << b[i].num << "/" << b[i].den << "  ";
    cout << endl;
}

bool compareFraction(Fraction f1, Fraction f2) {
    return f1.num * f2.den - f1.den * f2.num > 0;
}

Fraction maxFractionInMatrix(Fraction a[MAX][MAX], int m, int n) {
    Fraction max = a[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (compareFraction(a[i][j], a[i][j - 1])) {
                max = a[i][j];
            }
        }
    }
    return max;
}

bool queenFraction(Fraction a[MAX][MAX], int m, int n, int i, int j) {
    for (int k = 0; k < m; k++) {
        for (int p = 0; p < n; p++) {
            if (compareFraction(a[i][p], a[i][j]) || compareFraction(a[k][j], a[i][j]))
                return false;
        }
    }
    
    int i1 = i, j1 = j, i2 = i, j2 = j;
    while (i1 > 0 && j1 > 0) {
        i1--; j1--;
        if (compareFraction(a[i1][j1], a[i][j])) return false;
    }
    while (i2 < m - 1 && j2 < n - 1) {
        i2++; j2++;
        if (compareFraction(a[i2][j2], a[i][j])) return false;
    }
    return true;
}

void queenFractions(Fraction a[MAX][MAX], int m, int n, Fraction b[MAX], int &k) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (queenFraction(a, m, n, i, j))
                b[k++] = a[i][j];
        }
    }
}

Fraction simplify(Fraction frac) {
    int a = frac.num, b = frac.den;
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    frac.num /= a;
    frac.den /= a;
    return frac;
}

void simplifyMatrix(Fraction a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = simplify(a[i][j]);
        }
    }
}

int main() {
    Fraction a[MAX][MAX];
    int m, n;
    inputMatrix(a, m, n);
    outputMatrix(a, m, n);

    cout << endl << "==== CAU 1 ====" << endl;
    Fraction max = maxFractionInMatrix(a, m, n);
    cout << "Max fraction in matrix: " << max.num << "/" << max.den << endl;

    cout << endl << "==== CAU 2 ====" << endl;
    Fraction b[MAX];
    int k = 0;
    queenFractions(a, m, n, b, k);
    cout << "Queen fractions in matrix: ";
    outputArray(b, k);

    cout << endl << "==== CAU 3 ====" << endl;
    simplifyMatrix(a, m, n);
    cout << "After simplifying: " << endl;
    outputMatrix(a, m, n);

    return 0;
}
