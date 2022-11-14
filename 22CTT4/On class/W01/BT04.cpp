#include <iostream>

#define PI 3.14159265

using namespace std;

int main() {
    float r;
    cout << "Input radius: ";
    cin >> r;
    cout << "Circumference: " << 2 * PI * r << endl;
    cout << "Area: " << PI * r * r << endl;

    return 0;
}