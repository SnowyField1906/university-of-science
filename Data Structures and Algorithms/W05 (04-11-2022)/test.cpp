#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// 4 2 6 2 2 2 1 2

struct Word {
    string word;
    int count;
};

int majorityElement1(int A[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i] == A[j]) {
                count++;
            }
        }
        if (count > n / 2) {
            return A[i];
        }
        count = 0;
    }
    return 0;
}

int majorityElement2(int A[], int n) {
    int count = 1;
    int elem = A[0];
    for (int i = 1; i < n; i++) {
        count += 2*(A[i] == elem) - 1;
        if (count == 0) {
            if(i == n-1) return count;
            elem = A[i];
            count = 1;
        }
    }
    return elem;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

vector<Word> worldCloudProblem1(string W[], int n) {
    vector<Word> words;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < words.size(); j++) {
            if (W[i] == words[j].word) {
                words[j].count++;
                found = true;
                break;
            }
        }
        if (!found) {
            Word word;
            word.word = W[i];
            word.count = 1;
            words.push_back(word);
        }
    }
    return words;
}

vector<int> seeSaw(vector<int> hat, int left, int right) {
    sort(hat.begin(), hat.end(), greater<int>());

    for (int i = 0; i < hat.size(); i++) {
        int found = binary_search(hat.begin() + i, hat.end(), abs(hat.at(i) + abs(left - right)));
        if (found) {
            return vector<int>(hat.at(i), hat.at(found));
        }
    }
    return vector<int>(0, 0);
}

// int main() {
//     int A[10];
//     int n;
//     cout << "Enter the array's length: "; cin >> n;
//     for (int i = 0; i < n; i++) {
//         cout << "Element " << i + 1 << ": "; cin >> A[i];
//     }
//     int major = majorityElement1(A, n);
//     if (majorityElement1(A, n))
//         cout << "The majority element is " << major;
//     else
//         cout << "There is no majority element";

//     return 0;

// }

// int main() {
//     string W[] = {"apple", "banana", "apple", "apple", "dog", "cat", "dog", "dog", "dog", "dog", "dog"};
//     vector<Word> words = worldCloudProblem1(W, 11);
//     for (int i = 0; i < words.size(); i++) {
//         cout << words[i].word << "=" << words[i].count << " " << endl;
//     }

//     return 0;
// }

int main() {
    int n;
    vector<int> hat;
    cout << "Enter hat's length: "; cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        hat.push_back(a);
    }

    int left, right;
    cout << "Enter left: "; cin >> left;
    cout << "Enter right: "; cin >> right;

    vector<int> pair = seeSaw(hat, left, right);
    cout << pair.at(0) << " and " << pair.at(1);

    return 0;
}