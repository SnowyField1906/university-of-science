#include <iostream>
#include "Vector.cpp"

using namespace std;

int main()
{
    vector<int> v(5);
    v.push(1);
    v.push(2);
    v.push(3);
    v.push(4);
    v.push(5);
    v.print();

    v.push(6);
    v.print();

    v.reserve(20);
    v.print();

    v[2] = 10;
    v.print();

    return 0;
}