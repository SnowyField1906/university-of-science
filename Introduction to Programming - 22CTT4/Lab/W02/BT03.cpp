#include <iostream>

using namespace std;

int main() {
    float radius;
    cout << "Enter radius: "; cin >> radius;

    cout << "Circumference: " << 2 * 3.14 * radius << endl;
    cout << "Area: " << 3.14 * radius * radius << endl;

    return 0;
}