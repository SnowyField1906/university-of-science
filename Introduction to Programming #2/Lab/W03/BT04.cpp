#include <iostream>

using namespace std;

int main() {
    char c;

    cout << "Enter a character: "; cin >> c;

    if (c >= 'a' && c <= 'z') {
        cout << "Uppercased: " << (char)(c + 'A' - 'a') << endl;
    } else if (c >= 'A' && c <= 'Z') {
        cout << "Lowercased: " << (char)(c + 'a' - 'A') << endl;
    } else {
        cout << "Invalid character" << endl;
    }

    return 0;
}