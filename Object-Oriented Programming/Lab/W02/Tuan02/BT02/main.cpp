#include <iostream>
#include "List.cpp"
#include "Stack.cpp"
using namespace std;

int main()
{
    Stack stack;

    stack.push("Nguyen");
    cout << "Pushed: Nguyen" << endl;
    stack.push("Huu");
    cout << "Pushed: Huu" << endl;
    stack.push("Thuan");
    cout << "Pushed: Thuan" << endl
         << endl;

    cout << "Stack size: " << stack.size() << endl;
    cout << "Top: " << stack.top() << endl
         << endl;

    stack.pop();
    cout << "Popped" << endl;
    stack.pop();
    cout << "Popped" << endl
         << endl;

    cout << "Stack size: " << stack.size() << endl;
    cout << "Top: " << stack.top() << endl;
    return 0;
}
