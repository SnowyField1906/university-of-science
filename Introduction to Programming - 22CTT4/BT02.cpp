// 21120566 - Nguyen Huu Thuan
// Bai 2

#include <iostream>

#define PI 3.1415

using namespace std;

struct Diem {
    double x, y;
};

struct DuongTron {
    Diem center;
    double radius;
};

void inputPoint(Diem& p) {
    cout << "\tEnter x: "; cin >> p.x;
    cout << "\tEnter y: "; cin >> p.y;
}

void inputCircle(DuongTron& c) {
    cout << "Enter center: " << endl;
    inputPoint(c.center);
    cout << "Enter radius: "; cin >> c.radius;
}

double Circumference(DuongTron c) {
    return 2 * PI * c.radius;
}

double Area(DuongTron c) {
    return PI * c.radius * c.radius;
}

int main() {
    DuongTron c;
    inputCircle(c);

    cout << endl << "Circumference: " << Circumference(c) << endl;
    cout << "Area: " << Area(c) << endl;

    return 0;
}