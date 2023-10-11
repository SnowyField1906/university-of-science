#include <iostream>
#include "vector.cpp"

int main()
{
    vector<int> intVector;

    intVector.push(123);
    intVector.push(456);

    intVector.print();

    vector<string> stringVector;

    stringVector.push("Nguyen");
    stringVector.push("Huu");
    stringVector.push("Thuan");

    stringVector.print();

    return 0;
}
