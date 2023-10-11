#include <iostream>

using namespace std;

bool validDate(int d, int m, int y) {
    if (d < 1 || d > 31 || m < 1 || m > 12 || y < 0) return false;
    if (m == 2) {
        if ((y % 4 == 0 && y % 100 != 0 || y % 400 == 0) && d > 29) return false;
        else if (d > 28) return false;
    }
    else if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) return false;
    return true;
}

int daysOfMonth(int m, int y) {
    if (m == 2) {
        if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) return 29;
        else return 28;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    else return 31;
}

void yesterday(int d1, int m1, int y1, int& d2, int& m2, int& y2) {
    if (d1 == 1) {
        if (m1 == 1) {
            d2 = 31;
            m2 = 12;
            y2 = y1 - 1;
        }
        else {
            d2 = daysOfMonth(m1 - 1, y1);
            m2 = m1 - 1;
            y2 = y1;
        }
    }
    else {
        d2 = d1 - 1;
        m2 = m1;
        y2 = y1;
    }
}


void tomorrow(int d1, int m1, int y1, int& d2, int& m2, int& y2) {
    if (d1 == daysOfMonth(m1, y1)) {
        if (m1 == 12) {
            d2 = 1;
            m2 = 1;
            y2 = y1 + 1;
        }
        else {
            d2 = 1;
            m2 = m1 + 1;
            y2 = y1;
        }
    }
    else {
        d2 = d1 + 1;
        m2 = m1;
        y2 = y1;
    }
}

void dateAfterKDays(int d1, int m1, int y1, int k, int& d2, int& m2, int& y2) {
    d2 = d1; m2 = m1; y2 = y1;
    for (int i = 0; i < k; i++) {
        tomorrow(d2, m2, y2, d2, m2, y2);
    }
}

void dateBeforeKDays(int d1, int m1, int y1, int k, int& d2, int& m2, int& y2) {
    d2 = d1; m2 = m1; y2 = y1;
    for (int i = 0; i < k; i++) {
        yesterday(d2, m2, y2, d2, m2, y2);
    }
}

int weekday(int d, int m, int y) {
    return (d + 2*m + 3*(m + 1)/5 + y + y/4 - y/100 + y/400 + 2) % 7;
}

int weekInYear(int d, int m, int y) {
    int w = weekday(d, m, y);
    int k = 0;
    for (int i = 1; i < m; i++) k += daysOfMonth(i, y);
    k += d;
    return (k - w + 6) / 7;
}

int main() {
    int d1, m1, y1, d2, m2, y2;

    cout << "Enter day: "; cin >> d1;
    cout << "Enter month: "; cin >> m1;
    cout << "Enter year: "; cin >> y1;

    d2 = d1; m2 = m1; y2 = y1;

    if (validDate(d1, m1, y1)) {
        tomorrow(d1, m1, y1, d2, m2, y2);
        cout << endl << "Tomorrow: " << d2 << "/" << m2 << "/" << y2 << endl;
        yesterday(d1, m1, y1, d2, m2, y2);
        cout << "Yesterday: " << d2 << "/" << m2 << "/" << y2 << endl;

        int k;
        cout << endl << "Enter k: "; cin >> k;

        dateAfterKDays(d1, m1, y1, k, d2, m2, y2);
        cout << "After " << k << " days: " << d2 << "/" << m2 << "/" << y2 << endl;
        dateBeforeKDays(d1, m1, y1, k, d2, m2, y2);
        cout << "Before " << k << " days: " << d2 << "/" << m2 << "/" << y2 << endl;

        cout << endl << "Weekday: " << weekday(d1, m1, y1) << endl;
        cout << "Ordinal week in year: " << weekInYear(d1, m1, y1) << endl;
    }
    else cout << "Invalid date" << endl;

    return 0;
}