#include <iostream>

using namespace std;


string prettifyNumberWithCommas(int n) {
    int num[10];
    int count = 0;

    while (n > 0) {
        num[count] = n % 1000;
        n /= 1000;
        count++;
    }


    string s = "";
    for (int i = count - 1; i >= 0; i--) {
        s += to_string(num[i]);
        if (i != 0) {
            s += ",";
        }
    }

    return s;
}

int main() {
    int n;
    cout << "Enter a number: "; cin >> n;

    cout << endl << "Your number after prettifying: " << prettifyNumberWithCommas(n) << endl;

    return 0;
}