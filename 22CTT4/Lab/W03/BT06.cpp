#include<iostream>

using namespace std;

int main() {
    float maths, physics, chemistry, average;

    cout << "Enter maths mark: "; cin >> maths;
    cout << "Enter physics mark: "; cin >> physics;
    cout << "Enter chemistry mark: "; cin >> chemistry;

    average = (maths + physics + chemistry) / 3;

    cout << "Average: " << average << " ";

    if(average >= 9) {
        cout << "(Excellent)" << endl;
    } else if(average >= 8) {
        cout << "(Very good)" << endl;
    } else if(average >= 6.5) {
        cout << "(Good)" << endl;
    } else if(average >= 5) {
        cout << "(Average)" << endl;
    } else if(average >= 3.5) {
        cout << "(Weak)" << endl;
    } else {
        cout << "(Poor)" << endl;
    }

    return 0;
}