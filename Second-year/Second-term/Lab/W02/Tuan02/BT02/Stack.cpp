#include "Stack.h"

void Stack::push(const string &val)
{
    list.insert(0, val);
}

void Stack::pop()
{
    list.erase(0);
}

string Stack::top() const
{
    return list.get(0);
}

int Stack::size() const
{
    return list.size();
}
