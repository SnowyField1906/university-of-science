#include <iostream>
#include <cstdlib>

using namespace std;

int asciiToNumber(string s) {
    int n = 0;
    for (int i = 0; i < s.length(); i++) {
        n += (int)s[i] - 96;
    }
    return n;
}

int main() {
    string s[11] = {"potter", "weasley", "granger", "dumbledore", "voldermort", "hagrid", "dobby", "malfoy", "snape", "mcgonagall", "black"};
    for (int i = 0; i < 11; i++) {
        cout << s[i] << " = " << asciiToNumber(s[i]) << endl;
    }
}