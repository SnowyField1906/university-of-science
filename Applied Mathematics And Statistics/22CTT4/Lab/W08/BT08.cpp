#include <iostream>

using namespace std;

char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

char toUpper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 32;
    }
    return c;
}

string trim(string s) {
    string result = "";
    int i = 0, j = s.length() - 1;
    while (s[i] == ' ') i++;
    while (s[j] == ' ') j--;
    for (int k = i; k <= j; k++) {
        result += s[k];
    }
    return result;
}

string prettifyName(string s) {
    s = trim(s);
    string result = "";
    
    result += toUpper(s[0]);

    for (int i = 1; i < s.length(); i++) {
        if (s[i] == ' ') {
            result += s[i];
            while (s[i] == ' ') i++;
            result += toUpper(s[i]);
        } else result += toLower(s[i]);
    }
    return result;
}

int main() {
    string s;
    cout << "Enter a name: "; getline(cin, s);
    
    cout << endl << "Prettified name: " << prettifyName(s) << endl;
    
    return 0;
}