#include <iostream>

using namespace std;

bool substring(string s1, string s2) {
    int n = s2.length(), m = s1.length();
    for (int i = 0; i < n; i++) {
        if (s2[i] == s1[0]) {
            bool flag = true;
            for (int j = 1; j < m; j++) {
                if (s2[i + j] != s1[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) return true;
        }
    }
    return false;
}

int main() {
    string s1, s2;
    cout << "Enter string 1: "; getline(cin, s1);
    cout << "Enter string 2: "; getline(cin, s2);

    if (substring(s1, s2)) cout << "String 1 is a substring of string 2" << endl;
    else cout << "String 1 is not a substring of string 2" << endl;

    return 0;
}