#include <iostream>

using namespace std;

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

string mostFrequentWord(string s) {
    string a[100];
    stringToArray(s, a);
    int n = 0;
    while (a[n] != "") n++;
    int count[100] = { 0 };
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (a[i] == a[j]) count[i]++;
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (count[i] > count[max]) max = i;
    }
    return a[max];
}

int main() {
    string s;
    cout << "Enter a string: "; getline(cin, s);
    cout << "Most frequent word: " << mostFrequentWord(s) << endl;

    return 0;
}