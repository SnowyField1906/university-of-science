#include <iostream>

using namespace std;


int main() {
    int n;
    cout << "Enter a number: "; cin >> n;

    int reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    
    cout << "Reversed number: " << reversed << endl;

    return 0;
}