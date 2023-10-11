#include <iostream>

using namespace std;


string bubbleSortedString(string s) {
    for (int i = 0; i < s.length() - 1; i++) {
        for (int j = i + 1; j < s.length(); j++) {
            if (s[i] > s[j]) swap(s[i], s[j]);
        }
    }
    return s;
}


int main() {
    string s;
    cout << "Enter a string: "; getline(cin, s);

    cout << endl << "Your string after sorting: " << bubbleSortedString(s) << endl;

    return 0;
}