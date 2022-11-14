#include <iostream>

using namespace std;

int main() {
    float a, b, c;
    cout << "Enter first edge: "; cin >> a;
    cout << "Enter second edge: "; cin >> b;
    cout << "Enter third edge: "; cin >> c;

    if (a + b > c && a + c > b && b + c > a) {
        if (a == b && b == c) {
            cout << "This is an equilateral triangle" << endl;
        }
        else if (a == b || b == c || a == c) {
            if(a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
                cout << "This is a right isosceles triangle" << endl;
            }
            else {
                cout << "This is an isosceles triangle" << endl;
            }
        } else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
            cout << "This is a right triangle" << endl;
        } else {
            cout << "This is a scalene triangle" << endl;
        }
    } else {
        cout << "This is not a triangle" << endl;
    }
    

    return 0;
}