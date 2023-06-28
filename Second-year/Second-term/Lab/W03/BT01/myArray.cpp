#include <iostream>
#include "myArray.h"

using namespace std;

// Default constructor
MyIntArray::MyIntArray() {
    size = 0;
    pArr = nullptr;
}

//Parameter Constructors: Using input items of array
MyIntArray::MyIntArray(int sz) {
    size = sz;
    pArr = new int[size];
    for (int i = 0; i < size; i++) {
        pArr[i] = 0;
    }
}

// Destructor
MyIntArray::~MyIntArray() {
    if (pArr != nullptr) {
        delete[] pArr;
    }
}

// Overloading [] operator to access elements in array
int& MyIntArray::operator[](int index) {
    return pArr[index];
}

// Copy Constructor
MyIntArray::MyIntArray(const MyIntArray& arr) {
    size = arr.size;
    pArr = new int[size];
    for (int i = 0; i < size; i++) {
        pArr[i] = arr.pArr[i];
    }
}

// Assignment Operator Overloading
MyIntArray& MyIntArray::operator=(const MyIntArray& arr) {
    if (this != &arr) {
        size = arr.size;
        if (pArr != nullptr) {
            delete[] pArr;
        }
        pArr = new int[size];
        for (int i = 0; i < size; i++) {
            pArr[i] = arr.pArr[i];
        }
    }
    return *this;
}

// xuat mang
void MyIntArray::print() {
    for (int i = 0; i < size; i++) {
        cout << pArr[i] << " ";
    }
    cout << endl;
}
