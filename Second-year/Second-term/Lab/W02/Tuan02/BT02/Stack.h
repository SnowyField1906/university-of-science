#ifndef STACK_H
#define STACK_H
#include "List.h"
// Dinh nghia lop Stack su dung doi tuong list
class Stack
{
private:
    List list;

public:
    void push(const string &val);
    void pop();
    string top() const;
    int size() const;
};
#endif