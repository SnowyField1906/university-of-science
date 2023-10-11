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
        ptr = new T[10];
        capacity = 10;
        sz = 0;
    }
    vector(int cap)
    {
        ptr = new T[cap];
        capacity = cap;
        sz = 0;
    }
    ~vector()
    {
        delete[] ptr;
    }

    // utilities methods
    /* operator[] */
    T &operator[](int n)
    {
        return ptr[n];
    }
    /* Expand extra memory */
    void reserve(int newalloc)
    {
        if (newalloc > capacity)
        {
            T *newptr = new T[newalloc];
            for (int i = 0; i < sz; i++)
            {
                newptr[i] = ptr[i];
            }
            delete[] ptr;
            ptr = newptr;
            capacity = newalloc;
        }
    }
    // input, output
    void push(const T &element)
    {
        if (sz == capacity)
        {
            reserve(2 * capacity);
        }
        ptr[sz] = element;
        sz++;
    }
    void print()
    {
        for (int i = 0; i < sz; i++)
        {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }
};
