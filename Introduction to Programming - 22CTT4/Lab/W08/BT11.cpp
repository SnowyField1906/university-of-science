#include <iostream>

using namespace std;


// Gia su vi tri dau tien la 0


void frequencyS1InS2(string s1, string s2, int positions[], int &count) {
    count = 0;
    for (int i = 0; i < s2.length(); i++) {
        if (s2[i] == s1[0]) {
            bool isSame = true;
            for (int j = 0; j < s1.length(); j++) {
                if (s2[i + j] != s1[j]) {
                    isSame = false;
                    break;
                }
            }
            if (isSame) {
                positions[count] = i;
                count++;
            }
        }
    }
}

int main() {
    string s1, s2;
    cout << "Enter string 1: "; getline(cin, s1);
    cout << "Enter string 2: "; getline(cin, s2);

    int positions[s2.length()];
    int count;
    frequencyS1InS2(s1, s2, positions, count);

    cout << endl << "Your string 1 appears " << count << " times in string 2 at positions: ";
    for (int i = 0; i < count; i++) {
        cout << positions[i] << " ";
    }

    return 0;
}