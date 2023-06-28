#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cassert>
using namespace std;
class Stack
{
private:
    int *ptr;
    int capacity;
    int size;

public:
    // Constructor
    Stack(int capacity);
    // destructor
    ~Stack();
    // Thêm phần tử vào stack, them vào cuối
    void push(const int &element);
    // Lấy phần tử khỏi stack, Lấy ra ở cuối theo LIFO
    int pop();
};
#endif