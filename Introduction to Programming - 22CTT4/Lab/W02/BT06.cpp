#include<iostream>
#include<math.h>
using namespace std;

int main() {
    float edge, radius;
	cout << "Enter the edge of the triangle: "; cin >> edge;
    cout << "Enter the radius of the circle: "; cin >> radius;
	
	cout << "Area: " << 3.14 * pow(radius, 2) / 2 + 3 * sqrt(3) / 4 * pow(edge, 2);

    return 0;
}