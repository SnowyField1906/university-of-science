/*****************************************************
* myArray class, myArray.h
******************************************************/
#ifndef array_H
#define array_H
#include <iostream>
using namespace std;

class MyIntArray {
private:
    int* pArr;
    int size;
public:
    // Default Constructor
    MyIntArray();
    //Parameter Constructors: Using input items of array
    MyIntArray(int sz);
    // Destructor
    ~MyIntArray();
    // Overloading [] operator to access elements in array
    int& operator[](int);
    // Copy Constructor
    MyIntArray(const MyIntArray&);
    // Assignment Operator Overloading
    MyIntArray& operator=(const MyIntArray&);
    // xuat mang
    void print();
};
#endif