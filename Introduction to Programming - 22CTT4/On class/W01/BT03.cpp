#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float x;
    cout << "Input x: ";
    cin >> x;
    
    float f = -2 * x * x * x + 7 * x * x + 8;
    cout << fixed << setprecision(3) << "f(x) = " << f << endl;

    return 0;
}