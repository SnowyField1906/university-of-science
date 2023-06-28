#include <iostream>

using namespace std;


// Em lam tu tuan truoc nhung quen nop a
// Gio em moi phat hien nen cho em nop lai nha thay
// Em cam on a


void stringToArray(string s, string a[]) {
    int i = 0, j = 0;
    while (i < s.length()) {
        if (s[i] == ' ') {
            i++;
            j++;
        }
        else {
            a[j] += s[i];
            i++;
        }
    }
}

string reverseString(string s) {
    string a[100];
    stringToArray(s, a);
    int n = 0;
    while (a[n] != "") n++;
    string result = "";
    for (int i = n - 1; i >= 0; i--) {
        result += a[i];
        if (i != 0) result += " ";
    }
    return result;
}

int main() {
    string s;
    cout << "Enter a string: "; getline(cin, s);
    cout << "Reversed string: " << reverseString(s) << endl;

    return 0;
}