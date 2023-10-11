#include <iostream>

using namespace std;

int main() {
    float perimeter;

    cout << "Enter perimeter: "; cin >> perimeter;

    float width = perimeter / 5;

    cout << "Area: " <<  width * width * 1.5 << endl;

    return 0;
}