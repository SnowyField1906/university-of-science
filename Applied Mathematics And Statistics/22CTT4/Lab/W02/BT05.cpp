#include <iostream>

using namespace std;

int main() {
    float aWidth, aLength, aHeight, bEdge, cRadius, cHeight;

    cout << "=== Rectangular cuboid ===" << endl;
    cout << "Enter width: "; cin >> aWidth;
    cout << "Enter length: "; cin >> aLength;
    cout << "Enter height: "; cin >> aHeight;

    cout << "Surface area: " << 2 * (aWidth * aLength + aWidth * aHeight + aLength * aHeight) << endl;
    cout << "Volume: " << aWidth * aLength * aHeight << endl;

    cout << endl << "=== Cube ===" << endl;
    cout << "Enter edge: "; cin >> bEdge;

    cout << "Surface area: " << 6 * bEdge * bEdge << endl;
    cout << "Volume: " << bEdge * bEdge * bEdge << endl;

    cout << endl << "=== Cylinder ===" << endl;
    cout << "Enter radius: "; cin >> cRadius;
    cout << "Enter height: "; cin >> cHeight;

    cout << "Surface area: " << 2 * 3.14 * cRadius * cHeight + 2 * 3.14 * cRadius * cRadius << endl;
    cout << "Volume: " << 3.14 * cRadius * cRadius * cHeight << endl;

    return 0;
}