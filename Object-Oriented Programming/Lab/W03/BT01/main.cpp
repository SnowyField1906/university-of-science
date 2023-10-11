#include <iostream>
#include "myArray.cpp"

using namespace std;

int main() {
    // parameter constructor
    MyIntArray arr1(5);
    for (int i = 0; i < 5; i++) {
        arr1[i] = i + 1;
    }

    // copy constructor
    MyIntArray arr2(arr1);

    // assignment operator
    MyIntArray arr3 = arr1;

    cout << "Array 1: ";
    arr1.print();

    cout << "Array 2: ";
    arr2.print();

    cout << "Array 3: ";
    arr3.print();

    // overloading [] operator
    arr1[2] = 0;
    cout << endl << "Array 1: Changed arr[2] into 0 successfully!" << endl;

    cout << "Array 1: ";
    arr1.print();

    cout << "Array 2: ";
    arr2.print();

    cout << "Array 3: ";
    arr3.print();

    return 0;
}
