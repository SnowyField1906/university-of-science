#include <iostream>

using namespace std;


int main() {
    int w, h;
    cout << "Enter width: "; cin >> w;
    cout << "Enter height: "; cin >> h;

    cout << "Perimeter: " << 2 * (w + h) << endl;
    cout << "Area: " << w * h << endl << endl;

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (i == 0 || i == w - 1 || j == 0 || j == h - 1)  cout << "*";
            else cout << " ";
        }
        cout << endl;
    }

    return 0;
}