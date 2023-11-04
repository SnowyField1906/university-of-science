#include <iostream>

using namespace std;

int frequency(string s, char c) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == c) count++;
    }
    return count;
}

void mostFrequentCharacter(string s, char &c, int &max) {
    for (int i = 0; i < s.length(); i++) {
        if (frequency(s, s[i]) > max) {
            max = frequency(s, s[i]);
            c = s[i];
        }
    }
}

int main() {
    string s;
    cout << "Enter a string: "; getline(cin, s);

    char c;
    int max = 0;
    mostFrequentCharacter(s, c, max);
    
    cout << endl << "The most frequent character is: '" << c << "' (" << max << " times)" << endl;
    
    return 0;
}