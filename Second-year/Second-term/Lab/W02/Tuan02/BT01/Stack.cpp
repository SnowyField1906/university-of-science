#include "Stack.h"

Stack::Stack(int capacity)
{
    ptr = new int[capacity];
    this->capacity = capacity;
    size = 0;
}

Stack::~Stack()
{
    delete[] ptr;
}

void Stack::push(const int &element)
{
    assert(size < capacity);
    ptr[size++] = element;
}

int Stack::pop()
{
    assert(size > 0);
    return ptr[--size];
}
