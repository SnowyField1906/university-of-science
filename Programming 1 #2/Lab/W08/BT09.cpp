#include <iostream>

using namespace std;


// Gia su vi tri dau tien la 0


string deleteNCharacters(string s, int n, int i) {
    while(s[i] != '\0' && n > 0) {
        for (int j = i; j < s.length(); j++) {
            s[j] = s[j + 1];
        }
        n--;
    }
    return s;
}

int main() {
    string s;
    cout << "Enter a string: "; getline(cin, s);

    int n, i;
    cout << endl << "Enter position of element to delete: "; cin >> i;
    cout << "Enter number of elements to delete: "; cin >> n;

    cout << endl << "Your string after deleting: " << deleteNCharacters(s, n, i) << endl;

    return 0;
}