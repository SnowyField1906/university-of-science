#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
using namespace std;

/* vector class template */
template <typename T>
class vector
{
private:
    T *ptr;
    int capacity;
    int sz;

public:
    // Constructors
    vector()
    {
        capacity = 10; // initial capacity
        ptr = new T[capacity];
        sz = 0;
    }

    vector(int cap)
    {
        capacity = cap;
        ptr = new T[capacity];
        sz = 0;
    }

    // Destructor
    ~vector()
    {
        delete[] ptr;
    }

    // Operator[]
    T &operator[](int n)
    {
        return ptr[n];
    }

    // Expand extra memory
    void reserve(int newalloc)
    {
        if (newalloc <= capacity)
            return;

        T *newPtr = new T[newalloc];
        for (int i = 0; i < sz; i++)
        {
            newPtr[i] = ptr[i];
        }
        delete[] ptr;

        ptr = newPtr;
        capacity = newalloc;
    }

    // Push element to the vector
    void push(const T &element)
    {
        if (sz == capacity)
        {
            reserve(capacity * 2); // double the capacity
        }
        ptr[sz] = element;
        sz++;
    }

    // Print the elements in the vector
    void print()
    {
        for (int i = 0; i < sz; i++)
        {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }

    void erase(int index)
    {
        if (index < 0 || index >= sz)
        {
            return;
        }
        for (int i = index; i < sz - 1; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        sz--;
    }

    int size()
    {
        return sz;
    }

    void insert(int index, const T &element)
    {
        if (index < 0 || index > sz)
        {
            return;
        }
        if (sz == capacity)
        {
            reserve(capacity * 2);
        }
        for (int i = sz; i > index; i--)
        {
            ptr[i] = ptr[i - 1];
        }
        ptr[index] = element;
        sz++;
    }

    void clear()
    {
        sz = 0;
    }
};

#endif
