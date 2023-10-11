#include <iostream>

using namespace std;

int main() {
    float length, width;
    cout << "Enter length: "; cin >> length;
    cout << "Enter width: "; cin >> width;

    cout << "Perimeter: " << 2 * (length + width) << endl;
    cout << "Area: " << length * width << endl;
    
    return 0;
}